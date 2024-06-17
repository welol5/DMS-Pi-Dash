#include <iostream>
#include <ctime>
#include <thread>
#include <stdlib.h>
#include <gtkmm/window.h>
#include <gtkmm/paned.h>
#include <gtkmm/levelbar.h>
#include <gtkmm/label.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <glibmm/main.h>
#include <glibmm/dispatcher.h>
#include <gtkmm/stylecontext.h>
#include <gtkmm/cssprovider.h>
#include "gui/GaugeCluster.h"
#include "gui/Clock.h"

class PiDashWindow : public Gtk::Window {
    public:
        PiDashWindow();

    protected:
        time_t start_time;

        Gtk::Paned rpm_other_pane;
        Gtk::LevelBar rpm_bar;

        Gtk::Paned clock_other_pane;
        Clock clock;

        GaugeCluster gauges;

        Gtk::Label test_label;
        Gtk::Box test_box;
        Gtk::Button test_button;

        void increase_rpms();
        int clock_update();

    private:
        std::thread can_thread;
        Glib::Dispatcher dispatcher;

        int next_rpm;
        int next_voltage;
        int next_oil_pressure;
        int next_coolent_temp;
        int next_afr;

        void can_worker(int socket);
        void update_gauges();
        void setup_css();
};

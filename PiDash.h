#include <iostream>
#include <ctime>
#include <gtkmm/window.h>
#include <gtkmm/paned.h>
#include <gtkmm/levelbar.h>
#include <gtkmm/label.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <glibmm/main.h>
#include <gtkmm/stylecontext.h>
#include <gtkmm/cssprovider.h>
#include "GaugeCluster.h"

class PiDashWindow : public Gtk::Window {
    public:
        PiDashWindow();

    protected:
        time_t start_time;

        Gtk::Paned rpm_other_pane;
        Gtk::LevelBar rpm_bar;

        Gtk::Paned clock_other_pane;
        Gtk::Label clock_label;

        GaugeCluster gauges;

        Gtk::Label test_label;
        Gtk::Box test_box;
        Gtk::Button test_button;

        void increase_rpms();
        void can_thread();
        int clock_update();

    private:
        void setup_css();
};
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
#include "can/CanDecoder.h"

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
        //int next_oil_pressure;
        int next_coolent_temp;
        int next_afr;
        int next_tps;
        int next_map;
        int next_adv_deg;
        int next_mat;
        int next_pw2;
        int next_pw1;
        int next_pwseq1;
        int next_egt1;
        int next_egocor1;
        int next_afrtgt1;
        int next_knk_rtd;
        int next_sensors2;
        int next_sensors1;
        int next_batt;
        int next_launch_timing;
        int next_tc_retard;
        int next_VSS1;


        void can_worker(int socket);
        void update_gauges();
        void setup_css();
};

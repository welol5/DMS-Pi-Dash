#include <iostream>
#include <ctime>
#include <thread>
#include <stdlib.h>
#include <map>
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
#include "gui/RPMGauge.h"
#include "can/CanDecoder.h"
#include "logging/Logger.h"

class PiDashWindow : public Gtk::Window {
    public:
        PiDashWindow();

    protected:
        time_t start_time;

        Gtk::Paned rpm_other_pane;
        Gtk::LevelBar rpm_bar;
        RPMGauge rpm_gauge;


        Gtk::Paned clock_other_pane;
        Clock clock;

        GaugeCluster gauges;

        void increase_rpms();
        int clock_update();

    private:
        std::thread can_thread;
        Glib::Dispatcher dispatcher;
        Logger* logger = Logger::getLogger();

        int next_rpm;
        float next_voltage;
        //int next_oil_pressure;
        float next_coolent_temp;
        float next_afr;
        float next_tps;
        float next_map;
        float next_adv_deg;
        float next_mat;
        float next_pw2;
        float next_pw1;
        float next_pwseq1;
        float next_egt1;
        float next_egocor1;
        float next_afrtgt1;
        float next_knk_rtd;
        float next_sensors2;
        float next_sensors1;
        float next_launch_timing;
        float next_tc_retard;
        float next_VSS1;

        std::map<std::string, float> next_values{{"tps",0},{"clt",0},{"rpm",0},{"map",0},
                                                    {"adv_deg",0},{"mat",0},{"pw2",0},{"pw1",0},
                                                    {"pwseq1",0},{"egt1",0},{"egocor1",0},{"AFR1",0},{"afrtgt1",0},
                                                    {"knk_rtd",0},{"sensors2",0},{"sensors1",0},{"batt",0},
                                                    {"launch_timing",0},{"tc_retard",0},{"VSS1",0},};

        bool debugging = true;
        int rpm_testing = 0;


        void can_worker(int socket);
        void update_gauges();
        void setup_css();
        void map_gauge_values(int canId, __u8 *data);
        void update_current_map(std::map<std::string,float>* updatedData);
        void testing_map_gauge_values();
        void testing_map_gauge_values(std::map<std::string,float> *data);
};

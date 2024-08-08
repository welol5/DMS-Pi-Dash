#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <gtkmm/paned.h>
#include <gtkmm/label.h>
#include <gtkmm/grid.h>
#include <gtkmm/button.h>
#include <glibmm/main.h>
#include <gtkmm/stylecontext.h>
#include <gtkmm/cssprovider.h>
#include "Gauge.h"

/**
 * Requirements:
 * Voltage
 * Oil Pressure
 * Coolent temp
 * AFR
*/

class GaugeCluster : public Gtk::Grid {
    public:
        GaugeCluster();
        void update_gauge(std::string name, int value);
        void update_gauge(std::string name, float value);

    protected:
        std::vector<std::string> gauge_names = {"Voltage", "MAP", "Coolent temp", "AFR"};

    private:
        std::map<std::string, int> gauges;
};
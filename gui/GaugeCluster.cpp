#include "GaugeCluster.h"

GaugeCluster::GaugeCluster(){
    for(int i = 0; i < gauge_names.size(); i++){
        Gauge *g = new Gauge(gauge_names[i]);
        g->set_expand(true);
        attach(*g,i,0);
        set_expand(true);

        std::string s = gauge_names[i];
        gauges[s] = i;
    }
}

void GaugeCluster::update_gauge(std::string name, int value){
    int location = gauges[name];

    Gtk::Widget *w = get_child_at(location,0);
    Gauge *g = dynamic_cast<Gauge*>(w);

    g->update_value(value);
}

void GaugeCluster::update_gauge(std::string name, float value){
    int location = gauges[name];

    Gtk::Widget *w = get_child_at(location,0);
    Gauge *g = dynamic_cast<Gauge*>(w);

    g->update_value(value);
}
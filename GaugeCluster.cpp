#include "GaugeCluster.h"
#include <iostream>

GaugeCluster::GaugeCluster(){

    std::cout << "gauge count: " << gauge_names.size() << std::endl;
    for(int i = 0; i < gauge_names.size(); i++){
        std::cout << "Creating gauge for " << gauge_names[i] << std::endl;
        Gauge *g = new Gauge(gauge_names[i]);
        g->set_expand(true);
        attach(*g,i,0);
        set_expand(true);
    }
}
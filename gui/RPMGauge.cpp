#include <iostream>
#include <ctime>
#include <string>
#include <gtkmm/paned.h>
#include <gtkmm/label.h>
#include <glibmm/main.h>
#include <gtkmm/stylecontext.h>
#include <gtkmm/cssprovider.h>
#include "RPMGauge.h"

RPMGauge :: RPMGauge(){
    level.set_label("Placeholder");
    ticks = max/1000;

    graphic.set_draw_func( sigc::mem_fun(*this, &RPMGauge::updateGrpahic));

    set_orientation(Gtk::Orientation::VERTICAL);
    set_start_child(graphic);
    // set_end_child(level);

}

void RPMGauge::update_value(int value){
    rpm_value = value;
    level.set_label(std::to_string(value));
    graphic.queue_draw();
}

void RPMGauge::updateGrpahic(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height){

    //reset background
    cr->set_source_rgb(0,0,0);
    cr->rectangle(0,0,width,height);
    cr->fill();

    //add rpm bar
    int rpm_bar_length = mapRPMToBar(rpm_value, width);
    if(rpm_value > 6700) {
        cr->set_source_rgb(1,0,0);
    } else if(rpm_value > 6500){
        cr->set_source_rgb(0,0,1);
    } else {
        cr->set_source_rgb(0.6784,0.2588,0.9607);
    }
    cr->rectangle(0,0,rpm_bar_length, height);
    cr->fill();

    //add ticks at every 1000 rpm
    int tickWidth = (width/100)/2;
    int tickOffset = width/ticks;
    cr->set_source_rgba(1,1,1,1);
    for(int i = 0; i < ticks; i++){
        cr->rectangle(mapRPMToBar((i+1)*1000, width)-(tickWidth/2), 0, tickWidth, height);
        cr->fill();
    }
}

int RPMGauge::mapRPMToBar(int rpm, int width){
    //linear
    return (int)((((float)rpm)/max)*width);
}
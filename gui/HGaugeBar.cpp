#include "HGaugeBar.h"

HGaugeBar::HGaugeBar(const Glib::ustring &name, float min, float max){
    label.set_label(name);
    graphic.set_draw_func( sigc::mem_fun(*this, &RPMGauge::updateGrpahic));
    set_orientation(Gtk::Orientation::HORIZONTAL);
    set_start_child(label);
    set_end_child(graphic);
}

void HGaugeBar::update_value(int value){
    this.value = value;
    graphic.queue_draw();
}

void HGaugeBar::updateGrpahic(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height){

    //reset background
    cr->set_source_rgb(0,0,0);
    cr->rectangle(0,0,width,height);
    cr->fill();

    //if the value is outside of the limits show an error bar
    if(value > max || value < min){
        cr->set_source_rgb(1,0,0);
        cr->rectangle(0,0,width,height);
        cr->fill();
        return;
    }

    //add bar
    int bar_length = mapToBar(value, width);
    cr->set_source_rgb(0.7,0,0.7);
    cr->rectangle(0,0,rpm_bar_length, height);
    cr->fill();
}

int RPMGauge::mapToBar(int value, int width){
    //linear
    return (int)((((float)value-min)/max)*width);
}
#include "Gauge.h"

Gauge :: Gauge(const Glib::ustring &name){
    label.set_label(name);
    level.set_label("Placeholder");

    set_orientation(Gtk::Orientation::VERTICAL);
    set_start_child(level);
    set_end_child(label);
}

void Gauge::update_value(int value){
    level.set_label(std::to_string(value));
}
#include <iostream>
#include <ctime>
#include <string>
#include <gtkmm/paned.h>
#include <gtkmm/label.h>
#include <glibmm/main.h>
#include <gtkmm/stylecontext.h>
#include <gtkmm/cssprovider.h>

class Gauge : public Gtk::Paned {
    public:
        Gauge(const Glib::ustring &name);
        void update_value(int value);

    protected:
        Gtk::Label level;
        Gtk::Label label;

        int min;
        int max;
};
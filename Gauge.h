#include <iostream>
#include <ctime>
#include <gtkmm/paned.h>
#include <gtkmm/label.h>
#include <gtkmm/button.h>
#include <glibmm/main.h>
#include <gtkmm/stylecontext.h>
#include <gtkmm/cssprovider.h>

class Gauge : public Gtk::Paned {
    public:
        Gauge(const Glib::ustring &name);

    protected:
        Gtk::Label level;
        Gtk::Label label;

        int min;
        int max;
};
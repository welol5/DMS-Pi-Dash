#include <gtkmm/drawingarea.h>

class HGaugeBar : public Gtk::Paned {
    public:
        HGaugeBar(const Glib::ustring &name, float min, float max);
        void update_value(float value);

    protected:
        Gtk::DrawingArea graphic;
        Gtk::Label label;

        float value;
        float min;
        float max;

        void updateGrpahic(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
        int mapToBar(float value, int width);
};
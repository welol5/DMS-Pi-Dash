#include <gtkmm/drawingarea.h>

class RPMGauge : public Gtk::Paned {
    public:
        RPMGauge();
        void update_value(int value);

    protected:
        Gtk::DrawingArea graphic;
        Gtk::Label level;

        int rpm_value;
        int min;
        int max = 6900;
        int ticks;

        void updateGrpahic(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
        int mapRPMToBar(int rpm, int width);
};
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
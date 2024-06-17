class Clock : public Gtk::Label {
    public:
        Clock();

    private:
        int clock_update();

        long start_time;
};
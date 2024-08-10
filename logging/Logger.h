#include <string>
#include <mutex>
#include <deque>
#include <thread>

class Logger {


    public:
        Logger();
        static Logger* getLogger();
        void log(uint8_t level, std::string message);
        static uint8_t log_level;

    private:
        static Logger* logger;
        bool isEnabled;

        std::mutex mutex;
        std::deque<std::string> write_buffer;
        std::deque<std::string> log_buffer;
        std::thread write_thread;

        void write();
};
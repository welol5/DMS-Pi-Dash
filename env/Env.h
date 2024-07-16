#include <string>

class Env{
    public:
        static std::string root_path;
        static std::string config_path;
        static std::string styles_path;

        static void init(std::string configPath);
};
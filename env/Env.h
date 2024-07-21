#include <string>
#include <map>

class Env{
    public:
        static std::string root_path;
        static std::string config_path;
        static std::string styles_path;

        static std::map<std::string,std::string> enviornmentVaribles;

        static void init(std::string configPath);
};
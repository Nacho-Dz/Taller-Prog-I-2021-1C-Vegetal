#include <string>

namespace logger {
    class Logger {
        private:
            Logger();
            ~Logger()= default;
            Logger(const Logger&)= delete;
            Logger& operator=(const Logger&)= delete;
            std::string filepath;
            std::string debug_level;
            void log(const std::string&, const std::string&);
        public:
            static Logger& getInstance();
            void setDebugLevel(const std::string&);
            void logNewGame(void);
            void logError(const std::string&);
            void logInformation(const std::string&);
            void logDebug(const std::string&);
    };
}
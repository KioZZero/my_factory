#ifndef LOGMANAGER_HPP
    #define LOGMANAGER_HPP

#include <ctime>
#include <exception>
#include <fstream>
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

#define MSG(msg) std::cout << msg << std::endl
#define ERR(msg) std::cerr << msg << std::endl

namespace Log
{
    class LogManager
    {
        private:
            std::ofstream _logs;
            bool _first_log = true;

            LogManager();
            ~LogManager();

            void writeLog(const std::string& message);
            std::string getTimeString();
        
        public:
            static LogManager& instance();

            LogManager(const LogManager&) = delete;
            LogManager& operator=(const LogManager&) = delete;
            LogManager(LogManager&&) = delete;
            LogManager& operator=(LogManager&&) = delete;

            void log(const std::string& message);
            void log(std::string from, const std::string& message);

            void log(const std::string& message, const std::exception& e);
            void log(std::string from, const std::string& message, const std::exception& e);
            void log(std::string from, const std::string& message, const std::string& e);
    };
}

#endif // LOGMANAGER_HPP
#include "LogManager.hpp"

namespace Log
{
    void LogManager::writeLog(const std::string& message)
    {
        _logs << message << std::endl;
    }

    std::string LogManager::getTimeString(void)
    {
        auto time = std::time(nullptr);
        auto local_time = *std::localtime(&time);

        std::ostringstream out;
        out << std::put_time(&local_time, "%d/%m/%Y - %H:%M:%S");

        return out.str();
    }

    LogManager::LogManager()
    {
        _logs = std::ofstream();

        auto time = std::time(nullptr);
        auto local_time = *std::localtime(&time);

        std::ostringstream out;
        out << std::put_time(&local_time, "%d_%m_%Y-%H_%M_%S");

        std::string log_file_name = "general_logs-" + out.str() + ".log";
        _logs.open(log_file_name);
    }

    LogManager::~LogManager()
    {
        _logs.close();
    }

    void LogManager::log(const std::string& message)
    {
        std::ostringstream out;
        out << getTimeString() << " | " << "?USER?" << " | " << message;
        writeLog(out.str());
    }

    void LogManager::log(const std::string& message, const std::exception &e)
    {
        std::ostringstream out;
        out << getTimeString() << " | " << "?USER?" << " | " << message << " | Exception: " << e.what();
        writeLog(out.str());
    }

    void LogManager::log(std::string user, const std::string& message)
    {
        std::ostringstream out;
        out << getTimeString() << " | " << user << " | " << message;
        writeLog(out.str());
    }

    void LogManager::log(std::string user,const std::string& message, const std::exception &e)
    {
        std::ostringstream out;
        out << getTimeString() << " | " << user << " | " << message << " | Exception: " << e.what();
        writeLog(out.str());
    }
}
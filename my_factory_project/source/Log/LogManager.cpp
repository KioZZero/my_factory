#include "LogManager.hpp"

#define LOG_FOLDER_PATH "logs/"

namespace Log
{
    LogManager& LogManager::instance()
    {
        static LogManager logger;
        return logger;
    }

    void LogManager::writeLog(const std::string& message)
    {
        if (_logs.is_open())
        {
            _logs << message;
        }
    }

    std::string LogManager::getTimeString()
    {
        const auto time = std::time(nullptr);
        const auto local_time = *std::localtime(&time);

        std::ostringstream out;
        out << std::put_time(&local_time, "%d/%m/%Y - %H:%M:%S");

        return out.str();
    }

    LogManager::LogManager()
    {
        std::filesystem::create_directories(LOG_FOLDER_PATH);

        auto time = std::time(nullptr);
        auto local_time = *std::localtime(&time);

        std::ostringstream out;
        out << std::put_time(&local_time, "%d_%m_%Y-%H_%M_%S");

        const std::string log_file_name = "logs-" + out.str() + ".log.json";
        _logs.open(LOG_FOLDER_PATH + log_file_name);
        _logs << "[" << std::endl;
    }

    LogManager::~LogManager()
    {
        if (_logs.is_open())
        {
            _logs << std::endl << "]" << std::endl;
            _logs.close();
        }
    }

    void LogManager::log(const std::string& message)
    {
        std::ostringstream out;
        std::string timestamp = getTimeString();
        
        if (!_first_log) { out << "," << std::endl; }

        out << "\t{\"timestamp\" : \"" << timestamp << "\", \"type\" : \"INFO\", \"from\" : \"???\", \"message\" : \"" << message << "\"}";
        writeLog(out.str());

        _first_log = false;
    }

    void LogManager::log(const std::string& message, const std::exception& e)
    {
        std::ostringstream out;

        if (!_first_log) { out << "," << std::endl; }
        
        std::string timestamp = getTimeString();
        out << "\t{\"timestamp\" : \"" << timestamp << "\", \"type\" : \"ERROR\", \"from\" : \"???\", \"message\" : \"" << message << "\", \"exception\" : \"" << e.what() << "\"}";
        writeLog(out.str());

        _first_log = false;
    }

    void LogManager::log(std::string from, const std::string& message)
    {
        std::ostringstream out;
        
        if (!_first_log) { out << "," << std::endl; }
        
        std::string timestamp = getTimeString();
        out << "\t{\"timestamp\" : \"" << timestamp << "\", \"type\" : \"INFO\", \"from\" : \"" << from << "\", \"message\" : \"" << message << "\"}";
        writeLog(out.str());

        _first_log = false;
    }

    void LogManager::log(std::string from, const std::string& message, const std::exception& e)
    {
        std::ostringstream out;

        if (!_first_log) { out << "," << std::endl; }
        
        std::string timestamp = getTimeString();
        out << "\t{\"timestamp\" : \"" << timestamp << "\", \"type\" : \"ERROR\", \"from\" : \"" << from << "\", \"message\" : \"" << message << "\", \"exception\" : \"" << e.what() << "\"}";
        writeLog(out.str());

        _first_log = false;
    }

    void LogManager::log(std::string from, const std::string& message, const std::string& e)
    {
        std::ostringstream out;

        if (!_first_log) { out << "," << std::endl; }
        
        std::string timestamp = getTimeString();
        out << "\t{\"timestamp\" : \"" << timestamp << "\", \"type\" : \"ERROR\", \"from\" : \"" << from << "\", \"message\" : \"" << message << "\", \"exception\" : \"" << e << "\"}";
        writeLog(out.str());

        _first_log = false;
    }

}
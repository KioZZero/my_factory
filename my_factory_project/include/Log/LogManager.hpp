#ifndef LOGMANAGER_HPP
    #define LOGMANAGER_HPP

#include <fstream>
#include <iostream>
#include <ostream>
#include <iomanip>
#include <ctime>
#include <sstream>

#define FORMAT "dd/mm/yyyy - hh:mm:ss | user | informations"

/// @brief Namespace Log contains every things related to the log part of the software it is made to be completly independant of the software and easily configurable
namespace Log
{
    /// @brief Class LogManager is responsible for managing the logs of the software. it writes the log messages to the output stream
    class LogManager
    {
        private:
            std::ofstream _logs;

            /// @brief Writes a log message to the output stream
            /// @param message The message to log
            void writeLog(const std::string& message);

            /// @brief Gets the current time as a formatted string
            /// @return The formatted time string
            std::string getTimeString(void);
        public:
            /// @brief The constructor LogManager generate the files with the following format general_logs-dd_mm_yyy-hh_mm_ss.log
            LogManager();

            /// @brief Close the log file
            ~LogManager();

            /// @brief Logs a message
            /// @param message The message to log
            void log(const std::string& message);
            
            /// @brief Logs a message with an exception
            /// @param message The message to log
            /// @param e The exception to log
            void log(const std::string& message, const std::exception &e);

            /// @brief Logs a message with a specific user
            /// @param user The user to log the message for
            /// @param message The message to log
            void log(std::string user, const std::string& message);
            
            /// @brief Logs a message with a specific user and an exception
            /// @param user The user to log the message for
            /// @param message The message to log
            /// @param e The exception to log
            void log(std::string user,const std::string& message, const std::exception &e);
    };
}
#endif // LOGMANAGER_HPP
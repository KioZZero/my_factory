/*
** 2026
** my_factory
** File description:
** Server.hpp
*/

#ifndef SERVER_HPP
    #define SERVER_HPP

namespace Factory::Server
{
    class Server
    {
        private:
        
        public:
            Server() = default;
            ~Server() = default;
            
            int run();
            void getEvents();
    };
}

#endif // SERVER_HPP
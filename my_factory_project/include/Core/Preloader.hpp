#ifndef PRELOADER_HPP
    #define PRELOADER_HPP

#include "Utils.hpp"

namespace Factory::Preloader
{
    class PreloaderManager
    {
        public:
            PreloaderManager() = default;
            ~PreloaderManager() = default;

            int init(void);
    };
}
#endif // PRELOADER_HPP
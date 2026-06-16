/*
** 2026
** my_factory
** File description:
** Core.hpp
*/

#ifndef CORE_HPP
    #define CORE_HPP

#include "Utils.hpp"

namespace Factory::Core
{
    #include "CCharacter.hpp"

    class Core
    {
        private:
            std::unique_ptr<Factory::Core::MyFactory::Character::CCharacter> _characterComposite;
            //std::vector<IComponent*> _graphicalComponents;
        public:
            Core() = default;
            ~Core() = default;
            
            void init(void);
            int run(void);
    };
}

#endif // CORE_HPP
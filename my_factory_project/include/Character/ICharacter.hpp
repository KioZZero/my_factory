/*
** 2026
** my_factory
** File description:
** ICharacter.hpp
*/

#ifndef ICHARACTER_HPP
    #define ICHARACTER_HPP

#include "Utils.hpp"

namespace MyFactory::Character
{
    class ICharacter
    {
        public:
            virtual ~ICharacter() = default; 
    };
}

#endif // ICHARACTER_HPP
/*
** 2026
** my_factory
** File description:
** ACharacter.hpp
*/

#ifndef ACHARACTER_HPP
    #define ACHARACTER_HPP

#include "ICharacter.hpp"

namespace MyFactory::Character
{
    class ACharacter : public ICharacter
    {
        protected:
            int _id = DEFAULT;
            Axis_t position;
            std::string _name;
    };
}

#endif // ACHARACTER_HPP
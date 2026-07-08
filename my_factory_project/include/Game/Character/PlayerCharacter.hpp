#ifndef PLAYERCHARACTER_HPP
    #define PLAYERCHARACTER_HPP

#include "ACharacter.hpp"

namespace MyFactory::Character
{
    class PlayerCharacter : public ACharacter
    {
        public:
            PlayerCharacter();
            PlayerCharacter(std::string name, Axis_t position);
            ~PlayerCharacter() = default;
    };
}

#endif // PLAYERCHARACTER_HPP
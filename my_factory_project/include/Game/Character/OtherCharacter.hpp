#ifndef OTHERCHARACTER_HPP
    #define OTHERCHARACTER_HPP

#include "ACharacter.hpp"

namespace MyFactory::Character
{
    class OtherCharacter : public ACharacter
    {
        private:
            OtherCharacter();
            OtherCharacter(std::string name, Axis_t position);
            ~OtherCharacter();
    };
}

#endif // OTHERCHARACTER_HPP
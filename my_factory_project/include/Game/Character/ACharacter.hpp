#ifndef ACHARACTER_HPP
    #define ACHARACTER_HPP

#include "ICharacter.hpp"

namespace MyFactory::Character
{
    class ACharacter : public ICharacter
    {
        protected:
            int _id = DEFAULT;
            std::string _name;

            Axis_t _position;
        public:
            ACharacter();
            ACharacter(std::string name);
            ACharacter(std::string name, Axis_t position);
            ~ACharacter() = default;

    };
}

#endif // ACHARACTER_HPP
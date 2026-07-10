#include "ACharacter.hpp"

namespace MyFactory::Character
{
    ACharacter::ACharacter() : _id(UNKNOWN), _name("Unknown"), _position({0.f, 0.f, 0.f}) {}

    ACharacter::ACharacter(std::string name, Axis_t position) : _id(UNKNOWN), _name(name), _position(position) {}

    ACharacter::ACharacter(std::string name) : _id(UNKNOWN), _name(name), _position({0.f, 0.f, 0.f}) {}
}
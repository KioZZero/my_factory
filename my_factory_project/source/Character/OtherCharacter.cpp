#include "OtherCharacter.hpp"

namespace MyFactory::Character
{
    OtherCharacter::OtherCharacter() : ACharacter() {}

    OtherCharacter::OtherCharacter(std::string name, Axis_t position) : ACharacter(name, position) {}
    
    OtherCharacter::~OtherCharacter() = default;
}
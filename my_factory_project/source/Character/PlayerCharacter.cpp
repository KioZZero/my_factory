#include "PlayerCharacter.hpp"

namespace MyFactory::Character
{
    PlayerCharacter::PlayerCharacter() : ACharacter() {}

    PlayerCharacter::PlayerCharacter(std::string name, Axis_t position) : ACharacter(name, position) {}
    
    PlayerCharacter::~PlayerCharacter() = default;
}
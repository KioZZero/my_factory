#include "ACharacter.hpp"

namespace MyFactory::Character
{
    ACharacter::ACharacter() : m_id(UNKNOWN), m_name("Unknown"), m_position({0.0f, 0.0f, 0.0f}) {}

    ACharacter::ACharacter(std::string name, Axis_t position) : m_id(UNKNOWN), m_name(name), m_position(position) {}

    ACharacter::~ACharacter() = default;
}
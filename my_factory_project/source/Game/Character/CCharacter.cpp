#include "CCharacter.hpp"

namespace MyFactory::Character
{
    std::unique_ptr<ICharacter> CCharacter::getCharacter(size_t index) const
    {
        MSG(index);
        return nullptr;
    }

    std::vector<std::unique_ptr<ICharacter>> CCharacter::getEveryone(void)
    {
        return {};
    }

    void CCharacter::addCharacter(std::unique_ptr<ICharacter> character)
    {
    }

    void CCharacter::removeCharacter(std::unique_ptr<ICharacter> character)
    {
    }

    void CCharacter::removeCharacter(size_t index)
    {
    }

    void CCharacter::displayAllCharacterInfo(void)
    {

    }

    void CCharacter::displayCharacterInfo(std::unique_ptr<ICharacter> character)
    {
    }

    void CCharacter::displayCharacterInfo(size_t index)
    {
    }

    bool CCharacter::IdIsAvailable(int id)
    {
        return true;
    }

    int CCharacter::getNewAvailableId(void)
    {
        return 0;
    }
}
#include "CCharacter.hpp"

namespace MyFactory::Character
{
    CCharacter() = default;
    ~CCharacter() = default;

    std::unique_ptr<ICharacter> getCharacter(size_t index) const;
    std::vector<std::unique_ptr<Character>> getEveryone(void);

    void addCharacter(std::unique_ptr<ICharacter> character);
    
    void removeCharacter(std::unique_ptr<ICharacter> character);
    void removeCharacter(size_t index);

    void displayAllCharacterInfo(void);
    void displayCharacterInfo(std::unique_ptr<ICharacter> character);
    void displayCharacterInfo(size_t index);

    bool IdIsAvailable(int id);
    int getNewAvailableId(void);
}
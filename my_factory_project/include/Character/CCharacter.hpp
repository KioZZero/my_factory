/*
** 2026
** my_factory
** File description:
** CCharacter.hpp
*/

#ifndef CCHARACTER_HPP
    #define CCHARACTER_HPP

#include "ICharacter.hpp"

namespace MyFactory::Character
{
    class CCharacter
    {
        private:
            std::vector< std::unique_ptr<ICharacter>> _characters;

        public:
            CCharacter() = default;
            ~CCharacter() = default;

            std::unique_ptr<ICharacter> getCharacter(size_t index) const;
            std::vector<std::unique_ptr<ICharacter>> getEveryone(void);

            void addCharacter(std::unique_ptr<ICharacter> character);
            
            void removeCharacter(std::unique_ptr<ICharacter> character);
            void removeCharacter(size_t index);

            void displayAllCharacterInfo(void);
            void displayCharacterInfo(std::unique_ptr<ICharacter> character);
            void displayCharacterInfo(size_t index);

            bool IdIsAvailable(int id);
            int getNewAvailableId(void);
    };
}

#endif // CCHARACTER_HPP

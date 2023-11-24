# ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp" 

class ICharacter;

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria * _slots[4]; // this is an array of pointers to AMateria objects

    public:
        Character();
        Character(std::string const & name);
        Character(const Character &copy);
        Character &operator=(const Character &copy);

        virtual ~Character();

        std::string const & getName() const;
        void setName(std::string const & name);

        void equip(AMateria* m);
        void unequip(int index);
        void use(int index, ICharacter& target);
};


# endif // CHARACTER_HPP
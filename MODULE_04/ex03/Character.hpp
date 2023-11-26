# ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp" 

class ICharacter;

typedef struct s_materia
{
    AMateria *materia;
    int index;
    struct s_materia *next;
} t_materia;

void add_materia(t_materia **materia, AMateria *new_materia, int index);
void free_materia_list(t_materia **materia);

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria * _slots[4]; // this is an array of pointers to AMateria objects
        t_materia *unequiped_materias;
    
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
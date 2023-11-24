# ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string	_type;

    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria &copy);
        AMateria &operator=(const AMateria &copy);

        virtual ~AMateria();

        std::string const & getType() const;
        void setType(std::string const & type);

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};


# endif // AMATERIA_HPP
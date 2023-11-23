# ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
    private:
        std::string ideas[100];

    public:
        Brain();
        ~Brain();
        Brain(const Brain &other);
        Brain &operator=(const Brain &other);

        std::string identify() const;
};

# endif // "BRAIN_HPP"
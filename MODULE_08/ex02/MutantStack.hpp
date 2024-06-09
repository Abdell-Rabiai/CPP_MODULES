# pragma once
# include <iostream>
# include <stack>
# include <list>
# include <algorithm>
# include <deque>

template <class T, class CT = std::deque<T> >
class MutantStack : public std::stack<T, CT> {
    private :
        // none 
    public :
        MutantStack() : std::stack<T, CT>() {}
        MutantStack(MutantStack const & src) : std::stack<T, CT>(src) {}
        virtual ~MutantStack() {}
        MutantStack & operator=(MutantStack const & rhs) {
            if (this != &rhs)
                std::stack<T, CT>::operator=(rhs);
            return *this;
        }
        typedef typename CT::iterator it;
        typedef typename CT::const_iterator const_it;

        it begin() { return std::stack<T, CT>::c.begin(); }
        it end() { return std::stack<T, CT>::c.end(); }
        const_it begin() const { return std::stack<T, CT>::c.begin(); }
        const_it end() const { return std::stack<T, CT>::c.end(); }
        
        void print() {
            for (it it = begin(); it != end(); ++it)
                std::cout << *it << "|";
            std::cout << std::endl;
        }

        void print(it begin, it end) {
            for (it it = begin; it != end; ++it)
                std::cout << *it << "|";
            std::cout << std::endl;
        }
};

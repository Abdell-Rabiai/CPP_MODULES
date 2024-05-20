#include "Span.hpp"

/*
Develop a Span class that can store a maximum of N integers. N is an unsigned int
variable and will be the only parameter passed to the constructor.
This class will have a member function called addNumber() to add a single number
to the Span. It will be used in order to fill it. Any attempt to add a new element if there
are already N elements stored should throw an exception.
Next, implement two member functions: shortestSpan() and longestSpan()
They will respectively find out the shortest span or the longest span (or distance, if
you prefer) between all the numbers stored, and return it. If there are no numbers stored,
or only one, no span can be found. Thus, throw an exception.
Of course, you will write your own tests and they will be way more thorough than the
ones below. Test your Span at least with a minimum of 10 000 numbers. More would be
even better.
*/

Span::Span(size_t n) {
    this->N = n;
}

Span::Span(Span const & rhs) {
    *this = rhs;
}

Span & Span::operator=(Span const & src) {
    if (this != &src) {
        this->N = src.N;
        this->vec = src.vec;
    }
    return *this;
}

Span::~Span() {
}

void Span::addNumber(int valueToAdd) {
    if (this->vec.size() >= this->N)
        throw std::runtime_error("Span has reached its maximum capacity.");
    this->vec.push_back(valueToAdd);
}

size_t Span::shortestSpan() {
    if (this->vec.size() <= 1)
        throw std::runtime_error("the Span is empty or has only one element.");
    std::vector<int> vecCopy = this->vec;
    std::sort(vecCopy.begin(), vecCopy.end());
    int shortestSpan = vecCopy[vecCopy.size() - 1] - vecCopy[0];
    for (size_t i = 0; i < vecCopy.size() - 1; i++) {
        if (vecCopy[i + 1] - vecCopy[i] < shortestSpan)
            shortestSpan = vecCopy[i + 1] - vecCopy[i];
    }
    return shortestSpan;
}

size_t Span::longestSpan() {
    if (this->vec.size() <= 1)
        throw std::runtime_error("the Span is empty or has only one element.");
    std::vector<int> vecCopy = this->vec;
    std::sort(vecCopy.begin(), vecCopy.end());
    return vecCopy[vecCopy.size() - 1] - vecCopy[0];
}

template <typename InputIterator>
void Span::addRangeNumberS(InputIterator begin, InputIterator end) {
    if (this->vec.size() + std::distance(begin, end) > this->N)
        throw std::runtime_error("Span has reached its maximum capacity.");
    this->vec.insert(this->vec.end(), begin, end);
}

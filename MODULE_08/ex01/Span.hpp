# pragma once

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <exception>

class Span
{
	private :
		size_t N;
		std::vector<int> vec;
	
	public :
		Span(size_t N);
		Span(Span const & rhs);
		Span & operator=(Span const & src);
		~Span();

		void addNumber(int n);
		template <typename IteratorType>
		void addRange(IteratorType begin, IteratorType end) {
			if (this->vec.size() + std::distance(begin, end) > this->N)
				throw std::runtime_error("Span has reached its maximum capacity.");
			this->vec.insert(this->vec.end(), begin, end);
		}
		size_t shortestSpan();
		size_t longestSpan();
};
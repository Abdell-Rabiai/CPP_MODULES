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
		template <typename InputIterator> void addRangeNumberS(InputIterator begin, InputIterator end);
		size_t shortestSpan();
		size_t longestSpan();
};
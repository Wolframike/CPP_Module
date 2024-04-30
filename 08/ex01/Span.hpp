/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:07:50 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/30 22:28:18 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <set>

class Span {
	private:
		unsigned int n_;
		std::multiset<int> set_;
	
	public:
		Span();
		Span(unsigned int n);
		Span(Span const &src);
		Span &operator=(Span const &rhs);
		~Span();
		
		void addNumber(int number);
		template <typename T>
		void addNumber(T begin, T end) {
			if (set_.size() + std::distance(begin, end) > n_)
				throw std::length_error("Span: Span is full");
			set_.insert(begin, end);
		}
		unsigned int shortestSpan();
		unsigned int longestSpan();
};

#endif

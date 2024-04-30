/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:21:53 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/30 22:28:05 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : n_(0) {}

Span::Span(unsigned int n) : n_(n) {}

Span::Span(Span const &src) : n_(src.n_), set_(src.set_) {}

Span &Span::operator=(Span const &rhs) {
	if (this != &rhs) {
		n_ = rhs.n_;
		set_ = rhs.set_;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (set_.size() >= n_)
		throw std::length_error("Span: Span is full");
	set_.insert(number);
}

unsigned int Span::shortestSpan() {
	if (set_.size() <= 1)
		throw std::length_error("Span: Span is too short to calculate span");
	std::multiset<int>::iterator it = set_.begin();
	std::multiset<int>::iterator it2 = ++set_.begin();
	unsigned int min = *it2 - *it;
	while (it2 != set_.end()) {
		if (static_cast<unsigned int>(*it2 - *it) < min)
			min = *it2 - *it;
		++it;
		++it2;
	}
	return min;
}

unsigned int Span::longestSpan() {
	if (set_.size() <= 1)
		throw std::length_error("Span: Span is too short to calculate span");
	std::multiset<int>::iterator it = set_.begin();
	std::multiset<int>::iterator it2 = --set_.end();
	return *it2 - *it;
}

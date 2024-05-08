/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:54:07 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/09 00:30:39 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) {
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {
	if (this != &copy) {
		this->vec_ = copy.vec_;
		this->deq_ = copy.deq_;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::fill(std::string &str) {
	std::stringstream ss(str);

	long long i;
	while (ss >> i) {
		if (i > INT_MAX)
			throw std::invalid_argument("Invalid argument");
		vec_.push_back(i);
		deq_.push_back(i);
	}
	if (!ss.eof())
		throw std::invalid_argument("Invalid argument");
	if (vec_.size() == 0 || deq_.size() == 0)
		throw std::invalid_argument("Empty argument");
}

size_t PmergeMe::jacobsthal(size_t n) {
	n -= 1;
	return (std::pow(2, n + 1) + std::pow(-1, n)) / 3;
}

void PmergeMe::sort(std::string &str) {
	fill(str);

	std::cout << "Before:  ";
	for (size_t i = 0; i < vec_.size(); i++)
		std::cout << vec_[i] << " ";
	std::cout << std::endl;
	
	std::stringstream &ssVec = sortContainer<std::vector<int>, std::vector<std::pair<int, int> > >(VECTOR);
	std::stringstream &ssDeq = sortContainer<std::deque<int>, std::deque<std::pair<int, int> > >(DEQUE);
	
	std::cout << "After:   ";
	for (size_t i = 0; i < vec_.size(); i++)
		std::cout << deq_[i] << " ";
	std::cout << std::endl;

	std::cout << ssVec.str() << std::endl;
	std::cout << ssDeq.str() << std::endl;
	
	delete &ssVec;
	delete &ssDeq;
}

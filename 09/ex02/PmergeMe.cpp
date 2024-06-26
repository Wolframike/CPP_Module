/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:54:07 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/15 06:19:00 by misargsy         ###   ########.fr       */
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
	if (vec_.size() == 0)
		throw std::invalid_argument("Empty argument");

	std::set<int> set(vec_.begin(), vec_.end());
	if (set.size() != vec_.size())
		throw std::invalid_argument("Duplicate argument");
}

size_t PmergeMe::jacobsthal(size_t n) {
	n -= 1;
	return (std::pow(2, n + 1) + std::pow(-1, n)) / 3;
}

void PmergeMe::sort(std::string &str) {
	std::stringstream ss;
	fill(str);

	ss << "Before:  ";
	for (size_t i = 0; i < vec_.size(); i++)
		ss << vec_[i] << " ";
	ss << std::endl;
	
	std::stringstream ssVec = sortContainer<std::vector<int> >(VECTOR);
	std::stringstream ssDeq = sortContainer<std::deque<int> >(DEQUE);
	
	ss << "After:   ";
	for (size_t i = 0; i < vec_.size(); i++)
		ss << deq_[i] << " ";
	ss << std::endl;

	ss << ssVec.str() << std::endl;
	ss << ssDeq.str() << std::endl;

	std::cout << ss.str();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:54:07 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/08 21:54:56 by misargsy         ###   ########.fr       */
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

std::stringstream &PmergeMe::sortVec() {
	std::stringstream *ss = new std::stringstream;
	std::clock_t start = std::clock();
	
	//Step 1: Pairwise comparison
	std::vector<std::pair<int, int> > m;
	for (size_t i = 0; i < vec_.size(); i += 2) {
		if (i + 1 < vec_.size())
			m.push_back(std::make_pair(vec_[i], vec_[i + 1]));
		else
			m.push_back(std::make_pair(vec_[i], -1));
	}
	for (size_t i = 0; i < m.size(); i++) {
		if (m[i].first < m[i].second)
			std::swap(m[i].first, m[i].second);
	}
	
	//Step 2: Recursion
	recursivePairSort(m, 0, m.size() - 1);
	
	//Step 3: Insertion
	std::vector<int> d;
	d.push_back(m[0].second);
	d.push_back(m[0].first);
	size_t insertedFromFirst = 1;
	size_t insertedFromSecond = 1;
	size_t inserting;
	for (size_t i = 1; insertedFromSecond < m.size(); i++) {
		inserting = jacobsthal(i) * 2;
		for (size_t j = 1; (insertedFromFirst < m.size()) && (j <= inserting); j++) {
			d.push_back(m[insertedFromFirst].first);
			insertedFromFirst++;
		}
		for (size_t j = 1; (insertedFromSecond < m.size()) && (j <= inserting); j++) {
			binaryInsertion(d, m[insertedFromSecond].second);
			insertedFromSecond++;
		}
	}
	
	//Step 4: Finishing up
	if (vec_.size() % 2 == 1)
		d.erase(d.begin());
	vec_ = d;
	
	std::clock_t end = std::clock();

	*ss	<< "Time to process a range of"
		<< std::setw(5) << vec_.size()
		<< " elements with std::vector : "
		<< std::setw(5) << static_cast<double>(end - start) << " us";

	return *ss;
}

std::stringstream &PmergeMe::sortDeq() {
	std::stringstream *ss = new std::stringstream;
	std::clock_t start = std::clock();
	
	//Step 1: Pairwise comparison
	std::deque<std::pair<int, int> > m;
	for (size_t i = 0; i < deq_.size(); i += 2) {
		if (i + 1 < deq_.size())
			m.push_back(std::make_pair(deq_[i], deq_[i + 1]));
		else
			m.push_back(std::make_pair(deq_[i], -1));
	}
	for (size_t i = 0; i < m.size(); i++) {
		if (m[i].first < m[i].second)
			std::swap(m[i].first, m[i].second);
	}
	
	//Step 2: Recursion
	recursivePairSort(m, 0, m.size() - 1);
	
	//Step 3: Insertion
	std::deque<int> d;
	d.push_back(m[0].second);
	d.push_back(m[0].first);
	size_t insertedFromFirst = 1;
	size_t insertedFromSecond = 1;
	size_t inserting;
	for (size_t i = 1; insertedFromSecond < m.size(); i++) {
		inserting = jacobsthal(i) * 2;
		for (size_t j = 1; (insertedFromFirst < m.size()) && (j <= inserting); j++) {
			d.push_back(m[insertedFromFirst].first);
			insertedFromFirst++;
		}
		for (size_t j = 1; (insertedFromSecond < m.size()) && (j <= inserting); j++) {
			binaryInsertion(d, m[insertedFromSecond].second);
			insertedFromSecond++;
		}
	}
	
	//Step 4: Finishing up
	if (deq_.size() % 2 == 1)
		d.erase(d.begin());
	deq_ = d;
	
	std::clock_t end = std::clock();
	
	*ss	<< "Time to process a range of"
		<< std::setw(5) << vec_.size()
		<< " elements with std::deque  : "
		<< std::setw(5) << static_cast<double>(end - start) << " us";

	return *ss;
}

void PmergeMe::sort(std::string &str) {
	fill(str);

	std::cout << "Before:  ";
	for (size_t i = 0; i < vec_.size(); i++)
		std::cout << vec_[i] << " ";
	std::cout << std::endl;
	
	std::stringstream &ssVec = sortVec();
	std::stringstream &ssDeq = sortDeq();
	
	std::cout << "After:   ";
	for (size_t i = 0; i < vec_.size(); i++)
		std::cout << vec_[i] << " ";
	std::cout << std::endl;

	std::cout << ssVec.str() << std::endl;
	std::cout << ssDeq.str() << std::endl;
	
	delete &ssVec;
	delete &ssDeq;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:54:07 by misargsy          #+#    #+#             */
/*   Updated: 2024/09/27 10:09:31 by misargsy         ###   ########.fr       */
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
		vec_.push_back(ctint(i));
		deq_.push_back(ctint(i));
	}
	if (!ss.eof())
		throw std::invalid_argument("Invalid argument");
	if (vec_.size() == 0)
		throw std::invalid_argument("Empty argument");

	std::set<int> set;
	for (std::vector<ctint>::iterator it = vec_.begin(); it != vec_.end(); it++)
		set.insert(it->val());
	if (set.size() != vec_.size())
		throw std::invalid_argument("Duplicate argument");
}

size_t PmergeMe::jacobsthal(size_t n) {
	return (std::pow(2, n + 1) + std::pow(-1, n)) / 3;
}


void PmergeMe::sort(std::string str) {
	fill(str);
	size_t veccount, deqcount;
	std::clock_t start, end, vect, deqt;

	std::cout << "Count: " << vec_.size() << std::endl;
	std::cout << "Before: " << std::endl;
	for (std::vector<ctint>::iterator it = vec_.begin(); it != vec_.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << "========================" << std::endl;
	
	ctint::resetComparisons();
	start = std::clock();
	std::vector<std::pair<ctint, size_t> > vecsorted = sortVector(vec_);
	end = std::clock();
	veccount = ctint::getComparisons();
	vect = end - start;

	ctint::resetComparisons();
	start = std::clock();
	std::deque<std::pair<ctint, size_t> > deqsorted = sortDeque(deq_);
	end = std::clock();
	deqcount = ctint::getComparisons();
	deqt = end - start;
	
	std::cout << "std::vector" << std::endl;
	std::cout << "Comparisons:\t" << veccount << std::endl;
	std::cout << "Time:\t\t" << std::fixed << std::setw(5) << std::setprecision(2) << static_cast<double>(vect) << " us" << std::endl;

	std::cout << "---------------------------" << std::endl;

	std::cout << "std::deque" << std::endl;
	std::cout << "Comparisons:\t" << deqcount << std::endl;
	std::cout << "Time:\t\t" << std::fixed << std::setw(5) << std::setprecision(2) << static_cast<double>(deqt) << " us" << std::endl;

	std::cout << "===========================" << std::endl;

	std::vector<ctint> vec = vec_;
	std::sort(vec.begin(), vec.end());

	bool vecok = true, deqok = true;
	for (size_t i = 0; i < vec.size(); i++) {
		if (vec[i] != vecsorted[i].first)
			vecok = false;
		if (vec[i] != deqsorted[i].first)
			deqok = false;
		if (!vecok && !deqok)
			break;
	}
	std::cout << "Sorted: " << std::endl;//print vec
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	std::cout << "std::vector:\t" << (vecok ? "OK" : "KO") << std::endl;
	for (std::vector<std::pair<ctint, size_t> >::iterator it = vecsorted.begin(); it != vecsorted.end(); it++)
		std::cout << it->first << " ";
	std::cout << std::endl;
	std::cout << "std::deque:\t" << (deqok ? "OK" : "KO") << std::endl;
	for (std::deque<std::pair<ctint, size_t> >::iterator it = deqsorted.begin(); it != deqsorted.end(); it++)
		std::cout << it->first << " ";
	std::cout << std::endl;
}

/*
Steps

1
Group elements into pairs, leave the extra one out

2
Sort the pairs so that the first element is greater

3
Sort the pairs based on its first element, recursively calling itself on it

4
Merge the second element of each pair in batches of Jacobsthal numbers.
*/
#define D std::cout << "/--" << __LINE__ << "--/" << std::endl;
std::vector<std::pair<ctint, size_t> > PmergeMe::sortVector(std::vector<ctint> &vec) {
	std::vector<std::pair<ctint, size_t> > indexed;

	for (size_t i = 0; i < vec.size(); i++)
		indexed.push_back(std::make_pair(vec[i], i));
	
	// Base case
	if (vec.size() < 2)
		return indexed;
	if (vec.size() == 2) {
		if (indexed[0].first > indexed[1].first)
			std::iter_swap(indexed.begin(), indexed.begin() + 1);
		return indexed;
	}

	// 1
	size_t size = vec.size();
	std::vector<std::pair<std::pair<ctint, size_t>, std::pair<ctint, size_t> > > pairs;

	for (size_t i = 0; i < (size % 2 == 0 ? size : size - 1); i += 2)
		pairs.push_back(std::make_pair(indexed[i], indexed[i + 1]));

	// 2
	for (size_t i = 0; i < pairs.size(); i++)
		if (pairs[i].first.first < pairs[i].second.first)
			std::swap(pairs[i].first, pairs[i].second);
	
	// 3
	std::vector<ctint> top;
	for (size_t i = 0; i < pairs.size(); i++)
		top.push_back(pairs[i].first.first);
	
	std::vector<std::pair<ctint, size_t> > topsorted = sortVector(top);

	std::vector<std::pair<std::pair<ctint, size_t>, std::pair<ctint, size_t> > > sortedpairs;
	for (size_t i = 0; i < topsorted.size(); i++)
		sortedpairs.push_back(pairs[topsorted[i].second]);

	// 4
	std::vector<std::pair<std::pair<ctint, ssize_t>, std::pair<ctint, ssize_t> > > chain;

	chain.push_back(std::make_pair(sortedpairs[0].second, std::make_pair(0, -1)));
	chain.push_back(std::make_pair(sortedpairs[0].first, std::make_pair(0, -1)));

	for (size_t i = 1; i < sortedpairs.size(); i++)
		chain.push_back(sortedpairs[i]);

	size_t js, i = 0, mergeduntil = 1, count, index;
	bool done;
	
	while (true) {
		js = jacobsthal(i) * 2;
		count = 0;
		index = mergeduntil + js;
		done = index >= chain.size();
		if (done && size % 2 != 0) {
			binaryInsertion(chain, std::make_pair(indexed[size - 1], std::make_pair(0, -1)), chain.size());
			index = chain.size() - 1;
		}
		while (count < js && index > mergeduntil) {
			if (index >= chain.size()) {
				index = chain.size() - 1;
				done = true;
			}
			if (chain[index].second.second != -1) {
				std::pair<ctint, size_t> insertee = chain[index].second;
				chain[index].second = std::make_pair(0, -1);
				binaryInsertion(chain, std::make_pair(insertee, std::make_pair(0, -1)), index);
				count++;
				mergeduntil++;
				index++;
			}
			index--;
		}
		i++;
		if (done)
			break;
	}

	std::vector<std::pair<ctint, size_t> > sorted;
	for (size_t i = 0; i < chain.size(); i++)
		sorted.push_back(chain[i].first);

	return sorted;
}

std::deque<std::pair<ctint, size_t> > PmergeMe::sortDeque(std::deque<ctint> &deq) {
	std::deque<std::pair<ctint, size_t> > indexed;

	for (size_t i = 0; i < deq.size(); i++)
		indexed.push_back(std::make_pair(deq[i], i));
	
	// Base case
	if (deq.size() < 2)
		return indexed;
	if (deq.size() == 2) {
		if (indexed[0].first > indexed[1].first)
			std::iter_swap(indexed.begin(), indexed.begin() + 1);
		return indexed;
	}

	// 1
	size_t size = deq.size();
	std::deque<std::pair<std::pair<ctint, size_t>, std::pair<ctint, size_t> > > pairs;

	for (size_t i = 0; i < (size % 2 == 0 ? size : size - 1); i += 2)
		pairs.push_back(std::make_pair(indexed[i], indexed[i + 1]));

	// 2
	for (size_t i = 0; i < pairs.size(); i++)
		if (pairs[i].first.first < pairs[i].second.first)
			std::swap(pairs[i].first, pairs[i].second);
	
	// 3
	std::deque<ctint> top;
	for (size_t i = 0; i < pairs.size(); i++)
		top.push_back(pairs[i].first.first);
	
	std::deque<std::pair<ctint, size_t> > topsorted = sortDeque(top);

	std::deque<std::pair<std::pair<ctint, size_t>, std::pair<ctint, size_t> > > sortedpairs;
	for (size_t i = 0; i < topsorted.size(); i++)
		sortedpairs.push_back(pairs[topsorted[i].second]);

	// 4
	std::deque<std::pair<ctint, size_t> > chain;

	chain.push_back(sortedpairs[0].second);
	chain.push_back(sortedpairs[0].first);

	size_t js, i = 0, mergeduntil = 0, pairsize = sortedpairs.size();
	while (true) {
		js = jacobsthal(i) * 2;
		for (size_t j = 0; j < js; j++)
			if (mergeduntil + j + 1 < pairsize)
				chain.push_back(sortedpairs[mergeduntil + j + 1].first);
		
		for (size_t j = 0; j < js; j++)
			if (mergeduntil + js - j < pairsize)
				binaryInsertion(chain, sortedpairs[mergeduntil + js - j].second, chain.size() - j - 1);
			
		mergeduntil += js;
		if (mergeduntil >= pairsize)
			break;
		i++;
	}
	if (size % 2 != 0)
		binaryInsertion(chain, indexed[size - 1], chain.size());

	return chain;
}
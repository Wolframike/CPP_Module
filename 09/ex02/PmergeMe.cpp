/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:54:07 by misargsy          #+#    #+#             */
/*   Updated: 2024/09/28 21:28:03 by misargsy         ###   ########.fr       */
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
		ctint ct(i);
		vec_.push_back(i);
		deq_.push_back(i);
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
	std::vector<indexedctint> vecsorted = sortVector(vec_);
	end = std::clock();
	veccount = ctint::getComparisons();
	vect = end - start;

	ctint::resetComparisons();
	start = std::clock();
	std::deque<indexedctint> deqsorted = sortDeque(deq_);
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
	std::cout << "Sorted: " << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	std::cout << "std::vector:\t" << (vecok ? "OK" : "KO") << std::endl;
	for (std::vector<indexedctint>::iterator it = vecsorted.begin(); it != vecsorted.end(); it++)
		std::cout << it->first << " ";
	std::cout << std::endl;
	std::cout << "std::deque:\t" << (deqok ? "OK" : "KO") << std::endl;
	for (std::deque<indexedctint>::iterator it = deqsorted.begin(); it != deqsorted.end(); it++)
		std::cout << it->first << " ";
	std::cout << std::endl;
}

// static void printMISChain(std::vector<MISChainLink> &chain) {
// 	for (size_t i = 0; i < chain.size(); i++)
// 		std::cout << std::setw(3) << chain[i].first.first << " ";
// 	std::cout << std::endl;

// 	for (size_t i = 0; i < chain.size(); i++)
// 		std::cout << std::setw(3) << chain[i].second.first << " ";
// 	std::cout << std::endl;
// }

/*
Steps

1
Group elements into pairs, leave the extra one out.

2
Sort the pairs so that the first element is greater.

3
Sort the pairs based on its first element, recursively using merge-insertion sort.

4
Merge the second element of each pair in batches of Jacobsthal numbers.
Merge elements in the batch in reverse order using binary search.
*/
std::vector<indexedctint> PmergeMe::sortVector(std::vector<ctint> &vec) {
	std::vector<indexedctint> indexed;

	// Index the elements
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
	std::vector<MISChainLink> pairs;

	// Group elements into pairs and create a chain
	for (size_t i = 0; i < (size % 2 == 0 ? size : size - 1); i += 2)
		pairs.push_back(std::make_pair(indexed[i], indexed[i + 1]));
	// 2

	// Sort the pairs so that the first element is greater
	for (size_t i = 0; i < pairs.size(); i++)
		if (pairs[i].first.first < pairs[i].second.first)
			std::swap(pairs[i].first, pairs[i].second);
	
	// 3

	// Create a container with elements on top of the chain
	std::vector<ctint> top;
	for (size_t i = 0; i < pairs.size(); i++)
		top.push_back(pairs[i].first.first);
	
	// Sort it
	std::vector<indexedctint> topsorted = sortVector(top);

	// Reconstruct the chain so that it is sorted with element on top of the chain as the key
	std::vector<MISChainLink> chain;
	for (size_t i = 0; i < topsorted.size(); i++)
		chain.push_back(pairs[topsorted[i].second]);

	// 4

	// Prepare a dummy to fill gaps in the chain
	indexedctint dummy = std::make_pair(static_cast<ctint>(-1LL), -1);

	// The bottom element of the first link do not have to be binary-searched of its position
	chain.insert(chain.begin(), std::make_pair(chain[0].second, dummy));
	chain[1].second = dummy;
	
	/*
	js: Jacobsthal number
	iterations: Number of batch iterations
	mergeduntil: Up until what index the top of the chain has been merged
	index: Index of the element to be merged
	displacement: Number of displacement caused during the merge
	*/
	size_t js, iterations = 0, mergeduntil = 1, index, displacement;

	// printMISChain(chain);
	while (mergeduntil < chain.size()) {
		js = jacobsthal(iterations) * 2; // Merge in batches of Jacobsthal numbers
		displacement = 0;
		if (mergeduntil + js >= chain.size() && size % 2 != 0) { // If this is the last batch and there is an extra element
			binaryInsertion(chain, std::make_pair(indexed[size - 1], dummy), chain.size()); // Insert the extra element
			mergeduntil++; // Merged until one further
		}
		for (ssize_t i = 0; i < static_cast<ssize_t>(js); i++) {
			index = mergeduntil + js - displacement - i; // Rightmost index of the batch(mergeduntil + js) - Skipped dummy elements(displacement) - Number of elements already merged(i)
			if (index < chain.size()) { // If the index is within the chain
				if (chain[index].second.second == -1) { // If the element is a dummy
					displacement++; // Displacement is caused by dummy elements
					i--; // Must not increment as no element is merged
					continue;
				}
				binaryInsertion(chain, std::make_pair(chain[index].second, dummy), index); // Insert the element
				chain[index + 1].second = dummy; // Overwrite the merged element with a dummy
				mergeduntil++; // Merged until one further
			}
		}
		mergeduntil += js; // Merged until the end of the batch
		iterations++; // One iteration done
	}
	// printMISChain(chain);
	// std::cout << "========================" << std::endl;

	std::vector<indexedctint> sorted; // Final sorted container
	for (size_t i = 0; i < chain.size(); i++)
		sorted.push_back(chain[i].first); // Push the top of the chain
	
	return sorted;
}

std::deque<indexedctint> PmergeMe::sortDeque(std::deque<ctint> &deq) {
	std::deque<indexedctint> indexed;

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
	std::deque<MISChainLink> pairs;

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
	
	std::deque<indexedctint> topsorted = sortDeque(top);

	std::deque<MISChainLink> chain;
	for (size_t i = 0; i < topsorted.size(); i++)
		chain.push_back(pairs[topsorted[i].second]);

	// 4
	indexedctint dummy = std::make_pair(static_cast<ctint>(-1LL), -1);

	chain.insert(chain.begin(), std::make_pair(chain[0].second, dummy));
	chain[1].second = dummy;
	
	size_t js, iterations = 0, mergeduntil = 1, index, displacement;

	while (mergeduntil < chain.size()) {
		js = jacobsthal(iterations) * 2;
		displacement = 0;
		if (mergeduntil + js >= chain.size() && size % 2 != 0) {
			binaryInsertion(chain, std::make_pair(indexed[size - 1], dummy), chain.size());
			mergeduntil++;
		}
		for (ssize_t i = 0; i < static_cast<ssize_t>(js); i++) {
			index = mergeduntil + js - displacement - i;
			if (index < chain.size()) {
				if (chain[index].second.second == -1) {
					displacement++;
					i--;
					continue;
				}
				binaryInsertion(chain, std::make_pair(chain[index].second, dummy), index);
				chain[index + 1].second = dummy;
				mergeduntil++;
			}
		}
		mergeduntil += js;
		iterations++;
	}

	std::deque<indexedctint> sorted;
	for (size_t i = 0; i < chain.size(); i++)
		sorted.push_back(chain[i].first);
	
	return sorted;
}
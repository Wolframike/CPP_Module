/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:54:07 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/05 17:36:21 by misargsy         ###   ########.fr       */
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

	int i;
	while (ss >> i) {
		vec_.push_back(i);
		deq_.push_back(i);
	}
	if (!ss.eof())
		throw std::invalid_argument("Invalid argument");
}

void PmergeMe::recursivePairSort(std::vector<std::pair<int, int> > &paired, size_t start, size_t end) {
	if (start == end)
		return;
	size_t mid = (start + end) / 2;
	recursivePairSort(paired, start, mid);
	recursivePairSort(paired, mid + 1, end);
	
	std::vector<std::pair<int, int> > tmp;
	size_t i = start;
	size_t j = mid + 1;
	while (i <= mid && j <= end) {
		if (paired[i].first < paired[j].first)
			tmp.push_back(paired[i++]);
		else
			tmp.push_back(paired[j++]);
	}
	while (i <= mid)
		tmp.push_back(paired[i++]);
	while (j <= end)
		tmp.push_back(paired[j++]);
	for (size_t i = start; i <= end; i++)
		paired[i] = tmp[i - start];
}

size_t PmergeMe::jacobsthalGenerator(size_t n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthalGenerator(n - 1) + 2 * jacobsthalGenerator(n - 2);
}

size_t PmergeMe::binarySearch(std::vector<int> &vec, int value, size_t start, size_t end) {
	if (start > end)
		return start;
	size_t mid = (start + end) / 2;
	if (vec[mid] == value)
		return mid;
	if (vec[mid] < value)
		return binarySearch(vec, value, mid + 1, end);
	return binarySearch(vec, value, start, mid - 1);
}

std::stringstream &PmergeMe::sortVec() {
	std::stringstream *ss = new std::stringstream;
	std::clock_t start = std::clock();
	
	std::vector<std::pair<int, int> > paired;
	
	for (size_t i = 0; i < vec_.size() / 2; i++)
		paired.push_back(std::make_pair(vec_[i], vec_[i + vec_.size() / 2]));

	for (size_t i = 0; i < paired.size(); i++)
		if (paired[i].first > paired[i].second)
			std::swap(paired[i].first, paired[i].second);

	recursivePairSort(paired, 0, paired.size() - 1);

	std::vector<int> sorted;

	sorted.push_back(paired[0].second);

	for (size_t i = 1; i < paired.size(); i++)
		sorted.push_back(paired[i].first);

	size_t index;
	for (size_t i = 0; i < sorted.size(); i++) {
		if (jacobsthalGenerator(i) - 1 >= paired.size())
			continue;
		
		index = binarySearch(sorted, paired[jacobsthalGenerator(i) - 1].second, 0, sorted.size() - 1);
		sorted.insert(sorted.begin() + index, paired[jacobsthalGenerator(i) - 1].second);
	}

	std::clock_t end = std::clock();
	*ss << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s";

	return *ss;
}

std::stringstream &PmergeMe::sortDeq() {
	std::stringstream *ss = new std::stringstream;
	// std::clock_t start = std::clock();
	
	return *ss;
}

void PmergeMe::sort(std::string &str) {
	fill(str);
	std::stringstream &ssVec = sortVec();
	std::stringstream &ssDeq = sortDeq();

	std::cout << "Vector: " << ssVec.str() << std::endl;

	//vector result
	for (size_t i = 0; i < vec_.size(); i++)
		std::cout << vec_[i] << " ";

	std::cout << std::endl;

	delete &ssVec;
	delete &ssDeq;
}

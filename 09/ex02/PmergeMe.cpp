/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:54:07 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/06 19:18:57 by misargsy         ###   ########.fr       */
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

size_t PmergeMe::jacobsthal(size_t n) {
	return (std::pow(2, n + 1) + std::pow(-1, n)) / 3;
}

void PmergeMe::binaryInsertion(std::vector<int> &vec, int value) {
	size_t start = 0;
	size_t end = vec.size();
	size_t mid;
	
	while (start < end) {
		mid = (start + end) / 2;
		if (vec[mid] < value)
			start = mid + 1;
		else
			end = mid;
	}
	vec.insert(vec.begin() + start, value);
}

std::stringstream &PmergeMe::sortVec() {
	std::stringstream *ss = new std::stringstream;
	std::clock_t start = std::clock();
	const size_t floor = vec_.size() / 2;
	
	//Step 1: Pairwise comparison
	std::vector<int> a;
	std::vector<int> b;
	
	for (size_t i = 1; i <= vec_.size(); i++) {
		if (i % 2 == 1)
			a.push_back(vec_[i - 1]);
		else
			b.push_back(vec_[i - 1]);
	}
	
	for (size_t i = 1; i <= floor; i++)
		if (a[i - 1] < b[i - 1])
			std::swap(a[i - 1], b[i - 1]);
			
	//Step 2: Recursion and Renaming
	std::vector<std::pair<int, int> > m;
	for (size_t i = 1; i <= floor; i++)
		m.push_back(std::make_pair(a[i - 1], b[i - 1]));
	
	recursivePairSort(m, 0, m.size() - 1);
	for (size_t i = 1; i <= floor; i++)
		b[i - 1] = m[i - 1].second;
	
	//Step 3: Insertion
	std::vector<int> d;
	d.push_back(b[1 - 1]);
	for (size_t i = 1; i <= floor; i++)
		d.push_back(a[i - 1]);
	size_t k = 2;
	size_t min;
	size_t u;
	std::vector<int> tmp;
	
	while (jacobsthal(k - 1) < floor + 1) {
		min = std::min(jacobsthal(k), floor + 1);
		u = jacobsthal(k - 1) + min;
		for (size_t i = min; i >= jacobsthal(k - 1) + 1; i--) {
			puts("1");
			tmp.clear();
			tmp.resize(u - 1);
			std::cout << d.size() << std::endl;
			for (size_t j = 1; j <= u - 1; j++) {
				std::cout << "j: " << j << std::endl;
				tmp[j - 1] = d[j - 1];
			}
			puts("2");
			binaryInsertion(tmp, b[i - 1]);
			puts("3");
			for (size_t j = u; j <= (2 * min + jacobsthal(k - 1) - i); j++)
				tmp.push_back(d[j - 1]);
			puts("4");
			d.clear();
			for (size_t j = 0; j < tmp.size(); j++)
				d.push_back(tmp[j]);
			while (d[u - 1] != a[i - 1 - 1])
				u--;
			puts("5");
		}
		k++;
	}

	///////////////////////////////////////////////////
	std::clock_t end = std::clock();
	*ss << "Time: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "s";

	return *ss;
}

std::stringstream &PmergeMe::sortDeq() {
	std::stringstream *ss = new std::stringstream;
	std::clock_t start = std::clock();

	std::clock_t end = std::clock();
	*ss << "Time: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "s";

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

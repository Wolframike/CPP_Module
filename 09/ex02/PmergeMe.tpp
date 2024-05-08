/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:52:15 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/09 00:33:17 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void PmergeMe::recursivePairSort(T &paired, size_t start, size_t end) {
	if (start == end)
		return;
	size_t mid = (start + end) / 2;
	recursivePairSort(paired, start, mid);
	recursivePairSort(paired, mid + 1, end);
	
	T tmp;
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

template <typename T>
void PmergeMe::binaryInsertion(T &container, int value) {
	size_t start = 0;
	size_t end = container.size();
	size_t mid;
	
	while (start < end) {
		mid = (start + end) / 2;
		if (container[mid] < value)
			start = mid + 1;
		else
			end = mid;
	}
	container.insert(container.begin() + start, value);
}

template <typename ContainerType, typename PairType>
std::stringstream &PmergeMe::sortContainer(Container type) {
	std::stringstream *ss = new std::stringstream;
	std::clock_t start = std::clock();

	//Step 1: Pairwise comparison
	PairType m;
	for (size_t i = 0; i < vec_.size(); i += 2) {
		if (i + 1 < vec_.size())
			m.push_back(std::make_pair(vec_[i], vec_[i + 1]));
		else
			m.push_back(std::make_pair(vec_[i], -1));
	}
	for (size_t i = 0; i < m.size(); i++)
		if (m[i].first < m[i].second)
			std::swap(m[i].first, m[i].second);
	
	//Step 2: Recursion
	recursivePairSort(m, 0, m.size() - 1);
	
	//Step 3: Insertion
	ContainerType d;
	d.push_back(m[0].second);
	d.push_back(m[0].first);
	size_t insertedFromFirst = 1;
	size_t insertedFromSecond = 1;
	size_t inserting;
	for (size_t i = 1; insertedFromSecond < m.size(); i++) {
		inserting = jacobsthal(i) * 2;
		for (size_t j = 1; (insertedFromFirst < m.size()) && (j <= inserting); j++)
			d.push_back(m[insertedFromFirst++].first);
		for (size_t j = 1; (insertedFromSecond < m.size()) && (j <= inserting); j++)
			binaryInsertion(d, m[insertedFromSecond++].second);
	}
	
	//Step 4: Finishing up
	if (vec_.size() % 2 == 1)
		d.erase(d.begin());
	for (size_t i = 0; i < d.size(); i++) {
		if (type == VECTOR)
			vec_[i] = d[i];
		else
			deq_[i] = d[i];
	}
	
	std::clock_t end = std::clock();
	
	*ss	<< "Time to process a range of"
		<< std::setw(5) << vec_.size()
		<< " elements with ";
	if (type == VECTOR)
		*ss << "std::vector ";
	else
		*ss << "std::deque  ";
	*ss
		<< " : "
		<< std::setw(5) << static_cast<double>(end - start) << " us";
	
	return *ss;
}

#include "PmergeMe.hpp"

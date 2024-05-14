/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:52:15 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/15 06:20:24 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename ContainerType>
void PmergeMe::binaryInsertion(ContainerType *container, int value) {
	size_t start = 0;
	size_t end = container->size();
	size_t mid;
	
	while (start < end) {
		mid = (start + end) / 2;
		if ((*container)[mid] < value)
			start = mid + 1;
		else
			end = mid;
	}
	container->insert(container->begin() + start, value);
}

template <typename ContainerType, typename PairType>
ContainerType *PmergeMe::mergeInsertionSort(ContainerType container) {
	if (container.size() == 1) {
		ContainerType *sorted = new ContainerType;
		*sorted = container;
		return sorted;
	}

	// Step 1: Pairwise comparison
	PairType paired;

	for (size_t i = 0; i < container.size(); i += 2) {
		if (i + 1 < container.size())
			paired.push_back(std::make_pair(container[i], container[i + 1]));
		else
			paired.push_back(std::make_pair(container[i], -1));
	}

	for (size_t i = 0; i < paired.size(); i++)
		if (paired[i].first < paired[i].second)
			std::swap(paired[i].first, paired[i].second);

	// Step 2: Step 2: Recursion
	ContainerType first;
	for (size_t i = 0; i < paired.size(); i++)
		first.push_back(paired[i].first);
	ContainerType *sortedFirst = mergeInsertionSort<ContainerType, PairType>(first);

	PairType sortedPair;
	for (size_t i = 0; i < sortedFirst->size(); i++) {
		for (size_t j = 0; j < paired.size(); j++) {
			if ((*sortedFirst)[i] == paired[j].first) {
				sortedPair.push_back(paired[j]);
				break;
			}
		}
	}

	// Step 3: Insertion
	ContainerType *sorted = new ContainerType;
	sorted->push_back(sortedPair[0].second);
	sorted->push_back(sortedPair[0].first);
	size_t insertedFromFirst = 1;
	size_t insertedFromSecond = 1;

	for (size_t i = 1; insertedFromSecond < sortedPair.size(); i++) {
		size_t inserting = jacobsthal(i) * 2;
		
		for (size_t j = 1; insertedFromFirst < sortedPair.size() && j <= inserting; j++)
			sorted->push_back(sortedPair[insertedFromFirst++].first);
		for (size_t j = 1; insertedFromSecond < sortedPair.size() && j <= inserting; j++)
			binaryInsertion(sorted, sortedPair[insertedFromSecond++].second);
	}

	// Step 4: Cleanup
	if (sorted->front() == -1)
		sorted->erase(sorted->begin());

	delete sortedFirst;
	return sorted;
}

template <typename ContainerType>
std::stringstream PmergeMe::sortContainer(Container type) {
	std::stringstream ss;
	const std::clock_t start = std::clock();

	if (type == VECTOR) {
		std::vector<int> *sorted = mergeInsertionSort<std::vector<int>, std::vector<std::pair<int, int> > >(vec_);
		for (size_t i = 0; i < vec_.size(); i++)
			vec_[i] = (*sorted)[i];
		delete sorted;
	} else {
		std::deque<int> *sorted = mergeInsertionSort<std::deque<int>, std::deque<std::pair<int, int> > >(deq_);
		for (size_t i = 0; i < deq_.size(); i++)
			deq_[i] = (*sorted)[i];
		delete sorted;
	}
	
	const std::clock_t end = std::clock();

	ss	<< "Time to process a range of"
		<< std::setw(5) << (type == VECTOR ? vec_.size() : deq_.size())
		<< " elements with ";
	if (type == VECTOR)
		ss << "std::vector ";
	else
		ss << "std::deque  ";
	ss
		<< " : "
		<< std::setw(5) << static_cast<double>(end - start) << " us";
	
	return ss;
}

#include "PmergeMe.hpp"

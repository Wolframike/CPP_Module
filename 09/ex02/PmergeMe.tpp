/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:52:15 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/08 20:52:19 by misargsy         ###   ########.fr       */
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

#include "PmergeMe.hpp"

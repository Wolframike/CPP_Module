/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:10:23 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/05 17:34:54 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <iostream>

class PmergeMe {
	private:
		std::vector<int> vec_;
		std::deque<int> deq_;

		void fill(std::string &str);

		size_t jacobsthalGenerator(size_t n);

		void recursivePairSort(std::vector<std::pair<int, int> > &paired, size_t start, size_t end);
		size_t binarySearch(std::vector<int> &vec, int value, size_t start, size_t end);
		std::stringstream &sortVec();
		std::stringstream &sortDeq();

		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();

		void sort(std::string &str);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:10:23 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/06 18:57:38 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>

class PmergeMe {
	private:
		std::vector<int> vec_;
		std::deque<int> deq_;

		void fill(std::string &str);

		size_t jacobsthal(size_t n);

		void recursivePairSort(std::vector<std::pair<int, int> > &paired, size_t start, size_t end);
		void binaryInsertion(std::vector<int> &vec, int value);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:10:23 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/09 00:30:23 by misargsy         ###   ########.fr       */
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
#include <iomanip>

class PmergeMe {
	private:
		std::vector<int> vec_;
		std::deque<int> deq_;

		void fill(std::string &str);

		size_t jacobsthal(size_t n);

		template <typename T>
		void recursivePairSort(T &paired, size_t start, size_t end);
		template <typename T>
		void binaryInsertion(T &vec, int value);
		
		enum Container {
			VECTOR,
			DEQUE
		};
		template <typename ContainerType, typename PairType>
		std::stringstream &sortContainer(Container type);

		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();

		void sort(std::string &str);
};

#include "PmergeMe.tpp"

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:10:23 by misargsy          #+#    #+#             */
/*   Updated: 2024/09/28 19:46:31 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <set>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <iomanip>

#include "ctint.hpp"

typedef std::pair<ctint, ssize_t> indexedctint;
typedef std::pair<indexedctint, indexedctint> MISChainLink;

class PmergeMe {
	private:
		std::vector<ctint> vec_;
		std::deque<ctint> deq_;

		void fill(std::string &str);
		size_t jacobsthal(size_t n);
		template <typename PairContainer>
		PairContainer jacobsthalOrderGen(size_t upper);
		
		template <typename Container>
		void binaryInsertion(Container& cont, const std::pair<indexedctint, indexedctint>& el, size_t bound);
		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();

		std::vector<indexedctint> sortVector(std::vector<ctint> &vec);
		std::deque<indexedctint> sortDeque(std::deque<ctint> &deq);

		void sort(std::string);
};

#include "Utils.tpp"

#endif
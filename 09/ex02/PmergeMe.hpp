/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:10:23 by misargsy          #+#    #+#             */
/*   Updated: 2024/09/27 07:55:14 by misargsy         ###   ########.fr       */
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

class PmergeMe {
	private:
		std::vector<ctint> vec_;
		std::deque<ctint> deq_;

		void fill(std::string &str);
		size_t jacobsthal(size_t n);
		template <typename PairContainer>
		PairContainer jacobsthalOrderGen(size_t upper);
		
		template <typename Container, typename Element>
		void binaryInsertion(Container& cont, const Element& el, size_t bound);
		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();

		std::vector<std::pair<ctint, size_t> > sortVector(std::vector<ctint> &vec);
		std::deque<std::pair<ctint, size_t> > sortDeque(std::deque<ctint> &deq);

		void sort(std::string);
};

#include "Utils.tpp"

#endif
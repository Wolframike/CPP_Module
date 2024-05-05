/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:47:40 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/05 17:43:02 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
	private:
		T *array_;
		unsigned int size_;
	
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T> &src);
		Array<T>& operator=(const Array<T> &src);
		~Array();

		T& operator[](unsigned int i);
		const T& operator[](unsigned int i) const;
		unsigned int size() const;
};

#include "Array.tpp"

#endif

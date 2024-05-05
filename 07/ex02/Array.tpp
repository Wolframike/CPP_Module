/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:51:39 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/05 17:43:16 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : array_(NULL), size_(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array_(new T[n]), size_(n) {}

template <typename T>
Array<T>::Array(const Array<T> &src) : array_(new T[src.size_]), size_(src.size_) {
	for (unsigned int i = 0; i < size_; i++)
		array_[i] = src.array_[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &src) {
	if (this == &src)
		return (*this);
	delete[] array_;
	array_ = new T[src.size_];
	size_ = src.size_;
	for (unsigned int i = 0; i < size_; i++)
		array_[i] = src.array_[i];
	return (*this);
}

template <typename T>
Array<T>::~Array() {
	delete[] array_;
}

template <typename T>
T& Array<T>::operator[](unsigned int i){
	if (i >= size_)
		throw std::out_of_range("Array: Index out of range");
	return (array_[i]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const {
	if (i >= size_)
		throw std::out_of_range("Array: Index out of range");
	return (array_[i]);
}

template <typename T>
unsigned int Array<T>::size() const {
	return (size_);
}

#include "Array.hpp"

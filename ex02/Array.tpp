/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:03:54 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/14 15:21:42 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <sstream>

template <typename T>
Array<T>::Array(void) :
	data_(NULL),
	size_(0)
{
	DEBUG_MSG("Array default constructor called");
}

template <typename T>
Array<T>::Array(unsigned int n):
	data_(new T[n]),
	size_(n)
{
	std::stringstream s;
	s << "Array parameterized constructor called (size " << n << ")";
	DEBUG_MSG(s.str());
	
	for (unsigned int i = 0; i < this->size_; i++)
		data_[i] = T();
}

template <typename T>
Array<T>::Array(const Array & other):
	data_(new T[other.size_]),
	size_(other.size_)
{
	std::stringstream s;
	s << "Array copy constructor called (size " << this->size() << ")";
	DEBUG_MSG(s.str());

	for (unsigned int i = 0; i < this->size_; i++)
		this->data_[i] = other.data_[i];
}

template <typename T>
Array<T>::~Array(void)
{
	DEBUG_MSG("Array deconstructor called");

	delete [] data_;
}

template <typename T>
Array<T> & Array<T>::operator=(const Array & other)
{
	std::stringstream s;
	s << "Array copy assignment operator called (size " << other.size() << ")";
	DEBUG_MSG(s.str());

	if (this != &other)
	{
		delete [] this->data_;
		this->size_ = 0;

		this->data_ = new T[other.size_];
		this->size_ = other.size_;

		for (unsigned int i = 0; i < this->size_; i++)
			this->data_[i] = other.data_[i];
	}

	return (*this);
}

template <typename T>
const T & Array<T>::operator[](unsigned int index) const
{
	std::stringstream s;
	s << "Array const operator[] called (index " << index << ")";
	DEBUG_MSG(s.str());

	if (index >= this->size_)
		throw std::exception();

	return (this->data_[index]);
}

template <typename T>
T & Array<T>::operator[](unsigned int index)
{
	std::stringstream s;
	s << "Array operator[] called (index " << index << ")";
	DEBUG_MSG(s.str());

	return (const_cast<T &>((const_cast<const Array<T> &>(*this))[index]));
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (this->size_);
}

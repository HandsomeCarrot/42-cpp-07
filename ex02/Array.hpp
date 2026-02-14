/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:54:55 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/14 13:15:31 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

# define RESET		"\033[0m"
# define BOLDYELLOW	"\033[1m\033[33m"

# ifdef DEBUG
#  define DEBUG_MSG(x) std::cout << BOLDYELLOW << "[DEBUG] " << RESET << x << std::endl
# else
#  define DEBUG_MSG(x)
# endif

template <typename T>
class Array
{
private:
	T*				data_;
	unsigned int	size_;
public:
	Array(void); // empty array
	Array(unsigned int n); // array with n elements
	Array(const Array & other); // create deep copy of other
	~Array(void); //deconstructor
	
	Array & operator=(const Array & other); // create deep copy of other

	const T & operator[](unsigned int index) const; // access i-th element in array (out-of-bounds -> std::exception)
	T & operator[](unsigned int index); // same as above, but non-const

	unsigned int size(void) const;
};

# include "Array.tpp"

#endif /* ARRAY_HPP */

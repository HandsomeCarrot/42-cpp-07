/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:28:14 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/13 15:43:27 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

static void printTest(const std::string& description)
{
	std::cout << "----- TEST: " << description << " -----" << std::endl;
}

void add(int& i)
{
	i++;
}

void subtract(char& c)
{
	c--;
}

static void intTest(void)
{
	printTest("int array[5]");

	int array[5] = {1, 2, 3, 4, 5};
	unsigned int size = 5;

	::iter(array, size, print<int>);

	std::cout << "++adding++" << std::endl;
	::iter(array, size, add);

	::iter(array, size, print<int>);
	std::cout << std::endl;
}

static void charTest(void)
{
	printTest("char array[4]");

	char array[4] = {'a', 'A', '-', 'H'};
	unsigned int size = 4;

	::iter(array, size, print<char>);

	std::cout << "--subtracting--" << std::endl;
	::iter(array, size, subtract);

	::iter(array, size, print<char>);
	std::cout << std::endl;
}

static void stringTest(void)
{
	printTest("string array[3]");

	std::string array[3] = {"one", "two", "three"};
	unsigned int size = 3;

	::iter(array, size, print<std::string>);
	std::cout << std::endl;
}

static void emptyArrayTest(void)
{
	printTest("empty array[0]");

	std::string array[0];

	::iter(array, 0, print<std::string>);
	std::cout << std::endl;
}

static void nullArrayTest(void)
{
	printTest("array = NULL");

	char* array = NULL;

	::iter(array, 0, print<char>);
	std::cout << std::endl;
}

int main(void)
{
	intTest();
	charTest();
	stringTest();
	emptyArrayTest();
	nullArrayTest();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:52:03 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/14 15:12:00 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void	printTest(const std::string & message)
{
	static int test_index = 1;

	const int width = 10;
	const char fill = '=';

	for (int i = 0; i < width; i++)
		std::cout << fill;

	std::cout \
	<< " TEST " << test_index << ": '" << message << "' ";

	for (int i = 0; i < width; i++)
		std::cout << fill;

	std::cout << std::endl;
	test_index++;
}

static void test1(void)
{
	printTest("int Array[5]");
	try
	{
		Array<int> array(5);

		for (unsigned int i = 0; i < array.size(); i++)
			std::cout << array[i] << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << "ERROR: exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void test2(void)
{
	printTest("CONST int Array[5]");
	try
	{
		const Array<int> array(5);

		for (unsigned int i = 0; i < array.size(); i++)
			std::cout << array[i] << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << "ERROR: exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void test3(void)
{
	printTest("deep-copy string Array[2]");
	try
	{
		Array<std::string> array(2);
		array[0] = "1.1";
		array[1] = "1.2";

		Array<std::string> array2(array);
		Array<std::string> array3 = array2;

		std::cout << "BEFORE CHANGE:\n" \
		<< array[0] << " | " << array[1] << "\n" \
		<< array2[0] << " | " << array2[1] << "\n" \
		<< array3[0] << " | " << array3[1] \
		<< std::endl;

		array2[0] = "2.1";
		array2[1] = "2.2";

		array3[0] = "3.1";
		array3[1] = "3.2";

		std::cout << "\nAFTER CHANGE:\n" \
		<< array[0] << " | " << array[1] << "\n" \
		<< array2[0] << " | " << array2[1] << "\n" \
		<< array3[0] << " | " << array3[1] \
		<< std::endl;

		std::cout << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << "ERROR: exception caught: " << e.what() << std::endl;
	}
}

static void test4(void)
{
	printTest("invalid index");
	try
	{
		Array<int> array(5);

		array[5] = 10;
	}
	catch (const std::exception & e)
	{
		std::cerr << "ERROR: exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main(void)
{
	test1();
	test2();
	test3();
	test4();
	return (0);
}

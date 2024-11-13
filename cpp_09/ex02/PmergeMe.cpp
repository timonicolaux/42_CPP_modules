/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 08:16:37 by tnicolau          #+#    #+#             */
/*   Updated: 2024/10/03 14:49:21 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const std::string& input)
{
	addToVector(input);
	addToDeque(input);
	sortVector();
	sortDeque();
}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	*this = copy;
}

PmergeMe::~PmergeMe()
{}

PmergeMe	&PmergeMe::operator=(const PmergeMe& src)
{
	if (this != &src)
	{
		this->first_vector = src.first_vector;
		this->smallest_vector = src.smallest_vector;
		this->biggest_vector = src.biggest_vector;
		this->first_deque = src.first_deque;
		this->smallest_deque = src.smallest_deque;
		this->biggest_deque = src.biggest_deque;
		this->unpaired = src.unpaired;
		this->unpaired_value = src.unpaired_value;
	}
	return *this;
}
void	PmergeMe::sortVector()
{
	clock_t	start, end;
	double	time;

	std::cout << "Before: ";
	for (std::vector<unsigned int>::iterator it = first_vector.begin(); it != first_vector.end(); ++it)
		std::cout << *it << " ";
	if (unpaired)
		std::cout << unpaired_value;
	std::cout << std::endl;
	start = clock();
	sortBiggestRecursiveVector(first_vector);
	makeFinalVector();
	end = clock();
	time = (double)((end - start)) / CLOCKS_PER_SEC * 1000;
	std::cout << "After: ";
	for (std::vector<unsigned int>::iterator it = biggest_vector.begin(); it != biggest_vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Time to process " << biggest_vector.size() << " elements with std::vector : " << time << std::endl;
}

void	PmergeMe::sortDeque()
{
	clock_t	start, end;
	double	time;

	std::cout << "Before: ";
	for (std::deque<unsigned int>::iterator it = first_deque.begin(); it != first_deque.end(); ++it)
		std::cout << *it << " ";
	if (unpaired)
		std::cout << unpaired_value;
	std::cout << std::endl;
	start = clock();
	sortBiggestRecursiveDeque(first_deque);
	makeFinalDeque();
	end = clock();
	time = (double)((end - start)) / CLOCKS_PER_SEC * 1000;
	std::cout << "After: ";
	for (std::deque<unsigned int>::iterator it = biggest_deque.begin(); it != biggest_deque.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Time to process " << biggest_deque.size() << " elements with std::deque : " << time << std::endl;
}

void PmergeMe::sortBiggestRecursiveVector(std::vector<unsigned int>& src)
{
	if (src.size() <= 1) return;
	std::vector<std::pair<unsigned int, unsigned int> > pairs;
	for (int i = 0; i < (int)src.size(); i += 2)
		pairs.push_back(std::make_pair(std::min(src[i], src[i+1]), std::max(src[i], src[i+1])));

	std::vector<unsigned int> recursiveVec;
	for (int i = 0; i < (int)pairs.size(); ++i)
		recursiveVec.push_back(pairs[i].second);

	sortBiggestRecursiveVector(recursiveVec);

	biggest_vector.clear();
	smallest_vector.clear();

	for (int i = 0; i < (int)recursiveVec.size(); ++i)
	{
		binaryInsertionVector(recursiveVec[i]);
		smallest_vector.push_back(pairs[i].first);
	}
}

void PmergeMe::sortBiggestRecursiveDeque(std::deque<unsigned int>& src)
{
	if (src.size() <= 1) return;
	std::deque<std::pair<unsigned int, unsigned int> > pairs;
	for (int i = 0; i < (int)src.size(); i += 2)
		pairs.push_back(std::make_pair(std::min(src[i], src[i+1]), std::max(src[i], src[i+1])));

	std::deque<unsigned int> recursiveVec;
	for (int i = 0; i < (int)pairs.size(); ++i)
		recursiveVec.push_back(pairs[i].second);

	sortBiggestRecursiveDeque(recursiveVec);

	biggest_deque.clear();
	smallest_deque.clear();

	for (int i = 0; i < (int)recursiveVec.size(); ++i)
	{
		binaryInsertionDeque(recursiveVec[i]);
		smallest_deque.push_back(pairs[i].first);
	}
}

std::vector<unsigned int> PmergeMe::generateJacobsthalSequence(unsigned int n)
{
	std::vector<unsigned int> sequence;
	sequence.push_back(0);
	sequence.push_back(1);
	while (sequence[sequence.size() - 1] < n)
	{
		unsigned int next = sequence[sequence.size() - 1] + 2 * sequence[sequence.size() - 2];
		if (next >= n) break;
		sequence.push_back(next);
	}
	return sequence;
}

void	PmergeMe::makeFinalVector()
{
	std::vector<unsigned int> jacobsthal = generateJacobsthalSequence(smallest_vector.size());
	binaryInsertionVector(smallest_vector[0]);

	int lastInserted = 1;

	for (int i = 1; i < (int)jacobsthal.size() && jacobsthal[i] <= smallest_vector.size(); ++i)
	{
		for (int j = jacobsthal[i]; j > lastInserted; --j)
		{
			if (j <= (int)smallest_vector.size())
				binaryInsertionVector(smallest_vector[j - 1]);
		}
		lastInserted = jacobsthal[i];
	}
	for (int i = lastInserted; i < (int)smallest_vector.size(); ++i)
		binaryInsertionVector(smallest_vector[i]);
	if (unpaired)
		binaryInsertionVector(unpaired_value);
}

void	PmergeMe::makeFinalDeque()
{
	std::vector<unsigned int> jacobsthal = generateJacobsthalSequence(smallest_deque.size());
	binaryInsertionDeque(smallest_deque[0]);

	int lastInserted = 1;

	for (int i = 1; i < (int)jacobsthal.size() && jacobsthal[i] <= smallest_deque.size(); ++i)
	{
		for (int j = jacobsthal[i]; j > lastInserted; --j)
		{
			if (j <= (int)smallest_deque.size())
				binaryInsertionDeque(smallest_deque[j - 1]);
		}
		lastInserted = jacobsthal[i];
	}
	for (int i = lastInserted; i < (int)smallest_deque.size(); ++i)
		binaryInsertionDeque(smallest_deque[i]);
	if (unpaired)
		binaryInsertionDeque(unpaired_value);
}

void	PmergeMe::binaryInsertionVector(unsigned int n)
{
	std::vector<unsigned int>::iterator low = biggest_vector.begin();
	std::vector<unsigned int>::iterator high = biggest_vector.end();

	while (low < high)
	{
		std::vector<unsigned int>::iterator mid = low + (high - low) / 2;
		if (n > *mid || n == *mid)
			low = mid + 1;
		else
			high = mid;
	}
	biggest_vector.insert(low, n);
}

void	PmergeMe::binaryInsertionDeque(unsigned int n)
{
	std::deque<unsigned int>::iterator low = biggest_deque.begin();
	std::deque<unsigned int>::iterator high = biggest_deque.end();

	while (low < high)
	{
		std::deque<unsigned int>::iterator mid = low + (high - low) / 2;
		if (n > *mid || n == *mid)
			low = mid + 1;
		else
			high = mid;
	}
	biggest_deque.insert(low, n);
}

void	PmergeMe::addToVector(const std::string& input)
{
	std::stringstream	ss(input);
	std::string			buffer;
	unsigned int		result;

	while (ss >> buffer)
	{
		result = std::atoi(buffer.c_str());
		if (!result && buffer != "0")
			throw NumberTooBig();
		first_vector.push_back(result);
	}
	if (!first_vector.size() || first_vector.size() == 1)
		throw NotEnoughNumbers();
	if (first_vector.size() % 2 != 0)
	{
		unpaired = true;
		unpaired_value = first_vector.back();
		first_vector.pop_back();
	}
}

void	PmergeMe::addToDeque(const std::string& input)
{
	std::stringstream	ss(input);
	std::string			buffer;
	unsigned int		result;

	while (ss >> buffer)
	{
		result = std::atoi(buffer.c_str());
		if (!result && buffer != "0")
			throw NumberTooBig();
		first_deque.push_back(result);
	}
	if (!first_deque.size() || first_deque.size() == 1)
		throw NotEnoughNumbers();
	if (first_deque.size() % 2 != 0)
	{
		unpaired = true;
		unpaired_value = first_deque.back();
		first_deque.pop_back();
	}
}

const char*	PmergeMe::NotEnoughNumbers::what() const throw()
{
	return "Not enough numbers, please include at least two numbers";
}

const char*	PmergeMe::NumberTooBig::what() const throw()
{
	return "Number can't be lower than 0 or greater than unsigned int max";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 08:56:08 by tnicolau          #+#    #+#             */
/*   Updated: 2024/10/02 15:03:16 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{};

BitcoinExchange::BitcoinExchange(const std::string& file)
{
	createDatabase();
	openFile(file);
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	*this = copy;
};

BitcoinExchange::~BitcoinExchange()
{};

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src)
		this->array = src.array;
	return *this;
};

void	BitcoinExchange::createDatabase()
{
	std::ifstream	file;
	std::string	buffer, date, number;

	file.open("data.csv");
	if (!file.is_open())
		throw FileCouldNotOpen();
	else
	{
		while (getline(file, buffer))
		{
			std::stringstream	buffer_stream(buffer);
			getline(buffer_stream, date, ',');
			getline(buffer_stream, number);
			array[date] = atof(number.c_str());
		}
		file.close();
	}
}

void	BitcoinExchange::openFile(const std::string& src)
{
	std::ifstream	file;
	std::string	buffer;

	file.open(src.c_str());
	if (!file.is_open())
		std::cout << "Error: could not open file" << std::endl;
	else
	{
		getline(file, buffer);
		if (buffer != "date | value")
			std::cout << "Error: invalid date | value format" << std::endl;
		else
		{
			while (getline(file, buffer))
			{
				if (!checkDateValidity(buffer))
				{
					if(!checkSeparator(buffer))
					{
						if (!checkNumberValidity(buffer))
							compareDates(buffer);
					}
				}
			}
		}
		file.close();
	}
};

int	BitcoinExchange::compareDates(std::string buffer)
{
	std::stringstream	buffer_stream(buffer);
	std::string date;
	getline(buffer_stream, date, '|');
	date = date.erase(10, date.length());
	std::string number_str = buffer.erase(0, 13);
	float number = atof(number_str.c_str());

	while (array.find(date) == array.end() && date != "2009-01-01")
	{
		if (date == "2009")
		{
			std::cout << "Error: reached limit of year 2009" << std::endl;
			return -1;
		}
		std::cout << "Error: date not found => " << date << ", decreasing date" << std::endl;
		date = decreaseDate(date);
	}
	if (array.find(date) != array.end())
		std::cout << date << " => " << number << " = " << array[date] * number << std::endl;
	else
		std::cout << "Error: date not found in database" << std::endl;
	return 0;
};

std::string	BitcoinExchange::decreaseDate(std::string date)
{
	std::string	year, month, day;
	std::stringstream	buffer_stream(date);
	std::stringstream	result;

	getline(buffer_stream, year, '-');
	int	y = atoi(year.c_str());
	getline(buffer_stream, month, '-');
	int	m = atoi(month.c_str());
	getline(buffer_stream, day);
	int	d = atoi(day.c_str());

	if (d == 1 && m == 1)
		y--;
	if (d == 1)
	{
		if (m == 1 && y == 2009)
			return "2009";
		else if (m == 1)
			m = 12;
		else
			m--;
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
			d = 31;
		if (m == 4 || m == 6 || m == 9 || m == 11)
			d = 30;
		if (m == 2)
			d = 28;
	}
	else
		d--;
	result << y << "-" << std::setw(2) << std::setfill('0') << m << "-" << std::setw(2) << std::setfill('0') << d;
	return result.str();
}

int	BitcoinExchange::checkDateValidity(const std::string& date)
{
	std::string			year, month, day;
	std::stringstream	buffer_stream(date);

	getline(buffer_stream, year, '-');
	getline(buffer_stream, month, '-');
	getline(buffer_stream, day);

	if (checkYear(year) == -1)
		return -1;
	if (checkMonth(month) == -1)
		return -1;
	if (checkDay(day, month) == -1)
		return -1;
	return 0;
};

int	BitcoinExchange::checkSeparator(const std::string& src)
{
	if ((src.length() < 14) || (src[10] != 32 && src[11] != '|' && src[12] != 32))
	{
		std::cout << "Error: no number or wrong format" << std::endl;
		return -1;
	}
	return 0;
};

int	BitcoinExchange::checkNumberValidity(std::string src)
{
	std::string			number_str;
	std::stringstream	buffer_stream(src);
	float	number;
	float	max_value = 1000.0f;

	number_str = src.erase(0, 13);
	number = atof(number_str.c_str());
	if (number < 0)
	{
		std::cout << "Error: not a positive number" << std::endl;
		return -1;
	}
	if (number > max_value)
	{
		std::cout << "Error: too large number" << std::endl;
		return -1;
	}
	return 0;
};

int	BitcoinExchange::checkYear(const std::string& src)
{
	int	year = 0;

	year = atoi(src.c_str());
	if (year < 2009 || year > 2022)
	{
		std::cout << "Error: wrong year format => " << year << std::endl;
		return -1;
	}
	return 0;
};

int	BitcoinExchange::checkMonth(const std::string& src)
{
	int	month = 0;

	month = atoi(src.c_str());
	if (month < 1 || month > 12)
	{
		std::cout << "Error: wrong month format => " << month << std::endl;
		return -1;
	}
	return 0;
};

int	BitcoinExchange::checkDay(const std::string& src_str, const std::string& month_str)
{
	int	day = 0;
	int	month = 0;

	day = atoi(src_str.c_str());
	month = atoi(month_str.c_str());
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
	{
		std::cout << "Error: wrong day format => " << day << std::endl;
		return -1;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		std::cout << "Error: wrong day format => " << day << std::endl;
		return -1;
	}
	if (month == 2 && day > 28)
	{
		std::cout << "Error: wrong day format => " << day << std::endl;
		return -1;
	}
	return 0;
};

const char*	BitcoinExchange::FileCouldNotOpen::what() const throw()
{
	return "Error: could not open database file";
}

#include "ScalarConverter.hpp"
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{

}

bool ScalarConverter::isChar(const std::string& literal)
{
	if (literal.length() != 1)
		return false;
	if (std::isdigit(literal[0]))
		return false;
	return true;
}

bool ScalarConverter::isInt(const std::string& literal)
{
	size_t i = 0;

	if (literal.empty())
		return false;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == literal.length())
		return false;
	while (i < literal.length())
	{
		if (!std::isdigit(literal[i]))
			return false;
		i++;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
	size_t i = 0;
	bool hasDot = false;
	bool hasDigitBeforeDot = false;
	bool hasDigitAfterDot = false;

	if (literal.empty())
		return false;
	if (literal[literal.length() - 1] != 'f')
		return false;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	while (i < literal.length() - 1)
	{
		if (std::isdigit(literal[i]))
		{
			if (hasDot == false)
				hasDigitBeforeDot = true;
			else
				hasDigitAfterDot = true;
		}
		else if (literal[i] == '.')
		{
			if (hasDot == true)
				return false;
			else
				hasDot = true;
		}
		else
			return false;
		i++;
	}
	if (hasDot == true && hasDigitBeforeDot == true && hasDigitAfterDot == true)
		return true;
	return false;
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	size_t i = 0;
	bool hasDot = false;
	bool hasDigitBeforeDot = false;
	bool hasDigitAfterDot = false;

	if (literal.empty())
		return false;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	while (i < literal.length())
	{
		if (std::isdigit(literal[i]))
		{
			if (hasDot == false)
				hasDigitBeforeDot = true;
			else
				hasDigitAfterDot = true;
		}
		else if (literal[i] == '.')
		{
			if (hasDot == true)
				return false;
			else
				hasDot = true;
		}
		else
			return false;
		i++;
	}
	if (hasDot == true && hasDigitBeforeDot == true && hasDigitAfterDot == true)
		return true;
	return false;
}

bool ScalarConverter::isPseudo(const std::string& literal)
{
	if (literal == "inf" || literal == "inff")
		return true;
	if (literal == "-inf" || literal == "-inff")
		return true;
	if (literal == "+inf" || literal == "+inff")
		return true;
	if (literal == "nan" || literal == "nanf")
		return true;
	return false;
}

void ScalarConverter::convert(const std::string& literal)
{
	if (ScalarConverter::isChar(literal))
	{
		char value = literal[0];

		std::cout << "char: '" << value << "'"<< std::endl;
		std::cout << "int: " << static_cast<int>(value) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << std::endl;
	}
	else if (ScalarConverter::isInt(literal))
	{
		char* end;
		long tmp = std::strtol(literal.c_str(), &end, 10);

		(void)end;
		if (tmp < INT_MIN || tmp > INT_MAX)
		{
			double d = std::atof(literal.c_str());
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
		}
		else
		{
			int value = static_cast<int>(tmp);
			if (value < 0 || value > 127)
				std::cout << "char: impossible" << std::endl;
			else if (!std::isprint(static_cast<char>(value)))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
			std::cout << "int: " << value << std::endl;
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(value) << std::endl;
		}
	}
	else if (ScalarConverter::isFloat(literal))
	{
		float value = static_cast<float>(std::atof(literal.c_str()));

		if (value < 0 || value > 127)
			std::cout << "char: impossible" << std::endl;
		else if (!std::isprint(static_cast<char>(value)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		if (static_cast<double>(value) < static_cast<double>(INT_MIN)
			|| static_cast<double>(value) > static_cast<double>(INT_MAX))
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(value) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << value << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << std::endl;
	}
	else if (ScalarConverter::isDouble(literal))
	{
		double value = std::atof(literal.c_str());

		if (value < 0 || value > 127)
			std::cout << "char: impossible" << std::endl;
		else if (!std::isprint(static_cast<char>(value)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		if (value < INT_MIN || value > INT_MAX)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(value) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << value << std::endl;
	}
	else if (ScalarConverter::isPseudo(literal))
	{
		if (literal == "inf" || literal == "inff")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: inff" << std::endl;
			std::cout << "double: inf" << std::endl;
		}
		else if (literal == "-inf" || literal == "-inff")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
		else if (literal == "+inf" || literal == "+inff")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
		else if (literal == "nan" || literal == "nanf")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
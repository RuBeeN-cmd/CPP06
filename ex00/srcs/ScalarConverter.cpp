#include "ScalarConverter.hpp"
#include <iomanip>
#include <limits>
#include <sstream>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void) rhs;
	return (*this);
}

int	ScalarConverter::get_literal_presion(const std::string &literal)
{
	int	precision = 0;
	int	i = literal.length() - 1;
	if (literal[i] == 'f')
		i--;
	while (literal[i] == '0')
		i--;
	while (literal[i] && std::isdigit(literal[i]))
	{
		i--;
		precision++;
	}
	if (literal[i] == '-' || literal[i] == '+')
		i--;
	if (i != -1)
	{
		if (!precision)
			return (1);
		if (precision > 16)
			return (16);
		return (precision);
	}
	return (1);
}

bool	ScalarConverter::is_num(const std::string &literal)
{
	int	i = 0;
	if (literal.length() == 1 && literal[0] == 'f')
		return (false);
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	while (literal[i] && std::isdigit(literal[i]))
		i++;
	if (literal[i] == '.' && i)
		i++;
	while (literal[i] && std::isdigit(literal[i]))
		i++;
	if (literal[i] == 'f')
		i++;
	return ((size_t) i == literal.length() && i);
}

void	ScalarConverter::convert(const std::string &literal)
{
	if (ScalarConverter::is_num(literal))
	{
		std::stringstream ss(literal);
		int to_int;
		if ((ss >> to_int))
		{
			if (to_int >= 0 && to_int <= 127)
			{
				if (std::isprint(to_int))
					std::cout << "char: \'" << (char) to_int << "\'" << std::endl;
				else
					std::cout << "char: Non displayable" << std::endl;
			}
			else
			{
				std::cout << "char: impossible" << std::endl;
			}
			std::cout << "int: " << to_int << std::endl;
		}
		else
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		}
		int precision = ScalarConverter::get_literal_presion(literal);
		float to_float = (float) std::atof(literal.c_str());
		if (to_float == std::numeric_limits<float>::infinity()
			|| to_float == -std::numeric_limits<float>::infinity())
			std::cout << "float: impossible" << std::endl;
		else	
			std::cout << "float: " << std::fixed << std::setprecision(precision) << (float) std::atof(literal.c_str()) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(precision) << (double) std::strtod(literal.c_str(), NULL) << std::endl;
	}
	else
	{
		if (literal.length() == 1)
		{
			std::cout << "char: \'" << literal[0] << "\'" << std::endl;
			std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
			std::cout << "float: " << static_cast<float>(literal[0]) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(literal[0]) << ".0" << std::endl;
		}
		else
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			if (literal == "-inf")
			{
				std::cout << "float: " << -std::numeric_limits<float>::infinity() << "f" << std::endl;
				std::cout << "double: " << -std::numeric_limits<float>::infinity() << std::endl;
			}
			else if (literal == "inf" || literal == "+inf")
			{
				std::cout << "float : " << std::numeric_limits<float>::infinity() << "f" << std::endl;
				std::cout << "double: " << std::numeric_limits<double>::infinity() << std::endl;
			}
			else if (literal == "nan" || literal == "nanf")
			{
				std::cout << "float : " << std::numeric_limits<float>::quiet_NaN() << "f" << std::endl;
				std::cout << "double: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
			}
			else
			{
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
			}
		}
	}
}
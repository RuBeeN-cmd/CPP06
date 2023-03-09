#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class ScalarConverter
{
private:
	static int	get_literal_presion(const std::string &);
	static bool	is_num(const std::string &);
	ScalarConverter();
	ScalarConverter(const ScalarConverter &);

public:
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &);

	static void	convert(const std::string &);
};

#endif
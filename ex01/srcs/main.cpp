#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data		*data = new Data;

	data->index = 2;
	std::cout << Serializer::deserialize(Serializer::serialize(data))->index << std::endl;
	delete data;
	return 0;
}

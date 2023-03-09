#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

struct Data {
	int	index;
};

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &);

public:
	~Serializer();
	Serializer	&operator=(const Serializer &);

	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);
};

#endif
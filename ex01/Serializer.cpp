#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return *this;
}

Serializer::~Serializer()
{

}

uintptr_t Serializer::serialize(Data* ptr)
{
	(void)ptr;
	return 0;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	(void)raw;
	return NULL;
}
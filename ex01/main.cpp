#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data data;

	data.id = 42;
	data.name = "jejeon";

	Data* original = &data;

	uintptr_t raw = Serializer::serialize(original);
	Data* restored = Serializer::deserialize(raw);

	std::cout << "original pointer: " << original << std::endl;
	std::cout << "serialized raw:   " << raw << std::endl;
	std::cout << "restored pointer: " << restored << std::endl;
	if (original == restored)
		std::cout << "same pointer: yes" << std::endl;
	else
		std::cout << "same pointer: no" << std::endl;
	std::cout << "restored id: " << restored->id << std::endl;
	std::cout << "restored name: " << restored->name << std::endl;

	return 0;
}
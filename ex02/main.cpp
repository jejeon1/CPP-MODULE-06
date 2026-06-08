#include "Base.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(NULL));

    Base* ptr = generate();

    identify(ptr);
    identify(*ptr);

    delete ptr;
    return 0;
}

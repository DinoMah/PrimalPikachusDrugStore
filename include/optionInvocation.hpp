#ifndef OPTIONINVOCATION_H
#define OPTIONINVOCATION_H

#include "../src/objeto.cpp"
#include <functional>

void invokeOption(int option, std::function<void(objeto &)> (options[]));

#endif // OPTIONINVOCATION_H
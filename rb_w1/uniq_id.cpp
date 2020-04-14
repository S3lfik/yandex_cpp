#include <iostream>

#define STRING(x) #x
#define TO_STRING(x) STRING(x)
#define UNIQ_ID TO_STRING(__LINE__)


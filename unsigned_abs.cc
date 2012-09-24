#ifdef STDLIB_H_VERSION
#include <stdlib.h>
#else
#include <cstdlib>
#endif
#include <iostream>
using std::cout; using std::endl;

template <typename T> class type_name {
public:
    static const char *name;
};

// Type name printing borrowed from http://stackoverflow.com/a/81939
#define DECLARE_TYPE_NAME(x) template<> const char *type_name<x>::name = #x;
#define GET_TYPE_NAME(x) (type_name<typeof(x)>::name)

DECLARE_TYPE_NAME(int);
DECLARE_TYPE_NAME(unsigned int);

#define PRINT_TYPE_OF(x)                                                \
    do {                                                                \
        cout << "Type of (" << #x << "): " << GET_TYPE_NAME((x)) << endl; \
    } while (0)

#define PRINT_VALUE(x)                          \
    do {                                        \
        cout << #x << " = " << (x) << endl;     \
    } while (0)

#define PRINT_ABS_VALUE(x, abs_fn)                              \
    do {                                                        \
        cout << "abs(" << #x << ") = " << abs_fn(x) << endl;    \
    } while (0)


int main()
{
    unsigned int a = 1;
    unsigned int b = 2;
    int c = 3;
    int d = 4;

    PRINT_TYPE_OF(a-b);
    PRINT_TYPE_OF(b-c);
    PRINT_TYPE_OF(c-d);

    PRINT_VALUE(a-b);
    PRINT_VALUE(b-c);
    PRINT_VALUE(c-d);

    PRINT_ABS_VALUE(a-b, abs);
    PRINT_ABS_VALUE(b-c, abs);
    PRINT_ABS_VALUE(c-d, abs);

    PRINT_ABS_VALUE((unsigned int)1 - (unsigned int)2, abs);

#ifdef SHOW_AMBIGUOUS_STD_ABS
    // compiler error; std::abs(unsigned int) is ambiguous
    // (unclear which signed integer type to convert to)
    PRINT_ABS_VALUE(a-b, std::abs);
#endif

    return 0;
}

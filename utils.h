#ifndef UTILS_H_INCLUDED_V0HG4H89CAC
#define UTILS_H_INCLUDED_V0HG4H89CAC

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
        cout << #abs_fn << "(" << #x << ") = " << abs_fn(x) << endl;  \
    } while (0)

void print_separator()
{
    cout << "----" << endl;
}

template <typename T>
static T
abs_diff(T a, T b)
{
    return ((a < b) ? b-a : a-b);
}

#endif /* include guard */

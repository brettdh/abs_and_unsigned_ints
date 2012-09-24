#include "utils.h"

int main()
{
    unsigned int a = 1, b = 2;
    int c = 3, d = 4;

    PRINT_TYPE_OF(a);
    PRINT_TYPE_OF(b);
    PRINT_TYPE_OF(c);
    PRINT_TYPE_OF(d);

    print_separator();

    PRINT_VALUE(a);
    PRINT_VALUE(b);
    PRINT_VALUE(c);
    PRINT_VALUE(d);

    print_separator();

    PRINT_TYPE_OF(a-b);
    PRINT_TYPE_OF(b-c);
    PRINT_TYPE_OF(c-d);
    PRINT_TYPE_OF((unsigned int)1 - (unsigned int)2);
    PRINT_TYPE_OF(abs_diff(a,b));

    print_separator();

    PRINT_VALUE(a-b);
    PRINT_VALUE(b-c);
    PRINT_VALUE(c-d);
    PRINT_VALUE((unsigned int)1 - (unsigned int)2);

    print_separator();

    PRINT_ABS_VALUE(a-b, abs);
    PRINT_ABS_VALUE(b-c, abs);
    PRINT_ABS_VALUE(c-d, abs);
    PRINT_ABS_VALUE((unsigned int)1 - (unsigned int)2, abs);

    PRINT_VALUE(abs_diff(a, b));

#ifdef SHOW_AMBIGUOUS_STD_ABS
    // compiler error; std::abs(unsigned int) is ambiguous
    // (unclear which signed integer type to convert to)
    PRINT_ABS_VALUE(a-b, std::abs);
#endif

    return 0;
}

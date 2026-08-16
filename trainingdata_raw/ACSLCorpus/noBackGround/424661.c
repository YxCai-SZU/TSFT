#include <stdbool.h>

/*@
    requires 1 <= a <= 10;
    requires 1 <= b <= 10;
    requires 1 <= c <= 10;
    ensures \result == true <==> ((((a) == 5 && (b) == 5 && (c) != 5) ||
        ((a) == 5 && (b) != 5 && (c) == 5) ||
        ((a) != 5 && (b) == 5 && (c) == 5)) || (((a) == 5 && (b) == 5 && (c) == 5)));
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    unsigned long long count;
    count = 0;

    //@ assert count == 0;

    if (a == 5)
    {
        count += 1;
    }

    if (b == 5)
    {
        count += 1;
    }

    if (c == 5)
    {
        count += 1;
    }

    //@ assert count == 0 || count == 1 || count == 2 || count == 3;

    return (count == 2) || (count == 3);
}

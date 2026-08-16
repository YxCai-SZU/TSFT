#include <stdbool.h>

/*@
    requires 1 <= a <= 10;
    requires 1 <= b <= 10;
    requires 1 <= c <= 10;
    ensures \result == true <==> (((a) == 5 && (b) == 5 && (c) == 7) ||
        ((a) == 5 && (b) == 7 && (c) == 5) ||
        ((a) == 7 && (b) == 5 && (c) == 5));
 */
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int count_5;
    unsigned int count_7;
    count_5 = 0;
    count_7 = 0;

    if (a == 5)
    {
        count_5 += 1;
    }
    if (a == 7)
    {
        count_7 += 1;
    }
    if (b == 5)
    {
        count_5 += 1;
    }
    if (b == 7)
    {
        count_7 += 1;
    }
    if (c == 5)
    {
        count_5 += 1;
    }
    if (c == 7)
    {
        count_7 += 1;
    }

    //@ assert count_5 <= 3;
    //@ assert count_7 <= 3;

    return count_5 == 2 && count_7 == 1;
}

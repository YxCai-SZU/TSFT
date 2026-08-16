#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 5000) && (1 <= (b) && (b) <= 5000) && (1 <= (c) && (c) <= 5000);
    ensures \result == (a + b >= c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool is_possible = false;
    unsigned int sum = 0;

    sum = a + b;

    //@ assert sum == a + b;

    if (sum >= c)
    {
        is_possible = true;
    }

    //@ assert is_possible == (a + b >= c);

    return is_possible;
}

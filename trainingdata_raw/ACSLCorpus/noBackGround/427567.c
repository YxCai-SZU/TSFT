#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 500 &&
        1 <= (b) && (b) <= 500 &&
        1 <= (c) && (c) <= 1000);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum;

    //@ assert (1 <= (a) && (a) <= 500 &&         1 <= (b) && (b) <= 500 &&         1 <= (c) && (c) <= 1000);
    sum = a + b;
    //@ assert sum == a + b;
    return sum >= c;
}

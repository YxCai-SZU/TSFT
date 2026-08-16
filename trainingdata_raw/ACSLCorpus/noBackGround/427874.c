#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result == (c >= a && c <= a + b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result = false;
    unsigned int sum = 0;

    //@ assert (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    sum = a + b;
    //@ assert sum == a + b;

    if (c >= a && c <= sum) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == (c >= a && c <= a + b);
    return result;
}

#include <stdbool.h>

/*@
    requires (1 <= (a) <= 13) && (1 <= (b) <= 13) && (1 <= (c) <= 13);
    ensures \result == (a + b + c >= 22);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum;
    sum = a + b + c;

    if (a == 1 && b == 1 && c == 1)
    {
        //@ assert sum == 3;
        return false;
    }
    else if (sum >= 22)
    {
        //@ assert sum >= 22;
        return true;
    }
    else
    {
        //@ assert sum < 22;
    }
    return false;
}

#include <stdbool.h>

/*@
    requires (1 <= (a) <= 13) && (1 <= (b) <= 13) && (1 <= (c) <= 13);
    ensures \result == (a + b + c >= 22);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum;
    bool result;

    sum = a + b + c;

    //@ assert 3 <= sum <= 39;

    if (sum >= 22)
    {
        result = true;
    }
    else
    {
        //@ assert sum == a + b + c;
        result = false;
    }

    return result;
}

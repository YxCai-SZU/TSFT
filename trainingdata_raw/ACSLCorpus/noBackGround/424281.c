#include <stdbool.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    ensures \result == (a <= b);
    assigns \nothing;
 */
bool func(int a, int b)
{
    int diff;
    bool is_leq;

    diff = a - b;
    is_leq = false;

    if (diff <= 0)
    {
        is_leq = true;
    }

    //@ assert diff <= 0 ==> is_leq == true;
    //@ assert diff > 0 ==> is_leq == false;

    return is_leq;
}

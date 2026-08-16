#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    ensures \result == (a + b == c || b + c == a || c + a == b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    unsigned int index;

    if (a + b == c || b + c == a || c + a == b)
    {
        return true;
    }
    else
    {
        index = 0;
        /*@
            loop invariant 0 <= index <= 3;
            loop invariant !(a + b == c || b + c == a || c + a == b);
            loop assigns index;
            loop variant 3 - index;
        */
        while (index < 3)
        {
            //@ assert index < 3;
            index += 1;
        }
    }
    return false;
}

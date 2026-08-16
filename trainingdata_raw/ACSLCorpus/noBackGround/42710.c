#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    ensures \result == true <==> x % 2 == 0;
    assigns \nothing;
 */
bool func(int x)
{
    bool is_even = false;
    int temp;

    if (x >= 2 && x <= 100)
    {
        temp = x;
        /*@
            loop invariant 1 <= x <= 100;
            loop invariant temp >= 0;
            loop invariant temp <= x;
            loop invariant temp % 2 == x % 2;
            loop assigns temp;
            loop variant temp;
         */
        while (temp >= 2)
        {
            temp -= 2;
        }
        if (temp == 0)
        {
            is_even = true;
        }
    }

    //@ assert is_even == true <==> x % 2 == 0;
    return is_even;
}

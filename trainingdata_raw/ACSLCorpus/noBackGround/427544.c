#include <stdbool.h>

/*@
    requires (2 <= (n) && (n) <= 100 &&
        1 <= (a) && (a) < (b) && (b) <= (n));
    ensures \result == (((b) - (a) - 1) % 2 == 0);
    assigns \nothing;
*/
bool func(int n, int a, int b)
{
    int interval = b - a - 1;
    bool is_even = false;
    int temp = interval;

    /*@
        loop invariant 0 <= temp <= interval;
        loop invariant temp % 2 == interval % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }

    //@ assert temp == 0 || temp == 1;
    
    if (temp == 0)
    {
        is_even = true;
    }

    //@ assert is_even == (interval % 2 == 0);
    return is_even;
}

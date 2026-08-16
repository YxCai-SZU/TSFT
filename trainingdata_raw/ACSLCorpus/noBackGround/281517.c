#include <stdbool.h>

/*@
    requires (1 <= (k) && (k) <= 100 && 1 <= (x) && (x) <= 100000);
    ensures \result == (k * 500 >= x);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int x)
{
    // Variable declarations at top of scope
    unsigned int sum = 0;
    unsigned int i = 0;

    /*@
        loop invariant 0 <= i <= k;
        loop invariant sum == (500 * (i));
        loop invariant sum <= (500 * (k));
        loop assigns sum, i;
        loop variant k - i;
    */
    while (i < k)
    {
        //@ assert sum == 500 * i;
        sum += 500;
        i += 1;
        //@ assert sum == 500 * i;
    }

    //@ assert sum == 500 * k;
    return sum >= x;
}

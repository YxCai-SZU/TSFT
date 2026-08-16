#include <stdbool.h>

/*@
    predicate is_target(integer n) =
        n >= 2000 && (n % 2000 == 0 || n % 2000 == 200);
 */

/*@
    requires 1 <= n <= 1000000000;
    ensures \result == (n >= 2000 && (n % 2000 == 0 || n % 2000 == 200));
    assigns \nothing;
 */
bool func(unsigned long n)
{
    unsigned long i;

    if (n >= 2000 && (n % 2000 == 0 || n % 2000 == 200))
    {
        //@ assert is_target(n);
        return true;
    }
    else
    {
        i = 1;
        /*@
            loop invariant 1 <= n <= 1000000000;
            loop invariant 1 <= i <= 1000000000;
            loop invariant !(n >= 2000 && (n % 2000 == 0 || n % 2000 == 200));
            loop assigns i;
            loop variant 1000000000 - i;
         */
        while (i < 1000000000)
        {
            //@ assert i * 2000 >= n ==> !is_target(n);
            if (i * 2000 >= n)
            {
                return false;
            }
            i += 1;
        }
    }
    return false;
}

#include <stdbool.h>

/*@
    requires 2 <= n <= 1000000;
    ensures \result <= 1000000;
    assigns \nothing;
 */
unsigned int func(unsigned int n)
{
    unsigned int count = 0;
    unsigned int i = 1;

    /*@
        loop invariant 1 <= i <= n;
        loop invariant count <= i;
        loop invariant 2 <= n <= 1000000;
        loop assigns i, count;
        loop variant n - i;
     */
    while (i < n)
    {
        //@ assert 1 <= i < n;
        if (i % 2 == 0)
        {
            //@ assert ((i) % 2 == 0);
            count += 1;
        }
        i += 1;
    }
    //@ assert i == n;
    return count;
}

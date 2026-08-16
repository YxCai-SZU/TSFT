#include <stdbool.h>

/*@
    predicate is_odd(integer n, bool ret) =
        ret == (n % 2 != 0);
 */

/*@
    requires n < 0x100000000;
    ensures \result == (n % 2 != 0);
    assigns \nothing;
 */
bool is_odd(unsigned int n)
{
    unsigned int count;
    count = n;

    /*@
        loop invariant count <= n;
        loop invariant count % 2 == n % 2;
        loop invariant count < 0x100000000;
        loop assigns count;
        loop variant count;
     */
    while (count >= 2)
    {
        count -= 2;
    }

    //@ assert count == 0 || count == 1;
    return count == 1;
}

int main(void)
{
    return 0;
}

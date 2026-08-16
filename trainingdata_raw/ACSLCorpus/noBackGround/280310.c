#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures (n % 2 == 0 ==> \result == 1) && (n % 2 != 0 ==> \result == 1);
    assigns \nothing;
*/
int func(int n)
{
    int result = 1;
    int i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant result == 1;
        loop invariant (n % 2 == 0 ==> result == 1) && (n % 2 != 0 ==> result == 1);
        loop assigns i;
        loop variant n - i;
    */
    while (i < n)
    {
        i = i + 1;
    }

    //@ assert (n % 2 == 0 ==> result == 1) && (n % 2 != 0 ==> result == 1);
    return result;
}

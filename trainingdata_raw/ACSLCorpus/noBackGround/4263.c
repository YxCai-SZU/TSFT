#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == ((n) * ((n) + 1) / 2);
    assigns \nothing;
*/
int func(int n)
{
    int sum = 0;
    int i = 1;

    /*@
        loop invariant 1 <= i <= n + 1;
        loop invariant sum == ((i - 1) * ((i - 1) + 1) / 2);
        loop invariant sum >= 0;
        loop assigns sum, i;
        loop variant n + 1 - i;
    */
    while (i <= n)
    {
        //@ assert 0 <= i * (i + 1) <= 100 * 101;
        //@ assert sum + i >= 0;
        //@ assert sum + i == ((i) * ((i) + 1) / 2);

        sum += i;
        i += 1;
    }

    //@ assert sum == ((n) * ((n) + 1) / 2);
    return sum;
}

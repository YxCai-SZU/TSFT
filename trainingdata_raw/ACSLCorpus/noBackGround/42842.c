#include <stdbool.h>

/*@
    requires 1 <= n <= 10000;
    ensures \result == 0 || \result == 1;
    ensures ((n) % 2 == 1) ==> \result == 1;
    ensures ((n) % 2 == 0) ==> \result == 0;
*/
int func(int n)
{
    int rest;
    bool is_odd_var;
    int count;

    rest = n;
    is_odd_var = false;
    count = 0;

    /*@
        loop invariant 0 <= rest <= n;
        loop invariant 0 <= count <= n / 2;
        loop invariant rest == n - 2 * count;
        loop assigns rest, count;
        loop variant rest;
    */
    while (rest >= 2)
    {
        //@ assert rest >= 2;
        rest -= 2;
        count += 1;
    }

    if (rest == 1)
    {
        is_odd_var = true;
    }

    if (is_odd_var)
    {
        //@ assert ((n) % 2 == 1);
        return 1;
    }
    else
    {
        //@ assert ((n) % 2 == 0);
        return 0;
    }
}

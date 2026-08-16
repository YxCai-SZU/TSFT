#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000 && 0 <= (b) <= 1000);
    ensures \result == (((a) % 500) <= b && ((a) % 500) != 0) || ((a) % 500) == 0;
    assigns \nothing;
*/
bool func(int a, int b)
{
    int r = a;

    /*@
        loop invariant 1 <= a <= 10000;
        loop invariant 0 <= b <= 1000;
        loop invariant 0 <= r <= a;
        loop invariant r % 500 == a % 500;
        loop assigns r;
        loop variant r;
    */
    while (r >= 500)
    {
        //@ assert r % 500 == a % 500;
        r -= 500;
    }

    //@ assert r == a % 500;
    //@ assert r == ((a) % 500);
    return r <= b || r == 0;
}

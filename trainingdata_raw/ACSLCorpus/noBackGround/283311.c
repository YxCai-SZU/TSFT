#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 20 &&
        1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 2000);
    ensures \result == ((n) * (a)) || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
int func(int n, int a, int b)
{
    int product;
    int res;

    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 2000;
    //@ assert ((n) * (a)) <= 2000;

    product = n * a;

    if (product < b) {
        res = product;
    } else {
        //@ assert b <= 2000;
        res = b;
    }

    //@ assert res == ((n) * (a)) || res == b;
    //@ assert res <= b;
    return res;
}

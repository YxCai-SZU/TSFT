#include <stdbool.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    ensures ((\result) == (((a)) * ((n))) || (\result) == (b));
    ensures 1 <= \result <= 50 * 20;
    assigns \nothing;
*/
int func(int n, int a, int b)
{
    int product;
    int result;

    //@ assert 1 <= a * n <= 50 * 20;
    product = a * n;

    if (product < b)
    {
        result = product;
    }
    else
    {
        result = b;
    }

    //@ assert ((result) == (((a)) * ((n))) || (result) == (b));
    //@ assert 1 <= result <= 50 * 20;
    return result;
}

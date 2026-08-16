#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (n * a > b);
    assigns \nothing;
*/
bool func(int n, int a, int b)
{
    // Variable declarations at scope top
    int product;
    bool result;

    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= a && a <= 100;
    //@ assert n * a <= 10000;

    product = n * a;
    result = product > b;
    return result;
}

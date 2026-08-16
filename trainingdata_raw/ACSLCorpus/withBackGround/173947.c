#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b, integer n) =
        0 <= a && a <= n && 0 <= b && b <= n && 1 <= n && n <= 100;

    lemma mul_bounds: \forall integer a, b, n;
        bounds(a, b, n) ==> 0 <= a * b && a * b <= n * n;

    lemma mul_bounds_max: \forall integer a, b, n;
        bounds(a, b, n) ==> 0 <= a * b && a * b <= 10000;
*/

/*@
    requires 1 <= n && n <= 100;
    requires 0 <= a && a <= n;
    requires 0 <= b && b <= n;
    requires 0 <= c && c <= n;
    ensures \result == (a * b >= c);
    assigns \nothing;
*/
bool func(int n, int a, int b, int c)
{
    // Variable declarations at top
    int product;
    bool result;

    //@ assert bounds(a, b, n);
    //@ assert 0 <= a * b && a * b <= n * n;
    //@ assert 0 <= a * b && a * b <= 10000;

    product = a * b;
    result = product >= c;
    return result;
}

int main()
{
    return 0;
}

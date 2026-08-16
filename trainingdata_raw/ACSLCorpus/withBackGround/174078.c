#include <limits.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bounds:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> 
            1 <= product(x, y) <= 100;
*/

/*@
    requires valid_range(a) && valid_range(b) && 
             valid_range(c) && valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures 1 <= \result <= 100;
*/
int func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    int product1;
    int product2;
    int ans;

    //@ assert valid_range(a) && valid_range(b);
    //@ assert 1 <= product(a, b) <= 100;
    product1 = a * b;

    //@ assert valid_range(c) && valid_range(d);
    //@ assert 1 <= product(c, d) <= 100;
    product2 = c * d;

    if (product1 > product2) {
        ans = product1;
        //@ assert ans == product(a, b);
    } else {
        ans = product2;
        //@ assert ans == product(c, d);
    }

    //@ assert ans == product(a, b) || ans == product(c, d);
    //@ assert 1 <= ans <= 100;
    return ans;
}

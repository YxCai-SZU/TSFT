#include <limits.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_in_range:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> 
            1 <= product(x, y) <= 10000 * 10000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Declare all variables at the top
    int product1;
    int product2;
    int result;

    //@ assert valid_range(a) && valid_range(b);
    //@ assert 1 <= product(a, b) <= 10000 * 10000;
    product1 = a * b;

    //@ assert valid_range(c) && valid_range(d);
    //@ assert 1 <= product(c, d) <= 10000 * 10000;
    product2 = c * d;

    if (product1 > product2) {
        result = product1;
    } else {
        result = product2;
    }

    //@ assert result == product(a, b) || result == product(c, d);
    //@ assert result >= 1;
    return result;
}

int main() {
    return 0;
}

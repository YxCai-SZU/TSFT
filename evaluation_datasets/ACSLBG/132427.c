#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;

    logic integer product(integer a, integer b) = a * b;

    lemma product_range:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> 
            1 <= product(a, b) <= 100000000;
*/


bool func(int a, int b, int c, int d)
{
    // Variable declarations at scope top
    int a_b;
    int c_d;
    bool result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);

    //@ assert 1 <= product(a, b) <= 100000000;
    a_b = a * b;

    //@ assert 1 <= product(c, d) <= 100000000;
    c_d = c * d;

    if (a_b > c_d) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == (product(a, b) > product(c, d));
    return result;
}

/*@
    logic integer non_linear_arith_example(integer a, integer b, integer k) = a * b * k;

    lemma test_non_linear_arith_example:
        non_linear_arith_example(2, 3, 4) == 24 &&
        non_linear_arith_example(2, 3, 5) == 30;
*/

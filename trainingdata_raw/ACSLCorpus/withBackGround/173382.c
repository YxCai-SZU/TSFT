#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10;

    logic integer product(integer a, integer b, integer c) = a * b * c;
    logic integer sum(integer a, integer b, integer c) = a + b + c;
    logic integer expected_result(integer a, integer b, integer c) = 
        product(a, b, c) + sum(a, b, c);

    lemma product_bounds: 
        \forall integer a, b, c; 
        valid_range(a) && valid_range(b) && valid_range(c) ==> 
        1 <= product(a, b, c) <= 1000;

    lemma sum_bounds: 
        \forall integer a, b, c; 
        valid_range(a) && valid_range(b) && valid_range(c) ==> 
        1 <= sum(a, b, c) <= 30;
*/

/*@
    requires 1 <= a <= 10;
    requires 1 <= b <= 10;
    requires 1 <= c <= 10;
    ensures \result == expected_result(a, b, c) || \result == -1;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int product;
    int sum;
    int result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);

    //@ assert 1 <= a * b <= 100;
    product = a * b * c;
    //@ assert 1 <= product <= 1000;

    sum = a + b + c;
    //@ assert 1 <= sum <= 30;

    result = product + sum;

    if (result >= 1000) {
        result = -1;
    }

    //@ assert result == -1 || result == expected_result(a, b, c);
    return result;
}

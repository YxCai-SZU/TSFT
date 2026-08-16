#include <limits.h>

/*@
    predicate valid_range(integer a) = 1 <= a <= 20;

    logic integer sum_op(integer a, integer b) = a + b;
    logic integer product_op(integer a, integer b) = a * b;
    logic integer diff_op(integer a, integer b) = a - b;

    lemma product_bounds: \forall integer a, b; valid_range(a) && valid_range(b) ==> 1 <= product_op(a, b) <= 400;
*/

/*@
    requires valid_range(A) && valid_range(B);
    ensures \result == sum_op(A, B) || \result == product_op(A, B) || \result == diff_op(A, B);
    ensures \result >= sum_op(A, B);
    ensures \result >= product_op(A, B);
    ensures \result >= diff_op(A, B);
*/
int func(int A, int B) {
    int sum;
    int product;
    int difference;
    int max_val;

    //@ assert valid_range(A) && valid_range(B);
    //@ assert 1 <= A <= 20 && 1 <= B <= 20;
    //@ assert 1 <= product_op(A, B) <= 400;

    sum = A + B;
    product = A * B;
    difference = A - B;

    max_val = sum;
    if (product > max_val) {
        max_val = product;
    }
    if (difference > max_val) {
        max_val = difference;
    }

    //@ assert max_val == sum_op(A, B) || max_val == product_op(A, B) || max_val == diff_op(A, B);
    //@ assert max_val >= sum_op(A, B);
    //@ assert max_val >= product_op(A, B);
    //@ assert max_val >= diff_op(A, B);

    return max_val;
}

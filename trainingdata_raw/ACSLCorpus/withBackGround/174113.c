#include <stdbool.h>

/*@
    predicate is_nonnegative(integer x) = x >= 0;
    predicate is_within_bounds(integer x) = x >= 0 && x < 1000;
    predicate product_within_bounds(integer x) = x >= 0 && x < 1000000;
    predicate sum_within_bounds(integer x) = x >= 0 && x < 2000000;
*/

/*@
    logic integer square(integer x) = x * x;
    logic integer sum_squares_logic(integer a, integer b) = square(a) + square(b);
*/

/*@
    lemma square_nonnegative: \forall integer x; x >= 0 ==> square(x) >= 0;
    lemma square_bounded: \forall integer x; is_within_bounds(x) ==> product_within_bounds(square(x));
    lemma sum_squares_bounded: \forall integer a, b; is_within_bounds(a) && is_within_bounds(b) ==> sum_within_bounds(sum_squares_logic(a, b));
*/

/*@
    requires is_within_bounds(a) && is_within_bounds(b);
    ensures \result == sum_squares_logic(a, b);
    ensures is_nonnegative(\result);
*/
int sum_squares(int a, int b) {
    //@ assert is_within_bounds(a);
    //@ assert is_within_bounds(b);
    //@ assert product_within_bounds(a * a);
    //@ assert product_within_bounds(b * b);
    //@ assert sum_within_bounds(a * a + b * b);
    
    int result = a * a + b * b;
    return result;
}

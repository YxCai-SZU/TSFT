#include <stdint.h>

/*@
    predicate bounds(uint32_t x, uint32_t y) = x <= 8 && y <= 8;
    predicate bounds_sq(uint32_t x, uint32_t y) = x < 10 && y < 10;
    predicate bounds_sub(uint32_t x, uint32_t y) = x <= 100 && y <= 100;
    predicate bounds_single(uint32_t x) = x <= 100;
*/

/*@
    logic integer mul_bounded(integer x, integer y) = x * y;
    logic integer sq_sum(integer x, integer y) = x * x + y * y;
    logic integer sub_bounded(integer x, integer y) = x - y;
    logic integer add_constant(integer x) = x + 100;
    logic integer mixed_expr(integer x, integer y) = x - y + 100;
*/

/*@
    lemma nonlinear_arith_example:
        \forall uint32_t x, uint32_t y; bounds(x, y) ==> mul_bounded(x, y) <= 64;
    lemma sum_of_squares:
        \forall uint32_t x, uint32_t y; bounds_sq(x, y) ==> sq_sum(x, y) < 200;
    lemma subtraction_example:
        \forall uint32_t x, uint32_t y; bounds_sub(x, y) ==> sub_bounded(x, y) <= 100;
    lemma constant_addition:
        \forall uint32_t x; bounds_single(x) ==> add_constant(x) <= 200;
    lemma subtraction_and_addition:
        \forall uint32_t x, uint32_t y; bounds_sub(x, y) ==> mixed_expr(x, y) <= 200;
*/

/*@
    requires bounds(x, y);
    ensures mul_bounded(x, y) <= 64;
*/
void nonlinear_arith_example_c(uint32_t x, uint32_t y)
{
    //@ assert mul_bounded(x, y) <= 100;
    //@ assert mul_bounded(x, y) <= 64;
}

/*@
    requires bounds_sq(x, y);
    ensures sq_sum(x, y) < 200;
*/
void sum_of_squares_c(uint32_t x, uint32_t y)
{
    //@ assert sq_sum(x, y) < 200;
}

/*@
    requires bounds_sub(x, y);
    ensures sub_bounded(x, y) <= 100;
*/
void subtraction_example_c(uint32_t x, uint32_t y)
{
    //@ assert sub_bounded(x, y) <= 100;
}

/*@
    requires bounds_single(x);
    ensures add_constant(x) <= 200;
*/
void constant_addition_c(uint32_t x)
{
    //@ assert add_constant(x) <= 200;
}

/*@
    requires bounds_sub(x, y);
    ensures mixed_expr(x, y) <= 200;
*/
void subtraction_and_addition_c(uint32_t x, uint32_t y)
{
    //@ assert mixed_expr(x, y) <= 200;
}

int main() {
    return 0;
}

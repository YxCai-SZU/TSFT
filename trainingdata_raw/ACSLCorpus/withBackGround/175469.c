#include <stdint.h>

/*@
    predicate bounds(uint32_t x) = x <= 100;
    logic integer square(integer x) = x * x;
    logic integer sum_squares(integer x, integer y) = square(x) + square(y);
    lemma square_bound: \forall integer x; 0 <= x <= 100 ==> square(x) <= 10000;
    lemma sum_bound: \forall integer x, y; 0 <= x <= 100 && 0 <= y <= 100 ==> sum_squares(x, y) <= 20000;
*/

/*@
    requires bounds(x) && bounds(y);
    ensures \result == sum_squares(x, y);
    assigns \nothing;
*/
uint32_t square_sum(uint32_t x, uint32_t y)
{
    // Variable declarations at scope top
    uint32_t x_square;
    uint32_t y_square;
    uint32_t sum_of_squares;

    //@ assert x * x <= 10000;
    //@ assert y * y <= 10000;
    //@ assert x * x + y * y <= 20000;

    x_square = x * x;
    y_square = y * y;
    sum_of_squares = x_square + y_square;

    return sum_of_squares;
}

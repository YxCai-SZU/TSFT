#include <stdint.h>

/*@
    predicate is_nonnegative(integer value) = value >= 0;
    predicate is_within_bounds(integer side) = side >= 0 && side <= 1290;
    predicate product_within_i32_max(integer side) = side * side * side <= 2147483647;
*/

/*@
    logic integer cube(integer side) = side * side * side;
*/

/*@
    lemma cube_nonnegative:
        \forall integer side; is_within_bounds(side) ==> cube(side) >= 0;
    
    lemma cube_within_bounds:
        \forall integer side; is_within_bounds(side) ==> cube(side) <= 1290 * 1290 * 1290;
*/

/*@
    requires is_within_bounds(side);
    requires product_within_i32_max(side);
    ensures \result == cube(side);
    assigns \nothing;
*/
int32_t volume_cube(int32_t side)
{
    //@ assert is_within_bounds(side);
    //@ assert cube(side) >= 0;
    //@ assert cube(side) <= 1290 * 1290 * 1290;
    
    int32_t result;
    result = side * side * side;
    
    //@ assert result == cube(side);
    return result;
}

/*@
    predicate sum_of_squares_pre(uint32_t x, uint32_t y) = x < 10 && y < 10;
    predicate sum_of_squares_post(uint32_t x, uint32_t y) = x * x + y * y < 200;
*/

/*@
    lemma sum_of_squares_lemma:
        \forall uint32_t x, y; sum_of_squares_pre(x, y) ==> sum_of_squares_post(x, y);
*/

/*@
    requires sum_of_squares_pre(x, y);
    ensures sum_of_squares_post(x, y);
    assigns \nothing;
*/
void sum_of_squares(uint32_t x, uint32_t y)
{
    //@ assert sum_of_squares_pre(x, y);
    //@ assert sum_of_squares_post(x, y);
}

int main()
{
    return 0;
}

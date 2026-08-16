#include <limits.h>

/* ========== Original Function 1: compute_offset ========== */
/*@
    predicate is_valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer compute_result(integer a, integer b) =
        (2 * b <= a) ? (a - 2 * b) : 0;

    lemma result_property:
        \forall integer a, b, r;
            is_valid_range(a, b) && r == compute_result(a, b) ==>
            (r <= a && (r == a - 2 * b || r == 0));
*/

unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int result;

    //@ assert is_valid_range(a, b);
    result = a;

    if (2 * b <= result)
    {
        result -= 2 * b;
        //@ assert result == a - 2 * b;
    }
    else
    {
        result = 0;
        //@ assert result == 0;
    }

    //@ assert result == a - 2 * b || result == 0;
    return result;
}

/* ========== Original Function 2: rectangle_diagonal_squared ========== */
/*@
    predicate non_negative(integer x) = x >= 0;
    predicate within_i32_max(integer x) = x <= INT_MAX;
    predicate squares_sum_valid(integer l, integer b) = 
        l * l + b * b <= INT_MAX;
*/

/*@
    logic integer square(integer x) = x * x;
    logic integer diagonal_squared(integer l, integer b) = square(l) + square(b);
*/

/*@
    lemma squares_non_negative:
        \forall integer l, b; 
        non_negative(l) && non_negative(b) ==> 
        square(l) >= 0 && square(b) >= 0;
    
    lemma sum_within_bounds:
        \forall integer l, b;
        non_negative(l) && non_negative(b) && 
        within_i32_max(l) && within_i32_max(b) &&
        squares_sum_valid(l, b) ==>
        diagonal_squared(l, b) >= 0 && 
        diagonal_squared(l, b) <= INT_MAX;
*/

int rectangle_diagonal_squared(int l, int b) {
    //@ assert l >= 0 && b >= 0;
    //@ assert l * l + b * b <= INT_MAX;
    
    int l_square = l * l;
    int b_square = b * b;
    int sum_of_squares = l_square + b_square;
    
    //@ assert sum_of_squares == l * l + b * b;
    return sum_of_squares;
}

/* ========== Synthesized Function: process_rectangle_data ========== */
/* 
   Scenario: In a rectangle data processing system, we receive two unsigned values 
   representing a dimension index (a) and a scaling factor (b), where both must 
   be in [1,100]. We compute an offset from func, then use it as the length 
   (non-negative) for a rectangle side, along with a fixed width (b), to compute 
   the squared diagonal length. The final assertion checks that the squared diagonal 
   is non-negative and bounded by INT_MAX, ensuring no overflow.
*/

int process_rectangle_data(unsigned int a, unsigned int b) {
    unsigned int offset = func(a, b);
    //@ assert offset == a - 2 * b || offset == 0;
    //@ assert offset >= 0; // since it's unsigned, but we need it for the next step
    
    int l = (int)offset;
    int w = (int)b;
    
    //@ assert l >= 0 && w >= 0;
    //@ assert l * l + w * w <= INT_MAX;
    
    int diag_sq = rectangle_diagonal_squared(l, w);
    
    //@ assert diag_sq == l * l + w * w;
    //@ assert diag_sq >= 0;
    //@ assert diag_sq <= INT_MAX;
    
    //@ assert diag_sq >= 0 && diag_sq <= INT_MAX;
    
    return diag_sq;
}

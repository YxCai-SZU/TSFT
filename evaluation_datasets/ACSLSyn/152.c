#include <stdint.h>
#include <stdbool.h>

/* Original function 1: validates and multiplies small numbers */
/*@
    predicate is_within_bounds(integer a, integer b) =
        1 <= a && a <= 9 && 1 <= b && b <= 9;
    
    logic integer safe_product(integer a, integer b) =
        a * b;
    
    lemma product_bounds:
        \forall integer a, b;
            is_within_bounds(a, b) ==> safe_product(a, b) <= 81;
*/

int64_t func1(uint64_t a, uint64_t b)
{
    int is_within_bounds;
    uint64_t ans;
    int64_t result;

    is_within_bounds = (a < 10) && (b < 10);
    
    if (is_within_bounds)
    {
        //@ assert 1 <= a && a <= 9;
        //@ assert 1 <= b && b <= 9;
        //@ assert a * b <= 81;
        ans = a * b;
    }
    else
    {
        return -1;
    }
    
    //@ assert ans == a * b;
    
    result = (int64_t)ans;
    return result;
}

/* Original function 2: checks if four numbers are strictly increasing */
/*@
    predicate is_increasing(integer a, integer b, integer c, integer d) =
        a < b && b < c && c < d;
 */

bool func2(int a, int b, int c, int d)
{
    bool is_increasing;
    
    is_increasing = true;
    
    if (a >= b)
    {
        is_increasing = false;
    }
    
    if (b >= c)
    {
        is_increasing = false;
    }
    
    if (c >= d)
    {
        is_increasing = false;
    }
    
    //@ assert is_increasing == true <==> a < b && b < c && c < d;
    
    return is_increasing;
}

/* Synthesized function: validates a sequence of 4 small numbers and checks if they form a strictly increasing sequence of valid products */
/* Scenario: In a grid-based puzzle game, the player must select 4 cells with coordinates (x_i, y_i) where each coordinate is 1-9.
   The function validates that all coordinates are within the valid range, computes the product for each pair,
   and checks that the products form a strictly increasing sequence. */

bool check_valid_product_sequence(uint64_t x1, uint64_t y1, uint64_t x2, uint64_t y2, 
                                   uint64_t x3, uint64_t y3, uint64_t x4, uint64_t y4)
{
    int64_t p1, p2, p3, p4;
    bool result;
    
    p1 = func1(x1, y1);
    p2 = func1(x2, y2);
    p3 = func1(x3, y3);
    p4 = func1(x4, y4);
    
    /* If any product is invalid (-1), the sequence is invalid */
    if (p1 == -1 || p2 == -1 || p3 == -1 || p4 == -1)
    {
        //@ assert !(x1 < 10 && y1 < 10 && x2 < 10 && y2 < 10 && x3 < 10 && y3 < 10 && x4 < 10 && y4 < 10);
        result = false;
    }
    else
    {
        /* All products are valid; check if they form a strictly increasing sequence */
        result = func2((int)p1, (int)p2, (int)p3, (int)p4);
        
        //@ assert (result == true) <==> (p1 < p2 && p2 < p3 && p3 < p4);
    }
    
    //@ assert (result == true) ==> (x1 < 10 && y1 < 10 && x2 < 10 && y2 < 10 && x3 < 10 && y3 < 10 && x4 < 10 && y4 < 10 && p1 < p2 && p2 < p3 && p3 < p4);
    
    return result;
}

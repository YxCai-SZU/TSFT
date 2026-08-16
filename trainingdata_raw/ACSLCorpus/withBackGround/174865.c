#include <stdint.h>

/*@
    predicate positive_u64(uint64_t x) = x > 0;
    
    logic integer square(integer x) = x * x;
    
    lemma square_bounds:
        \forall integer l, b;
            l > 0 && b > 0 &&
            (l * l) + (b * b) <= 18446744073709551615 ==>
            l * l <= 18446744073709551615 &&
            b * b <= 18446744073709551615 &&
            (l * l) + (b * b) <= 18446744073709551615;
*/

/*@
    requires positive_u64(l);
    requires positive_u64(b);
    requires (unsigned long long)l * (unsigned long long)l + 
             (unsigned long long)b * (unsigned long long)b <= 18446744073709551615ULL;
    ensures \result == l * l + b * b;
    assigns \nothing;
*/
uint64_t rectangle_diagonal_squared(uint64_t l, uint64_t b)
{
    //@ assert l > 0 && l <= 18446744073709551615ULL;
    //@ assert b > 0 && b <= 18446744073709551615ULL;
    
    //@ assert l * l <= 18446744073709551615ULL;
    //@ assert b * b <= 18446744073709551615ULL;
    //@ assert l * l + b * b <= 18446744073709551615ULL;
    
    uint64_t l_squared;
    uint64_t b_squared;
    uint64_t sum_of_squares;
    
    l_squared = l * l;
    b_squared = b * b;
    sum_of_squares = l_squared + b_squared;
    
    return sum_of_squares;
}

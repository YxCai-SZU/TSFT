#include <stddef.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;

    logic integer min_val(integer x, integer y) =
        x < y ? x : y;

    logic integer max_val(integer x, integer y) =
        x > y ? x : y;
*/


size_t func(size_t a, size_t b, size_t c)
{
    size_t min_b_div_a;
    size_t result;

    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;
    
    if (b / a < c)
    {
        min_b_div_a = b / a;
    }
    else
    {
        min_b_div_a = c;
    }

    //@ assert min_b_div_a == min_val(b / a, c);
    
    if (0 > min_b_div_a)
    {
        result = 0;
    }
    else
    {
        result = min_b_div_a;
    }

    //@ assert result == max_val(0, min_b_div_a);
    //@ assert result <= min_b_div_a;
    
    //@ assert min_b_div_a <= b / a;
    //@ assert result <= b / a;
    
    //@ assert min_b_div_a <= c;
    //@ assert result <= c;
    
    //@ assert result == b / a || result == c;
    
    return result;
}

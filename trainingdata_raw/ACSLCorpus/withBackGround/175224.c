#include <stdbool.h>
#include <limits.h>

/*@
    predicate valid_range(integer a) = 1 <= a <= 100;
    
    logic integer multiply(integer a, integer b) = a * b;
    
    lemma multiply_bounds:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> 
            multiply(a, b) <= 100 * 100 && multiply(a, b) >= 1 * 1;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == multiply(a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top
    int result;
    
    //@ assert valid_range(a) && valid_range(b);
    
    //@ assert multiply(a, b) <= 100 * 100;
    
    result = a * b;
    
    //@ assert result == multiply(a, b);
    return result;
}

/*@
    requires \valid(input + (0..len-1));
    requires len >= 0;
    assigns \nothing;
    ensures \result == input;
*/
int* procon_read(int* input, int len)
{
    // Variable declarations at top
    int* result;
    
    //@ assert \valid(input + (0..len-1));
    
    result = input;
    
    //@ assert result == input;
    return result;
}

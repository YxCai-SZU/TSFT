#include <stdint.h>

/*@
    predicate valid_params(integer n, integer a) =
        1 <= n <= 100 && 0 <= a <= n * n;
    
    logic integer triangle(integer n) =
        (n * (n + 1)) / 2;
    
    lemma triangle_seven:
        triangle(7) == 28;
*/

/*@
    requires valid_params(n, a);
    ensures \result == n * n - a;
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t a)
{
    // Variable declarations at scope top
    int32_t result;
    
    // Precondition verification
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= a <= n * n;
    
    // Ensure n*n doesn't overflow int32_t range
    //@ assert n * n <= 10000;
    
    // Ensure subtraction is safe
    //@ assert n * n >= a;
    
    result = n * n - a;
    
    // Postcondition verification
    //@ assert result == n * n - a;
    
    return result;
}

/*@
    lemma test_triangle:
        triangle(7) == 28;
*/

int main()
{
    return 0;
}

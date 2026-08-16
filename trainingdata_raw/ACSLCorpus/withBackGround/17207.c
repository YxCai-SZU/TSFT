#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer calculate_product(integer r) = 2 * r * 314;
    
    logic integer expected_result(integer r) = calculate_product(r) / 100;
*/

/*@
    requires valid_range(r);
    ensures \result == expected_result(r);
*/
int64_t func(int64_t r)
{
    // Variable declarations
    int64_t pi = 314;
    int64_t two = 2;
    int64_t hundred = 100;
    int64_t product;
    int64_t result = 0;
    int64_t remainder;
    
    // Calculate product
    product = two * r * pi;
    
    // Initialize remainder
    remainder = product;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314;
        loop invariant two == 2;
        loop invariant hundred == 100;
        loop invariant result * hundred + remainder == product;
        loop invariant 0 <= result;
        loop invariant 0 <= remainder;
        loop invariant remainder < hundred + product;
        loop assigns result, remainder;
    */
    while (remainder >= hundred)
    {
        //@ assert remainder >= hundred;
        
        result += 1;
        remainder -= hundred;
        
        //@ assert result * hundred + remainder == product;
    }
    
    //@ assert result == expected_result(r);
    return result;
}

int main()
{
    return 0;
}

#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer calculate_product(integer pi, integer r) = 2 * pi * r;
    
    logic integer expected_result(integer pi, integer r, integer precision) = 
        2 * pi * r / precision;
*/

/*@
    requires valid_range(r);
    ensures \result == expected_result(3142, r, 1000);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t precision_factor = 1000;
    int64_t pi = 3142;
    int64_t product;
    int64_t result = 0;
    int64_t remainder;
    
    //@ assert valid_range(r);
    //@ assert pi == 3142;
    
    product = 2 * pi * r;
    
    //@ assert product == calculate_product(pi, r);
    //@ assert product <= 2 * 3142 * 100;
    
    remainder = product;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant result * precision_factor + remainder == product;
        loop invariant 0 <= result;
        loop invariant result <= product / precision_factor;
        loop invariant 0 <= remainder;
        loop invariant remainder <= product;
        loop assigns result, remainder;
        loop variant remainder;
    */
    while (remainder >= precision_factor)
    {
        result += 1;
        remainder -= precision_factor;
    }
    
    //@ assert result * precision_factor + remainder == product;
    //@ assert remainder < precision_factor;
    //@ assert result == expected_result(pi, r, precision_factor);
    
    return result;
}

/*@
    lemma product_bound: \forall integer r; valid_range(r) ==> 
        calculate_product(3142, r) <= 2 * 3142 * 100;
*/

int main(void)
{
    return 0;
}

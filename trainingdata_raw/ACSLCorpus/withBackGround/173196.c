#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer calculate_product(integer r) = 2 * 314159 * r;
    
    logic integer calculate_result(integer r) = 
        calculate_product(r) / 100000;
    
    lemma product_bounds:
        \forall integer r; valid_range(r) ==> 
            2 * 314159 * 1 <= calculate_product(r) <= 2 * 314159 * 100;
*/

/*@
    requires valid_range(r);
    ensures \result == calculate_result(r);
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t precision_factor;
    int64_t pi;
    int64_t product;
    int64_t result;
    int64_t remainder;
    
    precision_factor = 100000;
    pi = 314159;
    
    //@ assert 2 * pi * r == calculate_product(r);
    product = 2 * pi * r;
    
    result = 0;
    remainder = product;
    
    /*@
        loop invariant result * precision_factor + remainder == product;
        loop invariant 0 <= result;
        loop invariant 0 <= remainder;
        loop assigns result, remainder;
        loop variant remainder;
    */
    while (remainder >= precision_factor) {
        result += 1;
        remainder -= precision_factor;
    }
    
    //@ assert result * precision_factor + remainder == product;
    return result;
}

int main() {
    return 0;
}

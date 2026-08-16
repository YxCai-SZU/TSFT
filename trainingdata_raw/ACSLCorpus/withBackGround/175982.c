#include <stdbool.h>
#include <stdint.h>

/*@
    predicate in_range(integer a) = 1 <= a <= 10000;
    
    logic integer product_mod_2(integer a, integer b) = (a * b) % 2;
    
    lemma product_bound: \forall integer a, b; in_range(a) && in_range(b) ==> a * b <= 10000 * 10000;
*/

/*@
    requires in_range(a) && in_range(b);
    ensures \result == (product_mod_2(a, b) != 0);
*/
bool func(uint64_t a, uint64_t b)
{
    // Variable declarations
    uint64_t product;
    bool is_odd;
    uint64_t abs_product;
    uint64_t remainder;
    
    product = a * b;
    is_odd = false;
    abs_product = product;
    
    //@ assert product <= 10000 * 10000;
    
    // Implementing abs without using the abs function
    if (product >= UINT64_MAX / 2)
    {
        abs_product = UINT64_MAX - product;
    }
    
    remainder = abs_product;
    
    /*@
        loop invariant 0 <= remainder <= abs_product;
        loop invariant abs_product <= product;
        loop invariant remainder % 2 == abs_product % 2;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2)
    {
        remainder -= 2;
    }
    
    //@ assert remainder == abs_product % 2;
    
    if (remainder == 1)
    {
        is_odd = true;
    }
    
    return is_odd;
}

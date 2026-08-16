#include <stdbool.h>
#include <stdint.h>

/*@ predicate in_range(integer a, integer b) =
      a >= 1 && a <= 10000 && b >= 1 && b <= 10000;
*/

/*@ logic integer safe_product(integer a, integer b) =
      a * b;
*/

/*@ lemma product_bounds: \forall integer a, b;
      in_range(a, b) ==> safe_product(a, b) >= 0 && safe_product(a, b) <= 100000000;
*/

/*@
    requires in_range(a, b);
    ensures \result == (safe_product(a, b) % 2 == 0);
    assigns \nothing;
*/
bool func(uint64_t a, uint64_t b)
{
    // Variable declarations at scope top
    uint64_t product;
    bool result;

    //@ assert a >= 1 && a <= 10000;
    //@ assert b >= 1 && b <= 10000;
    
    //@ assert safe_product(a, b) >= 0 && safe_product(a, b) <= 100000000;
    
    product = a * b;
    //@ assert product == safe_product(a, b);
    
    result = (product % 2 == 0);
    //@ assert result == (safe_product(a, b) % 2 == 0);
    
    return result;
}

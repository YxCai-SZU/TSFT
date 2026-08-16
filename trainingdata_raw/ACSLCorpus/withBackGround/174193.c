#include <stdbool.h>

/*@
    predicate bounds(integer n, integer m) =
        1 <= n <= 10000 && 1 <= m <= 10000;

    logic integer product(integer n, integer m) = n * m;

    lemma product_bound:
        \forall integer n, m; bounds(n, m) ==> product(n, m) <= 100000000;

    lemma mod_even_property:
        \forall integer n, m; bounds(n, m) ==> 
            (product(n, m) % 2 == 0) == (n * m % 2 == 0);
*/

/*@
    requires bounds(n, m);
    ensures \result == (n * m % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    // Variable declarations at scope top
    bool result;
    unsigned long long product;

    //@ assert bounds(n, m);
    
    // Calculate product with safe bounds
    product = (unsigned long long)n * (unsigned long long)m;
    
    //@ assert product <= 100000000;
    
    result = (product % 2 == 0);
    
    //@ assert result == (n * m % 2 == 0);
    
    return result;
}

#include <stdbool.h>

/*@
    predicate is_valid_params(integer a, integer b) =
        1 <= a <= 10000 && 1 <= b <= 10000;

    logic integer safe_product(integer a, integer b) = a * b;

    lemma product_bound:
        \forall integer a, b;
            is_valid_params(a, b) ==> safe_product(a, b) <= 100000000;
*/

/*@
    requires is_valid_params(a, b);
    ensures \result == (safe_product(a, b) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    // Variable declarations at top
    unsigned long long c;
    bool result;

    //@ assert is_valid_params(a, b);
    
    //@ assert a <= 10000 && b <= 10000;
    //@ assert a * b <= 10000 * 10000;
    
    c = a * b;
    result = (c % 2 == 0);
    
    //@ assert result == ((a * b) % 2 == 0);
    return result;
}

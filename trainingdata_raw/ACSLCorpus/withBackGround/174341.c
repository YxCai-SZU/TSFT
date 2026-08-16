#include <stdbool.h>

/*@
    predicate is_odd(integer x) = (x % 2) != 0;
    logic integer product_mod_2(integer a, integer b) = (a * b) % 2;
    lemma product_mod_2_odd: \forall integer a, b; product_mod_2(a, b) != 0 ==> is_odd(a * b);
*/

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == ((a * b) % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at the top
    unsigned int product;
    unsigned int product_div_2;
    unsigned int product_mod_2;
    bool result;

    //@ assert a <= 10000;
    //@ assert b <= 10000;
    //@ assert a * b <= 10000 * 10000;

    product = a * b;
    product_div_2 = product / 2;
    product_mod_2 = product - (product_div_2 * 2);
    
    //@ assert product_mod_2 == product % 2;
    
    result = (product_mod_2 != 0);
    return result;
}

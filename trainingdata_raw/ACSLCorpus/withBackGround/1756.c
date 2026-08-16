/*@
    predicate bounds(integer e1, integer e2, integer e3) =
        1 <= e1 && e1 <= 10 &&
        1 <= e2 && e2 <= 10 &&
        1 <= e3 && e3 <= 10;

    logic integer product(integer e1, integer e2, integer e3) = e1 * e2 * e3;

    lemma product_bound:
        \forall integer e1, e2, e3;
        bounds(e1, e2, e3) ==> product(e1, e2, e3) <= 1000;
*/

#include <stdbool.h>

/*@
    requires 1 <= e1 && e1 <= 10;
    requires 1 <= e2 && e2 <= 10;
    requires 1 <= e3 && e3 <= 10;
    ensures \result == (e1 * e2 * e3 == 175);
*/
bool func(int e1, int e2, int e3)
{
    // Variable declarations at top of scope
    bool result;
    int intermediate_product;
    int final_product;

    //@ assert 1 <= e1 && e1 <= 10;
    //@ assert 1 <= e2 && e2 <= 10;
    //@ assert 1 <= e3 && e3 <= 10;
    
    intermediate_product = e1 * e2;
    //@ assert intermediate_product <= 100;
    
    final_product = intermediate_product * e3;
    //@ assert final_product <= 1000;
    
    result = (final_product == 175);
    return result;
}

#include <stdbool.h>

/*@
    predicate product_in_range(integer x, integer y) =
        1 <= x <= 100 && 1 <= y <= 100 ==> x * y <= 10000;

    lemma product_range_lemma:
        \forall integer x, y;
            1 <= x <= 100 && 1 <= y <= 100 ==> x * y <= 10000;
*/

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == ((x * y) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned long x, unsigned long y)
{
    // Variable declarations at scope top
    bool result;
    unsigned long product;

    //@ assert 1 <= x <= 100;
    //@ assert 1 <= y <= 100;
    
    //@ assert product_in_range(x, y);
    
    product = x * y;
    //@ assert product <= 10000;
    
    result = (product % 2 == 0);
    return result;
}

#ifdef TEST
#include <assert.h>

int main() {
    // Test cases
    bool r1 = func(2, 3);
    //@ assert r1 == true;
    assert(r1 == true);
    
    bool r2 = func(3, 5);
    //@ assert r2 == true;
    assert(r2 == true);
    
    return 0;
}
#endif

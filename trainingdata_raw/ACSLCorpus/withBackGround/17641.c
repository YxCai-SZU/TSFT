#include <stdint.h>
/*@
    predicate in_range(integer v) = 1 <= v <= 10;

    logic integer product(integer a, integer b, integer c) = a * b * c;

    lemma product_bound:
        \forall integer a, b, c;
            in_range(a) && in_range(b) && in_range(c) ==> product(a,b,c) <= 1000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == product(a,b,c) || \result == -1;
    ensures \result >= 0 ==> \result == product(a,b,c);
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    // Variable declarations at top of scope
    uint32_t product;
    int32_t result;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert a * b <= 100;
    //@ assert a * b * c <= 1000;

    product = a * b * c;
    
    if (product <= 1000) {
        result = (int32_t)product;
    } else {
        result = -1;
    }
    
    return result;
}

int main()
{
    return 0;
}

#include <stdint.h>

/*@
    predicate bounds(uint32_t x) = x <= 1000;
    logic integer product(integer a, integer b) = a * b;
    logic integer sum(integer a, integer b) = a + b;
    lemma product_bound: \forall integer x, y; 0 <= x <= 1000 && 0 <= y <= 1000 ==> product(x, y) <= 1000000;
    lemma sum_bound: \forall integer a, b, c, d; 
        0 <= a <= 1000 && 0 <= b <= 1000 && 0 <= c <= 1000 && 0 <= d <= 1000 ==> 
        product(a, b) + product(c, d) <= 2000000;
*/

/*@
    requires bounds(x) && bounds(y) && bounds(z) && bounds(w);
    ensures \result == (uint32_t)(x * y + z * w);
    assigns \nothing;
*/
uint32_t nonlinear_arith_example(uint32_t x, uint32_t y, uint32_t z, uint32_t w)
{
    //@ assert x <= 1000 && y <= 1000 && z <= 1000 && w <= 1000;
    //@ assert 0 <= x && 0 <= y && 0 <= z && 0 <= w;
    //@ assert product(x, y) <= 1000000;
    //@ assert product(z, w) <= 1000000;
    //@ assert product(x, y) + product(z, w) <= 2000000;
    
    uint32_t result;
    result = x * y + z * w;
    
    //@ assert result == (uint32_t)(x * y + z * w);
    return result;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}

#include <stdint.h>
/*@
    predicate valid_range(integer v) = 0 <= v <= 65535;

    logic integer multiply_add(integer a, integer b, integer c) = a * b + c;

    lemma multiplication_bounds:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==> a * b <= 4294967295;

    lemma addition_bounds:
        \forall integer a, b, c;
        valid_range(a) && valid_range(b) && valid_range(c) && a * b <= 4294967295 ==>
        multiply_add(a, b, c) <= 4294967295;

    lemma associativity_example:
        \forall integer x, y, z;
        x > 0 && y > 0 && z > 0 ==> x * (y * z) == (x * y) * z;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == multiply_add(a, b, c);
    ensures \result <= 4294967295;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c) {
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert a * b <= 4294967295;
    //@ assert multiply_add(a, b, c) <= 4294967295;
    
    uint32_t ans = a * b + c;
    //@ assert ans == multiply_add(a, b, c);
    //@ assert ans <= 4294967295;
    return ans;
}

int main() {
    return 0;
}

#include <stdint.h>

/*@
    predicate valid_x(integer x) = 1 <= x <= 100000;

    logic integer div100(integer x) = x / 100;
    logic integer mod100(integer x) = x % 100;

    lemma div_mod_property:
        \forall integer x; x >= 0 ==> x == div100(x) * 100 + mod100(x);
*/

/*@
    requires valid_x(x);
    ensures \result == 0 || (\result == 1 && x / 100 <= 5);
*/
int32_t func(uint32_t x) {
    uint32_t n;
    uint32_t m;
    uint32_t quotient;
    uint32_t remainder;
    uint32_t n_direct;
    uint32_t m_direct;
    int32_t ret;

    //@ assert valid_x(x);
    
    n = x / 100;
    m = x % 100;
    
    quotient = 0;
    remainder = x;
    
    /*@
        loop invariant 1 <= x <= 100000;
        loop invariant 0 <= quotient <= x / 100;
        loop invariant remainder == x - quotient * 100;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
    */
    while (remainder >= 100) {
        //@ assert remainder >= 100;
        quotient = quotient + 1;
        remainder = remainder - 100;
    }
    
    n_direct = quotient;
    m_direct = remainder;
    
    //@ assert n_direct == x / 100;
    //@ assert m_direct == x % 100;
    
    if (n_direct <= 5 && (m_direct / 5) <= n_direct) {
        ret = 1;
    } else {
        ret = 0;
    }
    
    //@ assert ret == 0 || (ret == 1 && x / 100 <= 5);
    return ret;
}

int main() {
    return 0;
}

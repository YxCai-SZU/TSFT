#include <stdint.h>

/*@
    requires (0 <= (a) <= 10000) && (0 <= (b) <= 10000) && (0 <= (c) <= 10000) && (0 <= (d) <= 10000);
    ensures \result == a * b || \result == c * d;
    ensures \result >= a * b;
    ensures \result >= c * d;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    // Variable declarations at top
    uint32_t product1;
    uint32_t product2;
    uint32_t result;
    
    //@ assert (0 <= (a) <= 10000);
    //@ assert (0 <= (b) <= 10000);
    //@ assert a * b <= 10000 * 10000;
    
    //@ assert (0 <= (c) <= 10000);
    //@ assert (0 <= (d) <= 10000);
    //@ assert c * d <= 10000 * 10000;
    
    product1 = a * b;
    product2 = c * d;
    
    //@ assert product1 >= a * b;
    //@ assert product2 >= c * d;
    
    if (product1 > product2) {
        result = product1;
        //@ assert result == a * b;
        //@ assert result >= a * b;
        //@ assert result >= c * d;
    } else {
        result = product2;
        //@ assert result == c * d;
        //@ assert result >= a * b;
        //@ assert result >= c * d;
    }
    
    //@ assert result == a * b || result == c * d;
    return result;
}

int main()
{
    return 0;
}

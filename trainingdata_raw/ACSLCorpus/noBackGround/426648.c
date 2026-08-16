#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures ((\result) == (int32_t)((a) * (b)) || (\result) == -1);
    ensures (((a) * (b) <= 1000) ==> (\result) == (int32_t)((a) * (b)));
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    uint32_t product;
    int32_t result;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    
    //@ assert ((a) * (b) <= 10000);
    
    product = a * b;
    
    if (product <= 1000) {
        //@ assert product <= 1000;
        //@ assert product >= 1;
        result = (int32_t)product;
    } else {
        result = -1;
    }
    
    //@ assert ((result) == (int32_t)((a) * (b)) || (result) == -1);
    //@ assert (((a) * (b) <= 1000) ==> (result) == (int32_t)((a) * (b)));
    return result;
}

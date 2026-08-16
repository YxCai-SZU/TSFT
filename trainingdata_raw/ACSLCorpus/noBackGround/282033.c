#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (x / 100) * 5 >= x % 100;
    ensures \result == 0 ==> (x / 100) * 5 < x % 100;
*/
int32_t func(uint32_t x)
{
    uint32_t y;
    uint32_t z;
    uint32_t pay;
    int32_t res;

    //@ assert (1 <= (x) <= 100000);
    y = x / 100;
    z = x % 100;
    
    //@ assert y == ((x) / 100);
    //@ assert z == ((x) % 100);
    
    //@ assert 0 <= y * 5 <= 5000;
    pay = y * 5;
    
    if (pay >= z) {
        res = 1;
        //@ assert pay >= z;
    } else {
        res = 0;
        //@ assert pay < z;
    }
    
    return res;
}

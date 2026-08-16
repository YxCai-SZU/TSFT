#include <stdint.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (a) <= 255 && (b) <= 255 && (a) >= (b));
    ensures \result == a - b;
    assigns \nothing;
*/
uint8_t func_subtraction(uint8_t a, uint8_t b)
{
    //@ assert ((a) >= 0 && (b) >= 0 && (a) <= 255 && (b) <= 255 && (a) >= (b));
    //@ assert a - b >= 0;
    //@ assert a - b <= 255;
    
    uint8_t ret;
    ret = a - b;
    
    //@ assert ret == a - b;
    return ret;
}

int main()
{
    return 0;
}

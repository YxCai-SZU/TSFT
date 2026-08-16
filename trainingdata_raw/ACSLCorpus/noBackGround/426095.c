#include <stdint.h>

/*@
    requires (-16 <= (x1) && (x1) < 16);
    ensures \result == (8 * (x1));
    assigns \nothing;
*/
int8_t octuple(int8_t x1)
{
    int8_t x2;
    int8_t x4;
    int8_t result;
    
    //@ assert (-16 <= (x1) && (x1) < 16);
    x2 = x1 + x1;
    //@ assert x2 == x1 + x1;
    x4 = x2 + x2;
    //@ assert x4 == x2 + x2;
    result = x4 + x4;
    //@ assert result == x4 + x4;
    //@ assert result == (8 * (x1));
    return result;
}

/*@
    requires (-16 <= (x1) && (x1) < 16);
    ensures \result == (8 * (x1));
    assigns \nothing;
*/
int8_t nonstricthyperoctuple(int8_t x1)
{
    int8_t x2;
    int8_t x4;
    int8_t x8;
    
    //@ assert (-16 <= (x1) && (x1) < 16);
    x2 = x1 + x1;
    //@ assert x2 == x1 + x1;
    x4 = x2 + x2;
    //@ assert x4 == x2 + x2;
    x8 = x4 + x4;
    //@ assert x8 == x4 + x4;
    //@ assert x8 == (8 * (x1));
    return x8;
}

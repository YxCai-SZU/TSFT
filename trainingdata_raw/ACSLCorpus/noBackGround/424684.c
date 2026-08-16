#include <stdint.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= a - b + c;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c)
{
    int32_t result;
    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    
    if (c > a - b) {
        result = a - b + c;
    } else {
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result <= a - b + c;
    return result;
}

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= a - b + c;
    assigns \nothing;
*/
int32_t func2(int32_t a, int32_t b, int32_t c)
{
    int32_t result;
    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    
    if (c > a - b) {
        //@ assert a - b + c >= 0;
        //@ assert a - b + c <= 40;
        result = a - b + c;
    } else {
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result <= a - b + c;
    return result;
}

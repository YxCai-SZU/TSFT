#include <stdint.h>

/*@
  requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
  ensures ((\result) == ((a) * (b) + 1) || (\result) == -1);
*/
int32_t func(uint32_t a, uint32_t b)
{
    //@ assert a * b <= 10000;
    int32_t result = (int32_t)(a * b + 1);
    uint32_t sum = a + b;
    uint32_t i = 0;
    
    /*@ loop invariant 0 <= i <= 4;
        loop invariant sum >= 0;
        loop invariant sum <= a + b;
        loop invariant ((result) == ((a) * (b) + 1) || (result) == -1);
        loop assigns result, sum, i;
        loop variant 4 - i;
    */
    while (i < 4) {
        if (sum <= 1) {
            result = -1;
            break;
        }
        sum = sum / 2;
        i = i + 1;
    }
    return result;
}

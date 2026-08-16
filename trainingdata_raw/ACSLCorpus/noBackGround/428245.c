#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (((n) % 100) * 21) < n;
    ensures \result == 0 ==> (((n) % 100) * 21) >= n;
*/
int32_t func(uint32_t n) {
    int32_t result;
    uint32_t temp;

    //@ assert (1 <= (n) && (n) <= 100000);
    temp = (n % 100) * 21;

    if (temp < n) {
        //@ assert temp < n;
        result = 1;
    } else {
        //@ assert temp >= n;
        result = 0;
    }

    //@ assert result == 1 || result == 0;
    //@ assert result == 1 ==> temp < n;
    //@ assert result == 0 ==> temp >= n;
    return result;
}

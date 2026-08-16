#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
    ensures 1 <= \result <= 100;
*/
uint64_t func(uint64_t a, uint64_t b)
{
    uint64_t sum;
    uint64_t avg;
    uint64_t result;

    sum = a + b;
    avg = sum / 2;
    
    //@ assert sum == a + b;
    //@ assert avg == sum / 2;
    
    if (sum % 2 == 1) {
        result = avg + 1;
        //@ assert result == avg + 1;
    } else {
        result = avg;
        //@ assert result == avg;
    }
    
    //@ assert result == (((a) + (b) + 1) / 2);
    //@ assert 1 <= result <= 100;
    
    return result;
}

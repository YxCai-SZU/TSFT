#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * ((r)) * 314) / 100);
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t circumference;
    int64_t result = 0;
    int64_t remainder;
    const int64_t divisor = 100;
    int64_t count = 0;
    
    //@ assert (1 <= (r) <= 100);
    circumference = 2 * r * 314;
    //@ assert circumference == 2 * r * 314;
    
    remainder = circumference;
    
    /*@
        loop invariant 0 <= count <= ((2 * ((r)) * 314) / 100);
        loop invariant remainder == circumference - count * divisor;
        loop assigns remainder, count;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        //@ assert remainder >= divisor;
        remainder -= divisor;
        count += 1;
    }
    
    result = count;
    //@ assert result == ((2 * ((r)) * 314) / 100);
    
    return result;
}

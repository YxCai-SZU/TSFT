#include <stdint.h>

/*@
  requires 1 <= a <= 20 && 1 <= b <= 20;
  ensures (a <= 9 && b <= 9 ==> \result == (int64_t)(a * b)) &&
          (a > 9 || b > 9 ==> \result == -1);
*/
int64_t func(uint64_t a, uint64_t b)
{
    // Variable declarations at top of scope
    int64_t result;
    
    if (a > 9 || b > 9) {
        //@ assert (((a) > 9) || ((b) > 9));
        result = -1;
        return result;
    }
    
    //@ assert (((a) <= 9) && ((b) <= 9));
    //@ assert ((a) * (b)) <= 81;
    
    result = (int64_t)(a * b);
    return result;
}

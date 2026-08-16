#include <stdint.h>

/*@
  requires 1 <= n <= 20;
  requires 1 <= m <= 20;
  ensures (n < 10 && m < 10) ==> \result == n * m;
  ensures (n >= 10 || m >= 10) ==> \result == -1;
*/
int32_t func(uint32_t n, uint32_t m) {
    int32_t result;
    
    if (n < 10 && m < 10) {
        //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20 && (n) < 10 && (m) < 10);
        //@ assert ((n) * (m)) <= 100;
        result = (int32_t)(n * m);
    } else {
        //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20 && ((n) >= 10 || (m) >= 10));
        result = -1;
    }
    
    return result;
}

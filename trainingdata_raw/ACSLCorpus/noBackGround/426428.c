#include <stdint.h>

/*@
  requires (1 <= (r) && (r) <= 100);
  ensures \result == 3 * r * r;
  ensures \result >= 0;
*/
int64_t func(int64_t r) {
    // Variable declarations at scope top
    int64_t ans;
    
    //@ assert r >= 1 && r <= 100;
    //@ assert 3 * r >= 3;
    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r <= 30000;
    
    ans = 3 * r * r;
    return ans;
}

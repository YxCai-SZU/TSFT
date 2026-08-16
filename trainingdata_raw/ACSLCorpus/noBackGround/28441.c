#include <stdint.h>

/*@
  requires (1 <= (B) && (B) <= (A) && (A) <= 20 &&
      1 <= (C) && (C) <= 20);
  ensures \result >= 0 && \result <= C;
*/
int64_t func(int64_t A, int64_t B, int64_t C)
{
    int64_t ans;
    
    //@ assert (1 <= (B) && (B) <= (A) && (A) <= 20 &&       1 <= (C) && (C) <= 20);
    ans = C - A + B;
    
    //@ assert ans == ((C) - (A) + (B));
    
    if (ans > 0) {
        //@ assert ans > 0 && ans <= C;
        return ans;
    } else {
        //@ assert ans <= 0;
        return 0;
    }
}

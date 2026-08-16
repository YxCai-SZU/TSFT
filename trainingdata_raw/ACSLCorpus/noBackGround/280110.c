#include <stdint.h>
#include <limits.h>

/*@
  requires (\valid((v)) && \valid((v)+1) && \valid((v)+2) &&
      1 <= (v)[0] <= 20 &&
      1 <= (v)[1] <= 20 &&
      1 <= (v)[2] <= 20);
  ensures \result >= 0;
  ensures \result <= v[0] + v[1] || \result <= v[1] + v[2] || \result <= v[2] + v[0];
*/
int32_t func(int32_t *v) {
    int32_t ans;
    int32_t tmp1;
    int32_t tmp2;
    int32_t tmp3;
    
    ans = INT32_MIN;
    
    tmp1 = v[0] + v[1];
    //@ assert tmp1 >= 0;
    ans = (ans > tmp1) ? ans : tmp1;
    
    tmp2 = v[1] + v[2];
    //@ assert tmp2 >= 0;
    ans = (ans > tmp2) ? ans : tmp2;
    
    tmp3 = v[2] + v[0];
    //@ assert tmp3 >= 0;
    ans = (ans > tmp3) ? ans : tmp3;
    
    //@ assert ans >= 0;
    //@ assert ans == tmp1 || ans == tmp2 || ans == tmp3;
    
    return ans;
}

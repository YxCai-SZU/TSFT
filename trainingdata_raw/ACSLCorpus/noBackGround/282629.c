#include <stdbool.h>
#include <stdint.h>

/*@
  requires 
      ((len) >= 1 && (len) <= 100) &&
      ((k) >= 1 && (k) <= 1000000000) &&
      \valid(s + (0 .. len-1)) &&
      (\forall integer j; 0 <= j < (len) ==> (((s)[j]) >= 1 && ((s)[j]) <= 1000000000));
  ensures
      \result >= 0 &&
      \result <= len;
*/
uint64_t func(int64_t* s, uint64_t len, uint64_t k)
{
    uint64_t ans = 0;
    uint64_t i = 0;
    
    /*@ loop invariant 
          0 <= i <= len &&
          ((ans) >= 0 && (ans) <= (i)) &&
          (\forall integer j; 0 <= j < (i) ==> ((s)[j] >= (k) ==> (ans) >= 1));
      loop assigns 
          ans, i;
      loop variant 
          len - i;
    */
    while (i < len) {
        int64_t ss = s[i];
        
        //@ assert ((ss) >= 1 && (ss) <= 1000000000);
        
        if (ss >= (int64_t)k) {
            ans += 1;
        }
        i += 1;
    }
    return ans;
}

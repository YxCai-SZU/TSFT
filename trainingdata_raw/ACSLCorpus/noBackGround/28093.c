#include <stdbool.h>
#include <stdint.h>

/*@
  requires (1 <= (n) && (n) <= 200000);
  requires (\valid((a) + (0 .. (n)-1)));
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 1000000000);
  ensures \result >= 0;
  ensures \result <= n;
*/
int32_t func(int64_t n, int64_t* a) {
    int32_t c = 0;
    int64_t p = 0;
    int64_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= c <= i;
      loop invariant p <= i;
      loop invariant (1 <= (n) && (n) <= 200000);
      loop invariant (\valid((a) + (0 .. (n)-1)));
      loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 1000000000);
      loop assigns c, p, i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if ((a[i] & 1) == 0) {
            c = c + 1;
        }
        //@ assert 0 <= c <= i+1;
        if ((a[i] & (int64_t)c) == 0) {
            p = i + 1;
        }
        //@ assert p <= i+1;
        i = i + 1;
    }
    //@ assert i == n;
    //@ assert 0 <= c <= n;
    return c;
}

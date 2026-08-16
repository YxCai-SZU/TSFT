#include <stddef.h>

/*@
  requires \valid(p + (0 .. n-1));
  requires n >= 1 && n <= 200000;
  requires ((n) >= 1 && (n) <= 200000 &&
      \forall size_t i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (int)(n) &&
      \forall size_t i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
  ensures \result >= 1 && \result <= (int)n;
  assigns \nothing;
*/
int func(size_t n, int *p) {
    int ans = 1;
    int m = p[0];
    size_t index = 1;
    
    /*@
      loop invariant 1 <= index <= n;
      loop invariant 1 <= ans <= (int)index;
      loop invariant m >= 1 && m <= (int)n;
      loop assigns ans, m, index;
      loop variant n - index;
    */
    while (index < n) {
        //@ assert p[index] >= 1 && p[index] <= (int)n;
        if (m >= p[index]) {
            ans += 1;
            m = p[index];
        }
        index += 1;
    }
    return ans;
}

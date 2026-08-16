#include <stdbool.h>
#include <stddef.h>

/*@
  requires 2 <= n <= 100000;
  requires 2 <= m <= 100000;
  requires \valid(a + (0..n-1));
  requires \valid(b + (0..m-1));
  requires (\forall size_t i, j; 0 <= i < j < (n) ==> (a)[i] != (a)[j]);
  requires (\forall size_t i, j; 0 <= i < j < (m) ==> (b)[i] != (b)[j]);
  requires (\forall size_t i; 0 <= i < (n) ==> (a)[i] >= 0);
  requires (\forall size_t i; 0 <= i < (m) ==> (b)[i] >= 0);
  ensures \result >= 0;
*/
long func(size_t n, size_t m, const long *a, const long *b) {
    long ans = 0;
    size_t index = 0;
    /*@
      loop invariant 0 <= index <= m;
      loop invariant ans >= 0;
      loop invariant ans <= index;
      loop assigns ans, index;
      loop variant m - index;
    */
    while (index < m) {
        long b_elem = b[index];
        bool found = false;
        size_t a_index = 0;
        /*@
          loop invariant 0 <= a_index <= n;
          loop invariant !found ==> (\forall size_t k; 0 <= k < a_index ==> a[k] != b_elem);
          loop assigns a_index, found;
          loop variant n - a_index;
        */
        while (a_index < n) {
            if (a[a_index] == b_elem) {
                found = true;
                break;
            }
            a_index++;
        }
        if (found) {
            ans++;
        }
        index++;
    }
    return ans;
}

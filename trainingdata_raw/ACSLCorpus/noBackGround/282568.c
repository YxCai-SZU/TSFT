#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) >= 1 && (n) <= 100000 &&
      \valid((aa) + (0 .. (n)-1)) &&
      \forall integer j; 0 <= j < (n) ==> (aa)[j] >= 1 && (aa)[j] <= 1000000000);
  ensures ((\result) >= 0 || (\result) == -1);
*/
int func(size_t n, int *aa) {
    size_t m = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant m <= i;
      loop invariant ((n) >= 1 && (n) <= 100000 &&
      \valid((aa) + (0 .. (n)-1)) &&
      \forall integer j; 0 <= j < (n) ==> (aa)[j] >= 1 && (aa)[j] <= 1000000000);
      loop invariant m <= n;
      loop assigns i, m;
      loop variant n - i;
    */
    while (i < n) {
        if (aa[i] % 2 == 0) {
            m += 1;
        }
        i += 1;
    }

    if (m == n || m == 0) {
        //@ assert ((0) >= 0 || (0) == -1);
        return 0;
    } else {
        size_t cnt = 0;
        i = 0;
        
        /*@
          loop invariant 0 <= i <= n;
          loop invariant cnt <= i;
          loop invariant ((n) >= 1 && (n) <= 100000 &&
      \valid((aa) + (0 .. (n)-1)) &&
      \forall integer j; 0 <= j < (n) ==> (aa)[j] >= 1 && (aa)[j] <= 1000000000);
          loop invariant cnt <= n;
          loop assigns i, cnt;
          loop variant n - i;
        */
        while (i < n) {
            if (aa[i] % 2 != 0) {
                cnt += 1;
            }
            i += 1;
        }

        bool is_even = true;
        i = 0;
        
        /*@
          loop invariant 0 <= i <= n;
          loop invariant ((n) >= 1 && (n) <= 100000 &&
      \valid((aa) + (0 .. (n)-1)) &&
      \forall integer j; 0 <= j < (n) ==> (aa)[j] >= 1 && (aa)[j] <= 1000000000);
          loop invariant cnt <= n;
          loop invariant cnt >= 0;
          loop assigns i, cnt, is_even;
          loop variant n - i;
        */
        while (i < n) {
            if (aa[i] % 2 == 0) {
                if (cnt > 0) {
                    cnt -= 1;
                } else {
                    is_even = false;
                }
            }
            i += 1;
        }

        if (is_even) {
            //@ assert (((int)cnt) >= 0 || ((int)cnt) == -1);
            return (int)cnt;
        } else {
            //@ assert ((-1) >= 0 || (-1) == -1);
            return -1;
        }
    }
}

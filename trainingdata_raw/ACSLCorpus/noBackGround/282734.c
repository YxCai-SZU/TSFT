#include <stdbool.h>
#include <stddef.h>

/*@
  requires (1 <= (n) && (n) <= 100 &&
     1 <= (x) && (x) <= 10000 &&
     \valid((l) + (0 .. (n)-1)) &&
     \forall integer i; 0 <= i < (n) ==> 1 <= (l)[i] && (l)[i] <= 100);
  ensures \result >= 1;
  ensures \result <= n + 1;
  assigns \nothing;
*/
size_t func(size_t n, long long x, const long long *l) {
    long long d = 0;
    size_t count = 1;
    size_t i = 0;
    
    /*@
      loop invariant (0 <= (i) && (i) <= (n) &&
     1 <= (n) && (n) <= 100 &&
     1 <= (x) && (x) <= 10000 &&
     \valid((l) + (0 .. (n)-1)) &&
     \forall integer j; 0 <= j < (n) ==> 1 <= (l)[j] && (l)[j] <= 100 &&
     (d) >= 0 &&
     (d) <= (i) * 100 &&
     (count) >= 1 &&
     (count) <= (i) + 1 &&
     ((i) > 0 ==> (d) <= (x) + 100));
      loop assigns d, count, i;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert d <= i * 100;
        d += l[i];
        if (d <= x) {
            count += 1;
        } else {
            break;
        }
        i += 1;
    }
    return count;
}

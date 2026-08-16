#include <stddef.h>
#include <stdbool.h>

/*@
  requires (1 <= (n) <= 100 && 1 <= (x) <= 10000);
  requires (\valid((l) + (0 .. (n)-1)) &&
      \forall integer j; 0 <= j < (n) ==> 1 <= (l)[j] <= 100);
  ensures 1 <= \result <= n+1;
*/
size_t func(size_t n, int x, int *l) {
    int d = 0;
    size_t count = 1;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant d <= x + 100 * (int)i;
      loop invariant 1 <= count <= i + 1;
      loop assigns d, count, i;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        d += l[i];
        if (d <= x) {
            count += 1;
        }
        i += 1;
    }
    
    //@ assert 1 <= count <= n+1;
    return count;
}

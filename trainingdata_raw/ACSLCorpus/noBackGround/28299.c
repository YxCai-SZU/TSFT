#include <stddef.h>

/*@
  requires 1 <= n && n <= 200000;
  requires \valid(a + (0..n-1));
  requires (\forall size_t i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= (int)(n));
  assigns \nothing;
  ensures 0 <= \result && \result <= (int)n;
*/
int func(size_t n, int *a) {
    int num = 1;
    int count = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 1 <= num <= (int)(index + 1);
      loop invariant 0 <= count <= (int)index;
      loop invariant (\forall size_t i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= (int)(n));
      loop assigns num, count, index;
      loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        if (a[index] == num) {
            num += 1;
        } else {
            count += 1;
        }
        index += 1;
    }
    return count;
}

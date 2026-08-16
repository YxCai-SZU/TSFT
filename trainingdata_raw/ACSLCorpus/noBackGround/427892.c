#include <stddef.h>

/*@
  requires 1 <= n <= 100;
  requires \valid(a + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> (1 <= (a[i]) <= 100);
  ensures \result >= 0 && \result <= n;
  ensures \forall integer i; 0 <= i < n && ((i) % 2 == 0) && ((a[i]) % 2 == 1) ==> \result > 0;
*/
size_t func(size_t n, const size_t a[]) {
    size_t count;
    size_t i;
    
    count = 0;
    i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant count >= 0;
      loop invariant count <= i;
      loop invariant \forall integer j; 0 <= j < i && ((j) % 2 == 0) && ((a[j]) % 2 == 1) ==> count > 0;
      loop invariant \forall integer k; 0 <= k < n ==> (1 <= (a[k]) <= 100);
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n) {
        if (i % 2 == 0) {
            if (a[i] % 2 == 1) {
                //@ assert count >= 0;
                count += 1;
                //@ assert count > 0;
            }
        }
        i += 1;
    }
    
    //@ assert count >= 0 && count <= n;
    //@ assert \forall integer i; 0 <= i < n && ((i) % 2 == 0) && ((a[i]) % 2 == 1) ==> count > 0;
    return count;
}

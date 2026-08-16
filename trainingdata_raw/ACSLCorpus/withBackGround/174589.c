#include <stddef.h>
#include <stdint.h>

/*@ predicate valid_range(integer n) = 1 <= n <= 1000000; */
/*@ predicate valid_array(int64_t *a, integer n) = 
      \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 1000000; */

/*@
  requires valid_range(n);
  requires \valid_read(a + (0 .. n-1));
  requires valid_array(a, n);
  ensures 0 <= \result <= n;
  assigns \nothing;
*/
int32_t func(size_t n, const int64_t *a) {
    int64_t before;
    int32_t count;
    size_t i;
    
    before = a[0];
    count = 0;
    i = 0;
    
    /*@
      loop invariant 0 <= i <= n-1;
      loop invariant 0 <= count <= i;
      loop invariant valid_range(n);
      loop invariant valid_array(a, n);
      loop invariant 1 <= before <= 1000000;
      loop invariant \valid_read(a + (0 .. n-1));
      loop assigns i, count, before;
      loop variant n - i;
    */
    while (i < n - 1) {
        //@ assert 0 <= i < n-1;
        
        if (before <= a[i + 1]) {
            before = a[i + 1];
        } else {
            count += 1;
            before = a[i + 1];
        }
        
        i += 1;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}

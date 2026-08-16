#include <stdbool.h>
#include <stdint.h>

/*@
  requires n > 0 && n <= 100;
  requires \valid(a + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> 0 < (a)[i] && (a)[i] <= 1000);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
int32_t func(uint32_t n, uint32_t *a) {
    int32_t count = 0;
    uint32_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= count <= i;
      loop assigns i, count;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (a[i] % 2 == 0) {
            count = count + 1;
        }
        i = i + 1;
    }
    //@ assert i == n;
    //@ assert 0 <= count <= n;
    return count;
}

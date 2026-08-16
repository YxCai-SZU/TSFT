#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) >= 1 && (n) <= 200000 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000000);
  assigns \nothing;
  ensures \result == -1 || \result > 0;
*/
int func(size_t n, const int *a) {
    // Variable declarations at top of scope
    int count = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant count <= n;
        loop invariant ((n) >= 1 && (n) <= 200000 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000000);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert ((n) >= 1 && (n) <= 200000 &&       \valid((a) + (0 .. (n)-1)) &&       \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000000);
        if (i % 2 == 0 && a[i] % 2 == 1) {
            count += 1;
        }
        i += 1;
    }
    
    if (count == 0) {
        //@ assert count == 0;
        return -1;
    } else {
        //@ assert count > 0;
        return count;
    }
}

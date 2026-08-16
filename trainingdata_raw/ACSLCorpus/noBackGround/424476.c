#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) > 0 && (n) <= 100000 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000000000);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
size_t func(size_t n, int* a) {
    bool prev = false;
    bool next = false;
    size_t count = 0;
    bool skip = true;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant \valid(a + (0 .. n-1));
      loop invariant \forall integer i; 0 <= i < n ==> a[i] > 0 && a[i] <= 1000000000;
      loop invariant count <= index;
      loop invariant index > 0 ==> (prev == false || prev == true);
      loop invariant index > 0 ==> (next == false || next == true);
      loop assigns prev, next, count, skip, index;
      loop variant n - index;
    */
    while (index < n - 1) {
        if (a[index] == 2) {
            skip = false;
        }
        if (skip) {
            index += 1;
            continue;
        }
        if (a[index] == 1) {
            count += 1;
            next = true;
        } else if (a[index] == 3 && next) {
            count += 1;
            next = false;
        }
        index += 1;
    }
    //@ assert 0 <= count <= n;
    return count;
}

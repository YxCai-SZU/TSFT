#include <stdbool.h>
#include <stddef.h>

/*@
  requires n > 0 && n <= 100;
  requires \valid(v + (0 .. n-1));
  requires ((n) > 0 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (v)[i] && (v)[i] <= 1000);
  assigns \nothing;
  ensures \result <= n;
  ensures (\exists integer i; 0 <= i < n && ((i) % 2 == 0 && (v)[(i)] % 2 == 1)) ==> \result > 0;
*/
size_t func(size_t n, int* v) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= count <= i;
      loop invariant ((n) > 0 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (v)[i] && (v)[i] <= 1000);
      loop invariant (\exists integer j; 0 <= j < i && ((j) % 2 == 0 && (v)[(j)] % 2 == 1)) ==> count > 0;
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n) {
        int value = v[i];
        //@ assert ((i) % 2 == 0 && (v)[(i)] % 2 == 1) ==> (i % 2 == 0 && value % 2 == 1);
        if (i % 2 == 0 && value % 2 == 1) {
            count += 1;
        }
        i += 1;
    }
    return count;
}

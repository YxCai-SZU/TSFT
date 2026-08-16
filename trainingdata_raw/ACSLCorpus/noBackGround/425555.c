#include <stddef.h>
#include <stdbool.h>

/*@
  requires ((n) >= 3 && (n) <= 20 &&
      \valid((p) + (0 .. (n)-1)) &&
      (\forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (n)) &&
      (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]));
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= n - 2;
*/
int func(size_t n, int *p) {
    int count = 0;
    size_t i = 1;

    /*@
      loop invariant 1 <= i <= n - 1;
      loop invariant count >= 0;
      loop invariant count <= (int)(i - 1);
      loop invariant ((n) >= 3 && (n) <= 20 &&
      \valid((p) + (0 .. (n)-1)) &&
      (\forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (n)) &&
      (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]));
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n - 1) {
        //@ assert i - 1 < n && i < n && i + 1 < n;
        
        if (p[i - 1] < p[i] && p[i] < p[i + 1]) {
            //@ assert count + 1 >= 0;
            count += 1;
        }
        if (p[i - 1] > p[i] && p[i] > p[i + 1]) {
            //@ assert count + 1 >= 0;
            count += 1;
        }
        i += 1;
    }
    return count;
}

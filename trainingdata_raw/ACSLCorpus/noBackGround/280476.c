#include <stddef.h>
#include <stdint.h>

/*@
  requires \valid_read(v + (0 .. n-1));
  requires (3 <= (n) && (n) <= 100 &&
      1 <= (a) && (a) < (b) && (b) <= (n));
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (v)[i] && (v)[i] <= 1000);
  assigns \nothing;
  ensures \result >= 0;
*/
int64_t func(size_t n, size_t a, size_t b, int64_t *v) {
    int64_t x;
    size_t i;

    x = v[a - 1];
    i = a;

    /*@
      loop invariant a <= i <= b;
      loop invariant 1 <= x <= 1000;
      loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (v)[i] && (v)[i] <= 1000);
      loop invariant (3 <= (n) && (n) <= 100 &&
      1 <= (a) && (a) < (b) && (b) <= (n));
      loop invariant i <= n;
      loop assigns x, i;
    */
    while (i < b) {
        //@ assert 0 <= i < n;
        if (x < v[i]) {
            x = x;
        } else {
            x = v[i];
        }
        //@ assert 1 <= x <= 1000;
        i = i + 1;
    }

    return x;
}

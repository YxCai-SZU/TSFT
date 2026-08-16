#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) >= 1 && (n) <= 100000 &&
      (k) >= 1 && (k) <= 500);
  requires \valid(h + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= *((h) + i) && *((h) + i) <= 500);
  assigns \nothing;
  ensures 0 <= \result <= n;
  ensures (\forall integer i; 0 <= i < (n) ==> (*((h) + i) >= (k) ==> (\result) >= 1));
*/
long func(long n, long k, long *h) {
    long count = 0;
    size_t index = 0;

    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= count <= index;
      loop invariant index > 0 ==> 
        \forall integer i; 0 <= i < index ==> (*(h + i) >= k ==> count >= 1);
      loop assigns count, index;
      loop variant n - index;
    */
    while (index < (size_t)n) {
        long i = *(h + index);
        if (i >= k) {
            count += 1;
        }
        index += 1;
    }
    return count;
}

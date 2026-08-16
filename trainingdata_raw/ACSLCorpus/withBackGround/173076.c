#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_even(integer n) = n % 2 == 0; */
/*@ predicate is_odd(integer n) = n % 2 != 0; */

/*@
  requires 1 <= n <= 200000;
  requires \valid(v + (0 .. n-1));
  requires \forall integer i; 0 <= i < n ==> 1 <= v[i] <= 1000000;
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
int func(size_t n, const int v[]) {
    int count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= count <= (int)i;
      loop invariant \forall integer j; 0 <= j < n ==> 1 <= v[j] <= 1000000;
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if ((i % 2 == 0) && ((v[i] & 1) != 0)) {
            count += 1;
        }
        i += 1;
    }
    return count;
}

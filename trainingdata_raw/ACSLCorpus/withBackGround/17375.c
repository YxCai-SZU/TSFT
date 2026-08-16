#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_params(integer n, integer x) =
      1 <= n && n <= 100 &&
      1 <= x && x <= 10000;
*/

/*@ predicate valid_array(integer n, int *l) =
      \valid(l + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> 1 <= l[i] && l[i] <= 100;
*/

/*@ lemma loop_invariant_maintains_count_bounds:
      \forall integer i, integer n, integer count;
      0 <= i && i <= n && 0 <= count && count <= i ==> count <= n + 1;
*/

/*@ requires valid_params(n, x);
    requires n >= 1;
    requires \valid(l + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= l[i] && l[i] <= 100;
    ensures \result >= 0;
    ensures \result <= n + 1;
*/
int func(int n, int x, int *l) {
    int d = 0;
    int count = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= d <= x + 100;
        loop invariant 0 <= count <= (int)i <= n + 1;
        loop invariant \forall integer j; 0 <= j < i ==> 1 <= l[j] && l[j] <= 100;
        loop invariant \forall integer k; 0 <= k < n ==> 1 <= l[k] && l[k] <= 100;
        loop invariant 1 <= n <= 100;
        loop invariant 1 <= x <= 10000;
        loop assigns d, count, i;
        loop variant n - i;
    */
    while (i < (size_t)n && d <= x) {
        int li = l[i];
        //@ assert 1 <= li && li <= 100;
        d += li;
        count += 1;
        i += 1;
    }
    //@ assert count >= 0;
    return count;
}

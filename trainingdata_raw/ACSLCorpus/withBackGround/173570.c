#include <stdbool.h>
#include <stddef.h>

/*@ predicate distinct_elements(int *v, integer n) =
      \forall integer i, j; 0 <= i < j < n ==> v[i] != v[j];
*/

/*@ predicate in_range(int *v, integer n, integer max_val) =
      \forall integer i; 0 <= i < n ==> 1 <= v[i] <= max_val;
*/

/*@ lemma distinct_preserved:
      \forall int *v, integer n, integer i;
        distinct_elements(v, n) && 0 <= i <= n ==>
        distinct_elements(v, i);
*/

/*@ lemma range_preserved:
      \forall int *v, integer n, integer max_val, integer i;
        in_range(v, n, max_val) && 0 <= i <= n ==>
        in_range(v, i, max_val);
*/

/*@ requires n >= 2 && n <= 100000;
    requires \valid(v + (0 .. n-1));
    requires distinct_elements(v, n);
    requires in_range(v, n, n);
    ensures 1 <= \result <= n;
    ensures \result >= 1;
    ensures \result <= n;
*/
int func(size_t n, int *v) {
    int ret = 1;
    size_t i = 1;

    /*@ loop invariant 1 <= i <= n;
        loop invariant 1 <= ret <= (int)i;
        loop invariant distinct_elements(v, n);
        loop invariant in_range(v, n, n);
        loop invariant distinct_elements(v, i);
        loop invariant in_range(v, i, n);
        loop assigns ret, i;
        loop variant n - i;
    */
    while (i < n) {
        int diff = v[i-1] - v[i];
        //@ assert distinct_elements(v, i+1);
        //@ assert in_range(v, i+1, n);
        if (diff < 0) {
            ret += 1;
        }
        i += 1;
    }
    return ret;
}

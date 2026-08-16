#include <stdbool.h>
#include <stddef.h>

/*@ predicate distinct_elements(int *p, integer n) =
      \forall integer i, j; 0 <= i < j < n ==> p[i] != p[j];

   predicate in_range(int *p, integer n) =
      \forall integer i; 0 <= i < n ==> 1 <= p[i] && p[i] <= n;

   logic integer ans_bounds(integer i) = i;
*/

/*@ lemma ans_non_negative:
      \forall integer i; 1 <= i ==> 0 <= ans_bounds(i);
*/

/*@ requires n >= 3 && n <= 200000;
    requires \valid(p + (0 .. n-1));
    requires distinct_elements(p, n);
    requires in_range(p, n);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(size_t n, int *p) {
    int ans = 0;
    size_t i = 1;

    /*@ loop invariant 1 <= i <= n-1;
        loop invariant ans >= 0;
        loop invariant ans <= ans_bounds(i);
        loop invariant distinct_elements(p, n);
        loop invariant in_range(p, n);
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n - 1) {
        //@ assert p[i-1] != p[i] && p[i] != p[i+1];
        
        if (p[i - 1] < p[i] && p[i] < p[i + 1]) {
            ans += 1;
        }
        //@ assert ans >= 0;
        
        if (p[i - 1] > p[i] && p[i] > p[i + 1]) {
            ans += 1;
        }
        //@ assert ans >= 0;
        
        i += 1;
    }
    return ans;
}

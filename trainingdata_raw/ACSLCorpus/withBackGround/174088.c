#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int *p, integer n) =
      n >= 1 && n <= 200000 &&
      \forall integer i; 0 <= i < n ==> p[i] >= 1 && p[i] <= (int)n &&
      \forall integer i, j; 0 <= i < j < n ==> p[i] != p[j];
*/

/*@ requires n >= 1 && n <= 200000;
    requires \valid(p + (0 .. n-1));
    requires valid_array(p, n);
    ensures \result >= 1 && \result <= (int)n;
    assigns \nothing;
*/
int func(int n, int *p) {
    int result = 1;
    int max = p[0];
    size_t i = 1;
    
    /*@ loop invariant 1 <= i <= n;
        loop invariant 1 <= result <= (int)i;
        loop invariant 1 <= max <= (int)n;
        loop invariant \forall integer k; 0 <= k < i ==> p[k] >= 1 && p[k] <= (int)n;
        loop invariant \forall integer k, j; 0 <= k < j < i ==> p[k] != p[j];
        loop assigns i, result, max;
        loop variant n - i;
    */
    while (i < (size_t)n) {
        //@ assert p[i] >= 1 && p[i] <= (int)n;
        if (p[i] <= max) {
            max = p[i];
            result += 1;
        }
        i += 1;
    }
    return result;
}

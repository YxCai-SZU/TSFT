#include <stdbool.h>
/*@
    predicate is_permutation(integer n, int *p) =
        \forall integer i; 0 <= i < n ==> 1 <= p[i] <= n &&
        \forall integer i, j; 0 <= i < j < n ==> p[i] != p[j];

    lemma result_bounds:
        \forall integer n, int *p, integer result;
        is_permutation(n, p) && 1 <= n <= 200000 && 1 <= result <= n ==> 1 <= result <= n;
*/

/*@
    requires 1 <= n <= 200000;
    requires \valid(p + (0 .. n-1));
    requires is_permutation(n, p);
    ensures 1 <= \result <= n;
    assigns \nothing;
*/
int func(int n, int *p) {
    int result = 1;
    int max = p[0];
    int index = 1;
    
    /*@
        loop invariant 1 <= index <= n;
        loop invariant 1 <= result <= index;
        loop invariant \forall integer i; 0 <= i < n ==> 1 <= p[i] <= n;
        loop invariant \forall integer i, j; 0 <= i < j < n ==> p[i] != p[j];
        loop invariant index > 0;
        loop invariant index <= n;
        loop invariant result <= index;
        loop assigns result, max, index;
        loop variant n - index;
    */
    while (index < n) {
        if (max <= p[index]) {
            result += 1;
            max = p[index];
        }
        index += 1;
    }
    //@ assert result <= n;
    return result;
}

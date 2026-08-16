#include <stdbool.h>
/*@
    predicate is_valid_range(integer n) = 3 <= n <= 20;
    predicate is_valid_index(integer i, integer n) = 0 <= i < n;
    predicate is_valid_value(integer v, integer n) = 1 <= v <= n;
    predicate is_injective(int *p, integer n) = 
        \forall integer i, j; 0 <= i < j < n ==> p[i] != p[j];
    predicate array_props(int *p, integer n) = 
        \forall integer i; 0 <= i < n ==> 1 <= p[i] <= n;
*/

/*@
    requires is_valid_range(n);
    requires \valid(p + (0 .. n-1));
    requires array_props(p, n);
    requires is_injective(p, n);
    assigns \nothing;
    ensures 0 <= \result <= n-2;
*/
int func(int n, int *p) {
    int count = 0;
    int i = 1;
    /*@
        loop invariant 1 <= i <= n-1;
        loop invariant 0 <= count <= i-1;
        loop invariant array_props(p, n);
        loop invariant is_injective(p, n);
        loop invariant is_valid_range(n);
        loop assigns count, i;
        loop variant n-i;
    */
    while (i < n-1) {
        //@ assert is_valid_index(i-1, n) && is_valid_index(i, n) && is_valid_index(i+1, n);
        if (p[i-1] < p[i] && p[i] < p[i+1]) {
            count += 1;
        }
        if (p[i-1] > p[i] && p[i] > p[i+1]) {
            count += 1;
        }
        i += 1;
    }
    return count;
}

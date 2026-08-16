#include <stdbool.h>

/*@
    predicate valid_range(integer n) = 1 <= n <= 100;
    predicate valid_array(int *a, integer n) =
        \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 100;
    predicate count_invariant(int *a, integer idx, integer cnt, integer n) =
        0 <= idx <= n &&
        0 <= cnt <= idx &&
        valid_array(a, n);
*/

/*@
    lemma count_bound: \forall int *a, integer idx, integer cnt, integer n;
        count_invariant(a, idx, cnt, n) ==> cnt <= n;
*/

/*@
    requires valid_range(n);
    requires \valid(a + (0 .. n-1));
    requires valid_array(a, n);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(int n, int *a) {
    int count = 0;
    int num = 0;
    int index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant valid_array(a, n);
        loop assigns count, num, index;
        loop variant n - index;
    */
    while (index < n) {
        num = a[index];
        if ((num & 1) == 1) {
            count += 1;
        }
        index += 1;
        //@ assert count <= index;
    }
    //@ assert count <= n;
    return count;
}

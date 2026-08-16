#include <stddef.h>

/*@
    predicate valid_params(integer n, integer a, integer b, int *p) =
        3 <= n && n <= 100 &&
        1 <= a && a < b && b < 20 &&
        \forall integer j; 0 <= j < n ==> (1 <= *(p + j) && *(p + j) <= 20);

    predicate first_loop_inv(integer i, integer n, integer count, integer a, int *p) =
        0 <= i <= n &&
        0 <= count <= i &&
        \forall integer k; 0 <= k < i ==> (*(p + k) <= a ==> count >= 1);

    predicate second_loop_inv(integer i, integer n, integer count, integer a, integer b, int *p) =
        0 <= i <= n &&
        0 <= count <= i &&
        \forall integer k; 0 <= k < i ==> (*(p + k) <= b && *(p + k) > a ==> count >= 1);

    predicate third_loop_inv(integer i, integer n, integer count, integer b, int *p) =
        0 <= i <= n &&
        0 <= count <= i &&
        \forall integer k; 0 <= k < i ==> (*(p + k) > b ==> count >= 1);
*/

/*@
    requires valid_params(n, a, b, p);
    requires \valid(p + (0 .. n-1));
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n, int a, int b, int *p) {
    int count;
    int i;
    int ans;

    // First loop
    count = 0;
    i = 0;
    /*@
        loop invariant first_loop_inv(i, n, count, a, p);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        int pi = p[i];
        //@ assert 0 <= i < n;
        if (pi <= a) {
            //@ assert pi <= a ==> count >= 0;
            count += 1;
        }
        i += 1;
    }
    ans = count;

    // Second loop
    count = 0;
    i = 0;
    /*@
        loop invariant second_loop_inv(i, n, count, a, b, p);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        int pi = p[i];
        //@ assert 0 <= i < n;
        if (pi <= b && pi > a) {
            //@ assert pi <= b && pi > a ==> count >= 0;
            count += 1;
        }
        i += 1;
    }
    //@ assert 0 <= ans <= n && 0 <= count <= n;
    ans = (ans < count) ? ans : count;

    // Third loop
    count = 0;
    i = 0;
    /*@
        loop invariant third_loop_inv(i, n, count, b, p);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        int pi = p[i];
        //@ assert 0 <= i < n;
        if (pi > b) {
            //@ assert pi > b ==> count >= 0;
            count += 1;
        }
        i += 1;
    }
    //@ assert 0 <= ans <= n && 0 <= count <= n;
    ans = (ans < count) ? ans : count;

    //@ assert ans >= 0 && ans <= n;
    return ans;
}

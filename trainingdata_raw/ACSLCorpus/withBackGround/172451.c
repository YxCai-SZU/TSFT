#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_params(integer n, integer x, int *l) =
    n >= 1 && n <= 100 &&
    x >= 1 && x <= 10000 &&
    \valid(l + (0 .. n-1)) &&
    \forall integer i; 0 <= i < n ==> l[i] >= 1 && l[i] <= 100;
*/

/*@ predicate loop_invariant(integer n, integer x, int *l, integer index, integer d, integer ans) =
    index >= 0 && index <= n &&
    d >= 0 && d <= index * 100 &&
    ans >= 0 && ans <= index &&
    n >= 1 && n <= 100 &&
    x >= 1 && x <= 10000 &&
    \valid(l + (0 .. n-1)) &&
    (index > 0 ==> \forall integer i; 0 <= i < index ==> l[i] >= 1 && l[i] <= 100);
*/

/*@ lemma loop_decreases: 
    \forall integer n, integer index; 
    index <= n ==> n - index >= 0;
*/

/*@ requires valid_params(n, x, l);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(int n, int x, int *l) {
    int d = 0;
    int ans = 0;
    int index = 0;

    /*@ loop invariant loop_invariant(n, x, l, index, d, ans);
        loop assigns d, ans, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert index >= 0 && index < n;
        d += l[index];
        if (d <= x) {
            ans += 1;
        }
        index += 1;
    }
    //@ assert ans >= 0;
    return ans;
}

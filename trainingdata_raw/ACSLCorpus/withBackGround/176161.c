#include <stdbool.h>

/*@ predicate sorted(int *a, integer n) =
      \forall integer i; 0 <= i < n-1 ==> a[i] <= a[i+1];
*/

/*@ lemma sorted_lemma:
      \forall int *a, integer n;
        sorted(a, n) ==> (\forall integer i; 0 <= i < n-1 ==> a[i] <= a[i+1]);
*/

/*@ logic integer safe_mult(integer s, integer t) = s * t; */

/*@ lemma mult_bounds:
      \forall integer s, t;
        1 <= s <= 10000 && 1 <= t <= 10000 ==>
          1 <= safe_mult(s, t) <= 100000000;
*/

/*@ requires n >= 0;
    requires \valid(a+(0..n-1));
    assigns \nothing;
    ensures \result == 1 <==> sorted(a, n);
*/
bool is_sorted(int *a, int n) {
    int i = 0;
    /*@ loop invariant 0 <= i <= n;
        loop invariant \forall integer j; 0 <= j < i ==> a[j] <= a[j+1];
        loop assigns i;
        loop variant n - i;
    */
    while (i < n - 1) {
        //@ assert 0 <= i < n-1;
        if (a[i] > a[i+1]) {
            return false;
        }
        i++;
    }
    return true;
}

/*@ requires 1 <= d <= 10000 && 1 <= t <= 10000 && 1 <= s <= 10000;
    assigns \nothing;
    ensures \result == (s * t >= d);
*/
bool func(int d, int t, int s) {
    //@ assert 1 <= safe_mult(s, t) <= 100000000;
    return s * t >= d;
}

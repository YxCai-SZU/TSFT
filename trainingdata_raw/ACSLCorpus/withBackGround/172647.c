#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_params(integer n, integer m, integer x) =
      1 <= n && n <= 100 &&
      1 <= m && m <= 100 &&
      1 <= x && x <= n - 1;
*/

/*@ predicate array_constraints(int *arr, integer m, integer n, integer x) =
      \forall integer i; 0 <= i < m ==> 
        arr[i] >= 1 && arr[i] <= n && arr[i] != x;
*/

/*@ lemma loop_invariant_maintained:
      \forall integer n, m, x, i, l, r;
      \forall int *arr;
        valid_params(n, m, x) &&
        array_constraints(arr, m, n, x) &&
        0 <= i && i <= m &&
        l >= 0 && r >= 0 &&
        l + r <= i ==>
        array_constraints(arr, m, n, x);
*/

/*@ requires valid_params(n, m, x);
    requires \valid(arr + (0 .. m-1));
    requires array_constraints(arr, m, n, x);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(int n, int m, int x, int *arr) {
    int l = 0;
    int r = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= m;
        loop invariant l >= 0;
        loop invariant r >= 0;
        loop invariant l + r == i;
        loop invariant array_constraints(arr, m, n, x);
        loop assigns i, l, r;
        loop variant m - i;
    */
    while (i < m) {
        int a = arr[i];
        if (a < x) {
            l = l + 1;
        } else if (a > x) {
            r = r + 1;
        }
        i = i + 1;
    }
    
    int min_val;
    if (l < r) {
        min_val = l;
    } else {
        min_val = r;
    }
    
    //@ assert min_val >= 0;
    return min_val;
}

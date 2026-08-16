#include <stdbool.h>

/*@ predicate arr_bounds(int *arr, integer n) =
      \forall integer i; 0 <= i < n ==> 0 <= arr[i] <= 1000;
*/

/*@ predicate loop1_inv(int *arr, integer n, integer i, int x) =
      0 <= i <= n &&
      1 <= n <= 100 &&
      x >= 0 &&
      x <= 1000 &&
      (i > 0 ==> \forall integer k; 0 <= k < i ==> x >= arr[k]);
*/

/*@ predicate loop2_inv(int *arr1, integer n, integer m, integer i, int y) =
      0 <= i <= m &&
      1 <= m <= n &&
      y >= 0 &&
      y <= 1000 &&
      (i > 0 ==> \forall integer k; 0 <= k < i ==> y >= arr1[k]);
*/

/*@ lemma max_property:
      \forall int *arr, integer n, int x;
      arr_bounds(arr, n) && loop1_inv(arr, n, n, x) ==> 
      \forall integer j; 0 <= j < n ==> x >= arr[j];
*/

/*@ lemma abs_nonneg:
      \forall int a, int b, int ans;
      a >= 0 && b >= 0 && ans >= 0 ==> 
      (a - ans < 0 ? -(a - ans) : a - ans) >= 0;
*/

/*@ requires 1 <= n <= 100;
    requires 1 <= m <= n;
    requires \valid(arr + (0 .. n-1));
    requires \valid(arr1 + (0 .. n-1));
    requires arr_bounds(arr, n);
    requires arr_bounds(arr1, n);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(int n, int m, int *arr, int *arr1) {
    int x;
    int i;
    int y;
    int ans;
    int s;
    
    x = 0;
    i = 0;
    
    /*@ loop invariant loop1_inv(arr, n, i, x);
        loop assigns x, i;
        loop variant n - i;
    */
    while (i < n) {
        if (arr[i] > x) {
            x = arr[i];
        }
        i = i + 1;
    }
    
    y = 0;
    i = 0;
    
    /*@ loop invariant loop2_inv(arr1, n, m, i, y);
        loop assigns y, i;
        loop variant m - i;
    */
    while (i < m) {
        if (arr1[i] > y) {
            y = arr1[i];
        }
        i = i + 1;
    }
    
    ans = (x > y) ? x : y;
    
    s = (x - ans < 0) ? -(x - ans) : (x - ans);
    
    //@ assert s >= 0;
    return s;
}

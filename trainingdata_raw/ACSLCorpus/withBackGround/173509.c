#include <stdbool.h>

/*@ predicate max_in_range(int *arr, integer len, integer i, int max) =
      \exists integer j; 0 <= j < i && arr[j] == max;
*/

/*@ predicate all_leq(int *arr, integer len, integer i, int max) =
      \forall integer j; 0 <= j < i ==> arr[j] <= max;
*/

/*@ lemma max_exists: 
      \forall int *arr, integer len, integer i, int max;
      all_leq(arr, len, i, max) && max_in_range(arr, len, i, max) ==>
      (\forall integer j; 0 <= j < i ==> arr[j] <= max) &&
      (\exists integer j; 0 <= j < i && arr[j] == max);
*/

/*@ logic integer product(integer n, integer m) = (n - 1) * (m - 1); */

/*@ lemma product_bounds:
      \forall integer n, m;
      2 <= n <= 100 && 2 <= m <= 100 ==> 
      1 <= product(n, m) <= 99 * 99;
*/

/*@ logic integer bounded_diff(integer a, integer b, integer c) =
      c - (a - b) < 0 ? 0 : c - (a - b);
*/

/*@ lemma diff_bounds:
      \forall integer a, b, c;
      1 <= b <= a <= 20 && 1 <= c <= 20 ==>
      0 <= bounded_diff(a, b, c) <= c;
*/

/*@ requires len > 0;
    requires \valid(arr + (0 .. len-1));
    assigns \nothing;
    ensures \exists integer j; 0 <= j < len && arr[j] == \result;
    ensures \forall integer j; 0 <= j < len ==> arr[j] <= \result;
*/
int find_max(int *arr, int len) {
    int max;
    int i;
    
    max = arr[0];
    i = 1;
    
    /*@ loop invariant 1 <= i <= len;
        loop invariant all_leq(arr, len, i, max);
        loop invariant max_in_range(arr, len, i, max);
        loop assigns max, i;
        loop variant len - i;
    */
    while (i < len) {
        if (arr[i] > max) {
            max = arr[i];
        }
        i = i + 1;
    }
    
    return max;
}

/*@ requires 2 <= n <= 100;
    requires 2 <= m <= 100;
    assigns \nothing;
    ensures \result == product(n, m);
*/
int func(int n, int m) {
    int result;
    
    result = (n - 1) * (m - 1);
    
    return result;
}

/*@ requires 1 <= b <= a <= 20;
    requires 1 <= c <= 20;
    assigns \nothing;
    ensures \result == bounded_diff(a, b, c);
*/
int func2(int a, int b, int c) {
    int result;
    int tmp;
    
    tmp = c - (a - b);
    if (tmp < 0) {
        result = 0;
    } else {
        result = tmp;
    }
    
    return result;
}

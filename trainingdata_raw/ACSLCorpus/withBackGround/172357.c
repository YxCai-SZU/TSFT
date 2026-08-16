#include <stdbool.h>

/*@
    predicate is_valid_range(int *arr, integer n) =
        n > 0 && n <= 100 &&
        \forall integer k; 0 <= k < n ==> arr[k] >= 1 && arr[k] <= 1000;

    predicate condition_holds(int *arr, integer n) =
        \forall integer i; 0 <= i < n && arr[i] % 2 == 0 ==>
            arr[i] % 3 == 0 || arr[i] % 5 == 0;
*/

/*@
    requires n > 0 && n <= 100;
    requires \valid(v + (0 .. n-1));
    requires is_valid_range(v, n);
    ensures \result == true <==> condition_holds(v, n);
    assigns \nothing;
*/
bool func(int n, int *v) {
    int i = 0;
    bool ret = true;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant ret == true <==> 
            (\forall integer j; 0 <= j < i && v[j] % 2 == 0 ==> 
                v[j] % 3 == 0 || v[j] % 5 == 0);
        loop invariant is_valid_range(v, n);
        loop assigns i, ret;
        loop variant n - i;
    */
    while (i < n) {
        int val = v[i];
        if (val % 2 == 0) {
            if (val % 3 != 0 && val % 5 != 0) {
                ret = false;
            }
        }
        i++;
    }
    return ret;
}

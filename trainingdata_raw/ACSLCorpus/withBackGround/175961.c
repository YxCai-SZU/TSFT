#include <stdbool.h>

/*@
    predicate exists_max(int *arr, integer len, integer i, integer max_val) =
        \exists integer k; 0 <= k < i && arr[k] == max_val;

    predicate forall_max(int *arr, integer len, integer i, integer max_val) =
        \forall integer j; 0 <= j < i ==> arr[j] <= max_val;

    predicate exists_min(int *arr, integer len, integer i, integer min_val) =
        \exists integer k; 0 <= k < i && arr[k] == min_val;

    predicate forall_min(int *arr, integer len, integer i, integer min_val) =
        \forall integer j; 0 <= j < i ==> arr[j] >= min_val;
*/

/*@
    requires len > 0;
    requires \valid_read(arr + (0 .. len-1));
    assigns \nothing;
    ensures \exists integer i; 0 <= i < len && arr[i] == \result;
    ensures \forall integer j; 0 <= j < len ==> arr[j] <= \result;
*/
int max_value(const int *arr, int len) {
    int max_val;
    int i;
    
    max_val = arr[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant exists_max(arr, len, i, max_val);
        loop invariant forall_max(arr, len, i, max_val);
        loop assigns max_val, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        i++;
    }
    return max_val;
}

/*@
    requires len > 0;
    requires \valid_read(arr + (0 .. len-1));
    assigns \nothing;
    ensures \exists integer i; 0 <= i < len && arr[i] == \result;
    ensures \forall integer j; 0 <= j < len ==> arr[j] >= \result;
*/
int min_value(const int *arr, int len) {
    int min_val;
    int i;
    
    min_val = arr[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant exists_min(arr, len, i, min_val);
        loop invariant forall_min(arr, len, i, min_val);
        loop assigns min_val, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        i++;
    }
    return min_val;
}

/*@
    assigns \nothing;
    ensures \result == a || \result == b || \result == c;
    ensures (\result == a ==> ((b <= a && a <= c) || (c <= a && a <= b)));
    ensures (\result == b ==> ((a <= b && b <= c) || (c <= b && b <= a)));
    ensures (\result == c ==> ((a <= c && c <= b) || (b <= c && c <= a)));
*/
int median_three(int a, int b, int c) {
    int ret;
    
    if ((a >= b && a <= c) || (a >= c && a <= b)) {
        ret = a;
    } else if ((b >= a && b <= c) || (b >= c && b <= a)) {
        ret = b;
    } else {
        ret = c;
    }
    
    //@ assert ret == a || ret == b || ret == c;
    return ret;
}

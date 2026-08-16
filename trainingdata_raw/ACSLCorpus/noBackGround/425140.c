#include <stddef.h>
#include <limits.h>

/*@ requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    assigns \nothing;
    ensures \exists integer idx; 0 <= idx < len && arr[idx] == \result;
    ensures (\forall integer j; 0 <= j < (len) ==> (\result) <= (arr)[j]);
*/
int minimum_in_list(const int *arr, size_t len) {
    int min;
    size_t i;
    min = arr[0];
    i = 1;
    /*@ loop invariant 1 <= i <= len;
        loop invariant \exists integer k; 0 <= k < i && arr[k] == min;
        loop invariant \forall integer j; 0 <= j < i ==> min <= arr[j];
        loop assigns min, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert i < len;
        if (arr[i] < min) {
            min = arr[i];
        }
        i = i + 1;
    }
    //@ assert \exists integer k; 0 <= k < len && arr[k] == min;
    return min;
}

/*@ requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    assigns \nothing;
    ensures \exists integer idx; 0 <= idx < len && arr[idx] == \result;
    ensures (\forall integer j; 0 <= j < (len) ==> (\result) >= (arr)[j]);
*/
int maximum_in_list(const int *arr, size_t len) {
    int max;
    size_t i;
    max = arr[0];
    i = 1;
    /*@ loop invariant 1 <= i <= len;
        loop invariant \exists integer k; 0 <= k < i && arr[k] == max;
        loop invariant \forall integer j; 0 <= j < i ==> max >= arr[j];
        loop assigns max, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert i < len;
        if (arr[i] > max) {
            max = arr[i];
        }
        i = i + 1;
    }
    //@ assert \exists integer k; 0 <= k < len && arr[k] == max;
    return max;
}

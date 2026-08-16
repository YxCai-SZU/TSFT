#include <stdbool.h>

/*@
    requires \valid(arr + (0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \exists integer idx; 0 <= idx < len && arr[idx] == \result;
    ensures \forall integer i; 0 <= i < len ==> arr[i] <= \result;
*/
int max_element(int *arr, int len) {
    int max;
    int i;
    max = arr[0];
    i = 1;
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= max;
        loop invariant \exists integer j; 0 <= j < i && arr[j] == max;
        loop assigns max, i;
        loop variant len - i;
    */
    while (i < len) {
        if (arr[i] > max) {
            max = arr[i];
        }
        //@ assert \forall integer j; 0 <= j < i+1 ==> arr[j] <= max;
        //@ assert \exists integer j; 0 <= j < i+1 && arr[j] == max;
        i = i + 1;
    }
    //@ assert \forall integer j; 0 <= j < len ==> arr[j] <= max;
    //@ assert \exists integer j; 0 <= j < len && arr[j] == max;
    return max;
}

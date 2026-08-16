#include <stdbool.h>
#include <stdint.h>

/*@
    requires \valid(arr + (0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \exists integer i; 0 <= i < len && \result == arr[i];
    ensures \forall integer i; 0 <= i < len ==> \result >= arr[i];
*/
int find_max(int *arr, int len) {
    int max;
    int i;
    
    max = arr[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant (\exists integer j; 0 <= j < (i) && (arr)[j] == (max));
        loop invariant (\forall integer j; 0 <= j < (i) ==> (max) >= (arr)[j]);
        loop assigns max, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] > max) {
            max = arr[i];
        }
        i += 1;
    }
    return max;
}

/*@
    requires \valid(numbers + (0..len-1));
    requires len >= 0;
    assigns \nothing;
    ensures \result >= -1 && \result < len;
    ensures \result == -1 ==> \forall integer i; 0 <= i < len ==> numbers[i] != target;
    ensures \result != -1 ==> numbers[\result] == target;
*/
int find_index(int *numbers, int len, int target) {
    int i;
    
    i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\forall integer j; 0 <= j < (i) ==> (numbers)[j] != (target));
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (numbers[i] == target) {
            return i;
        }
        i += 1;
    }
    return -1;
}

/*@
    requires 1 <= b <= a <= 20;
    requires 1 <= c <= 20;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == c - (a - b) || \result == 0;
*/
int func(int a, int b, int c) {
    int result;
    
    if (c > (a - b)) {
        result = c - (a - b);
    } else {
        result = 0;
    }
    return result;
}

/*@
    assigns \nothing;
*/
void main_func(void) {
    return;
}

#include <stdbool.h>

/*@ requires \valid(arr + (0 .. len-1));
    requires len > 0;
    assigns \nothing;
    ensures (\exists integer i; 0 <= i < (len) && (arr)[i] == (\result) &&
        \forall integer j; 0 <= j < (len) ==> (arr)[j] <= (\result));
*/
int find_max(int *arr, int len) {
    int max;
    int i;
    max = arr[0];
    i = 1;
    /*@ loop invariant 1 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= max;
        loop invariant \exists integer j; 0 <= j < i && max == arr[j];
        loop assigns max, i;
        loop variant len - i;
    */
    while (i < len) {
        if (arr[i] > max) {
            max = arr[i];
        }
        i = i + 1;
    }
    //@ assert (\exists integer i; 0 <= i < (len) && (arr)[i] == (max) &&         \forall integer j; 0 <= j < (len) ==> (arr)[j] <= (max));
    return max;
}

/*@ requires 1 <= n <= 100;
    requires 0 <= m <= ((n) * (n));
    assigns \nothing;
    ensures \result == ((n) * (n)) - m;
*/
int func(int n, int m) {
    int result;
    //@ assert ((n) * (n)) <= 10000;
    result = n * n - m;
    return result;
}

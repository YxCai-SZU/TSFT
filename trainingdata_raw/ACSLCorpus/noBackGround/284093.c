#include <stdbool.h>
#include <stddef.h>

/*@ requires 1 <= n <= 200000;
    requires 1 <= n_q <= 200000;
    requires \valid(arr + (0..n-1));
    requires \valid(arr_s + (0..n_q-1));
    requires (\forall integer i, j; 0 <= i < j < (n) ==> (arr)[i] != (arr)[j]);
    requires (\forall integer i, j; 0 <= i < j < (n_q) ==> (arr_s)[i] != (arr_s)[j]);
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (arr)[i] && (arr)[i] <= 1000000000);
    requires (\forall integer i; 0 <= i < (n_q) ==> 1 <= (arr_s)[i] && (arr_s)[i] <= 1000000000);
    ensures \result >= 0;
    ensures \result <= n_q;
*/
int func(int n, int *arr, int n_q, int *arr_s) {
    int total = 0;
    size_t i = 0;
    size_t j = 0;

    /*@ loop invariant 0 <= i <= (size_t)n_q;
        loop invariant total >= 0;
        loop invariant total <= (int)i;
        loop invariant (\forall integer i, j; 0 <= i < j < (n) ==> (arr)[i] != (arr)[j]);
        loop invariant (\forall integer i, j; 0 <= i < j < (n_q) ==> (arr_s)[i] != (arr_s)[j]);
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (arr)[i] && (arr)[i] <= 1000000000);
        loop invariant (\forall integer i; 0 <= i < (n_q) ==> 1 <= (arr_s)[i] && (arr_s)[i] <= 1000000000);
        loop invariant n >= 1 && n <= 200000;
        loop invariant n_q >= 1 && n_q <= 200000;
        loop assigns i, j, total;
        loop variant n_q - i;
    */
    while (i < (size_t)n_q) {
        j = 0;

        /*@ loop invariant 0 <= j <= (size_t)n;
            loop invariant total >= 0;
            loop invariant total <= (int)i;
            loop invariant (\forall integer i, j; 0 <= i < j < (n) ==> (arr)[i] != (arr)[j]);
            loop invariant (\forall integer i, j; 0 <= i < j < (n_q) ==> (arr_s)[i] != (arr_s)[j]);
            loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (arr)[i] && (arr)[i] <= 1000000000);
            loop invariant (\forall integer i; 0 <= i < (n_q) ==> 1 <= (arr_s)[i] && (arr_s)[i] <= 1000000000);
            loop invariant n >= 1 && n <= 200000;
            loop invariant n_q >= 1 && n_q <= 200000;
            loop assigns j, total;
            loop variant n - j;
        */
        while (j < (size_t)n) {
            if (arr[j] == arr_s[i]) {
                total += 1;
                break;
            }
            j += 1;
        }
        i += 1;
    }
    return total;
}

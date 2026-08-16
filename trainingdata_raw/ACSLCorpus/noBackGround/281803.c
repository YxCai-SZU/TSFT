#include <stdbool.h>

/*@
    requires n >= 0 && n <= 100;
    ensures \result == 0;
    ensures \forall integer i; 0 <= i < n ==> \result <= 2*i;
    assigns \nothing;
*/
int min_value_check(int n) {
    int arr[100];
    int min_val;
    int i;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] == 2*j;
        loop invariant i > 0 ==> \forall integer j; 0 <= j < i ==> arr[j] >= 0;
        loop assigns i, arr[0..(n-1)];
        loop variant n - i;
    */
    for (i = 0; i < n; ++i) {
        arr[i] = 2 * i;
    }

    if (n > 0) {
        min_val = arr[0];
        /*@
            loop invariant 1 <= i <= n;
            loop invariant \forall integer j; 0 <= j < i ==> min_val <= arr[j];
            loop invariant \exists integer j; 0 <= j < i && min_val == arr[j];
            loop assigns i, min_val;
            loop variant n - i;
        */
        for (i = 1; i < n; ++i) {
            if (arr[i] < min_val) {
                min_val = arr[i];
            }
        }
    } else {
        min_val = 0;
    }

    //@ assert min_val == 0;
    //@ assert (\forall integer i; 0 <= i < (n) ==> (&arr[0])[i] >= 0);
    return min_val;
}

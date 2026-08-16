#include <stdbool.h>
#include <stddef.h>

/*@
    predicate arr_unique(int *arr, integer n) =
        \forall integer i, j; 0 <= i < j < n ==> arr[i] != arr[j];

    predicate brr_unique(int *brr, integer m) =
        \forall integer i, j; 0 <= i < j < m ==> brr[i] != brr[j];

    predicate arr_range(int *arr, integer n) =
        \forall integer i; 0 <= i < n ==> 0 <= arr[i] <= 1000000000;

    predicate brr_range(int *brr, integer m) =
        \forall integer i; 0 <= i < m ==> 0 <= brr[i] <= 1000000000;

    lemma unique_preserved:
        \forall int *arr, integer n;
        arr_unique(arr, n) ==> \forall integer i; 0 <= i < n ==> arr_unique(arr, n);
*/

/*@
    requires 1 <= n <= 100000;
    requires 1 <= m <= 100000;
    requires \valid(arr + (0 .. n-1));
    requires \valid(brr + (0 .. m-1));
    requires arr_unique(arr, n);
    requires brr_unique(brr, m);
    requires arr_range(arr, n);
    requires brr_range(brr, m);
    assigns \nothing;
    ensures 0 <= \result <= m;
*/
int func(int n, int m, int *arr, int *brr) {
    int c = 0;
    int i = 0;
    /*@
        loop invariant 0 <= i <= m;
        loop invariant 0 <= c <= i;
        loop invariant arr_unique(arr, n);
        loop invariant brr_unique(brr, m);
        loop invariant arr_range(arr, n);
        loop invariant brr_range(brr, m);
        loop assigns c, i;
        loop variant m - i;
    */
    while (i < m) {
        int j = 0;
        /*@
            loop invariant 0 <= j <= n;
            loop invariant 0 <= c <= i;
            loop invariant arr_unique(arr, n);
            loop invariant brr_unique(brr, m);
            loop invariant arr_range(arr, n);
            loop invariant brr_range(brr, m);
            loop assigns c, j;
            loop variant n - j;
        */
        while (j < n) {
            //@ assert 0 <= i < m && 0 <= j < n;
            if (brr[i] == arr[j]) {
                c += 1;
                break;
            }
            j += 1;
        }
        i += 1;
    }
    //@ assert 0 <= c <= m;
    return c;
}

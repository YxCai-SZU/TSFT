#include <stdbool.h>

/*@
    predicate distinct(int *arr, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> arr[i] != arr[j];

    predicate in_range(int *arr, integer len) =
        \forall integer i; 0 <= i < len ==> 1 <= arr[i] <= 100000;

    lemma distinct_preserved:
        \forall int *arr, integer len, integer i, integer j;
        0 <= i < len && 0 <= j < len && i != j && distinct(arr, len) ==> arr[i] != arr[j];
*/

/*@
    requires 1 <= n <= 100000;
    requires 1 <= m <= 100000;
    requires \valid(arr + (0 .. n-1));
    requires \valid(arr1 + (0 .. m-1));
    requires distinct(arr, n);
    requires distinct(arr1, m);
    requires in_range(arr, n);
    requires in_range(arr1, m);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(int n, int m, int *arr, int *arr1) {
    int count = 0;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant distinct(arr, n);
        loop invariant distinct(arr1, m);
        loop invariant in_range(arr, n);
        loop invariant in_range(arr1, m);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        bool found = false;
        int j = 0;
        
        /*@
            loop invariant 0 <= j <= m;
            loop invariant found == false ==> 
                \forall integer k; 0 <= k < j ==> arr[i] != arr1[k];
            loop assigns j, found;
            loop variant m - j;
        */
        while (j < m) {
            if (arr[i] == arr1[j]) {
                found = true;
                break;
            }
            j++;
        }
        
        if (found) {
            count++;
        }
        i++;
    }
    return count;
}

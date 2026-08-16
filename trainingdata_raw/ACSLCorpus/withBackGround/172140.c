#include <stdbool.h>

/*@
    predicate valid_array(int *arr, integer len) = 
        len >= 0 && \valid(arr + (0 .. len-1));

    predicate element_exists(int *arr, integer len, integer x) = 
        \exists integer i; 0 <= i < len && arr[i] == x;
*/

/*@
    requires valid_array(arr, len);
    ensures \result == true <==> element_exists(arr, len, x);
    ensures \result == false <==> !element_exists(arr, len, x);
    assigns \nothing;
*/
bool contains_element(int *arr, int len, int x) {
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] != x;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        if (arr[i] == x) {
            return true;
        }
        i = i + 1;
    }
    return false;
}

/*@
    predicate valid_range(integer n) = 1 <= n <= 100;

    lemma square_bound: \forall integer n; valid_range(n) ==> n * n <= 10000;
*/

/*@
    requires valid_range(n);
    ensures \result == n * n;
    assigns \nothing;
*/
int func(int n) {
    int ans = n * n;
    return ans;
}

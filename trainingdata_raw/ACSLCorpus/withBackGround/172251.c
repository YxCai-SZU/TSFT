#include <stdbool.h>
#include <stddef.h>

/*@
    predicate all_even_divisible_by_3_or_5(unsigned int *arr, integer n, integer i) =
        \forall integer j; 0 <= j < i ==>
            (arr[j] % 2 == 0 ==> (arr[j] % 3 == 0 || arr[j] % 5 == 0));
*/

/*@
    requires n >= 1 && n <= 100;
    requires \valid_read(a_vec + (0 .. n-1));
    ensures \result == 1 <==> all_even_divisible_by_3_or_5(a_vec, n, n);
*/
bool func(unsigned int n, unsigned int *a_vec) {
    bool ans = true;
    unsigned int i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant ans == 1 <==> all_even_divisible_by_3_or_5(a_vec, n, i);
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n) {
        unsigned int a = a_vec[i];
        if (a % 2 == 0) {
            if (!(a % 3 == 0 || a % 5 == 0)) {
                ans = false;
            }
        }
        i++;
    }
    return ans;
}

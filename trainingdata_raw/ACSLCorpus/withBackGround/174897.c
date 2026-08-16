#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

/*@ predicate valid_array(int *arr, integer n) =
    n >= 1 && n <= 200000 &&
    \forall integer i; 0 <= i < n ==> 1 <= arr[i] && arr[i] <= 1000000000;
*/

/*@ predicate count_in_range(integer count, integer idx, integer n) =
    count >= 0 && count <= idx && idx <= n;
*/

/*@ lemma count_non_negative:
    \forall integer count, integer idx, integer n;
    count_in_range(count, idx, n) ==> count >= 0;
*/

/*@ lemma count_bounded_by_n:
    \forall integer count, integer idx, integer n;
    count_in_range(count, idx, n) && idx == n ==> count <= n;
*/

/*@
    requires n >= 1 && n <= 200000;
    requires \valid_read(a + (0 .. n-1));
    requires valid_array(a, n);
    assigns \nothing;
    ensures \result >= 0 && \result <= n;
*/
int func(int n, int *a) {
    int prev = INT_MAX;
    int count = 0;
    int index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant count_in_range(count, index, n);
        loop invariant valid_array(a, n);
        loop invariant n >= 1 && n <= 200000;
        loop assigns prev, count, index;
        loop variant n - index;
    */
    while (index < n) {
        int a_i = a[index];
        
        //@ assert 1 <= a_i && a_i <= 1000000000;
        
        if (a_i < prev) {
            //@ assert count + 1 >= 0;
            //@ assert count + 1 <= index + 1;
            count += 1;
            prev = a_i;
        }
        //@ assert count_in_range(count, index + 1, n);
        index += 1;
    }
    
    //@ assert count_in_range(count, n, n);
    //@ assert count <= n;
    return count;
}

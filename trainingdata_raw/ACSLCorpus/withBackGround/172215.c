#include <stdbool.h>

/*@
    predicate valid_array(int *arr, integer n) =
        n > 0 && n <= 20 &&
        \valid(arr + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> 1 <= arr[i] <= 100;

    predicate first_loop_invariant(int *arr, integer n, integer idx, integer max_h) =
        0 <= idx <= n &&
        valid_array(arr, n) &&
        \forall integer i; 0 <= i < idx ==> max_h >= arr[i];

    predicate second_loop_invariant(int *arr, integer n, integer idx, integer cnt, integer max_h) =
        0 <= idx <= n &&
        valid_array(arr, n) &&
        cnt >= 0 &&
        cnt <= idx &&
        \forall integer i; 0 <= i < idx ==> (arr[i] >= max_h ==> cnt > 0);
*/

/*@
    requires valid_array(h, n);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n, int *h) {
    int max_h = 0;
    int index = 0;
    
    /*@
        loop invariant first_loop_invariant(h, n, index, max_h);
        loop assigns max_h, index;
        loop variant n - index;
    */
    while (index < n) {
        int x = h[index];
        //@ assert 1 <= x <= 100;
        if (x > max_h) {
            max_h = x;
        }
        //@ assert max_h >= x;
        index++;
    }
    
    int count = 0;
    index = 0;
    
    /*@
        loop invariant second_loop_invariant(h, n, index, count, max_h);
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n) {
        int x = h[index];
        //@ assert 1 <= x <= 100;
        if (x >= max_h) {
            count++;
        }
        //@ assert count >= 0 && count <= index + 1;
        index++;
    }
    
    //@ assert count >= 0 && count <= n;
    return count;
}

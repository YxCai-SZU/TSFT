#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_range(int *arr, integer n) =
      n >= 1 && n <= 200000 &&
      \forall integer i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= 1000000000;
*/

/*@ predicate loop_invariant(int *arr, integer n, integer idx, integer cnt, integer x) =
      idx >= 0 && idx <= n &&
      cnt >= 0 && cnt <= idx &&
      (idx > 0 ==> \forall integer i; 0 <= i < idx ==> arr[i] >= 1 && arr[i] <= 1000000000) &&
      n >= 1 && n <= 200000;
*/

/*@ lemma cnt_bound: \forall integer idx, integer cnt; 
      idx >= 0 && cnt >= 0 && cnt <= idx ==> cnt >= 0 && cnt <= idx; */

/*@ requires n >= 1 && n <= 200000;
    requires \valid(a_vec + (0 .. n-1));
    requires is_valid_range(a_vec, n);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n, int *a_vec) {
    int count = 0;
    int x = 0;
    size_t index = 0;
    
    /*@ loop invariant loop_invariant(a_vec, n, index, count, x);
        loop assigns count, x, index;
        loop variant n - index;
    */
    while (index < (size_t)n && x >= 0) {
        int a = a_vec[index];
        
        //@ assert a >= 1 && a <= 1000000000;
        
        if (x < a) {
            count++;
            x = a;
        } else {
            x = a;
        }
        
        //@ assert count <= index + 1;
        index++;
    }
    
    //@ assert count >= 0 && count <= n;
    return count;
}

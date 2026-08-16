#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_range(integer n) = 1 <= n <= 1000000; */
/*@ predicate valid_array(int *arr, integer n) = 
      \forall integer i; 0 <= i < n ==> 1 <= arr[i] <= 1000000; */
/*@ predicate count_bounds(integer cnt, integer idx) = 
      0 <= cnt <= idx; */

/*@ lemma index_bounds: 
      \forall integer n, integer idx; 
      valid_range(n) && 0 <= idx <= n ==> 0 <= idx; */

/*@ requires valid_range(n);
    requires \valid(v + (0 .. n-1));
    requires valid_array(v, n);
    ensures 0 <= \result <= n;
    assigns \nothing;
 */
int func(int n, int *v) {
    int before;
    int count;
    size_t index;
    
    before = 0;
    count = 0;
    index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant count_bounds(count, index);
        loop invariant valid_range(n);
        loop invariant valid_array(v, n);
        loop assigns before, count, index;
        loop variant n - index;
     */
    while (index < (size_t)n) {
        int a;
        
        a = v[index];
        
        //@ assert 1 <= a <= 1000000;
        
        if (before >= a) {
            before = a;
            count = count + 1;
        }
        
        //@ assert count_bounds(count, index + 1);
        index = index + 1;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}

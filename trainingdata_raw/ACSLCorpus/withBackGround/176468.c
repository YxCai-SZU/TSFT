#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_array(int *a, size_t n) =
        n >= 1 && n <= 100 &&
        \forall integer i; 0 <= i < n ==> 1 <= a[i] && a[i] <= 100;

    logic integer count_condition(integer idx, integer val) =
        (idx + 1) % 2 == 0 && val % 2 == 1 ? 1 : 0;

    lemma count_bounds:
        \forall integer idx, integer cnt;
        0 <= idx && cnt >= 0 && cnt <= idx ==>
        cnt + count_condition(idx, 1) >= 0 &&
        cnt + count_condition(idx, 1) <= idx + 1;
*/

/*@
    requires n >= 1 && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires valid_array(a, n);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(size_t n, int *a) {
    int count = 0;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant valid_array(a, n);
        loop assigns index, count;
        loop variant n - index;
    */
    while (index < n) {
        int ai = a[index];
        
        //@ assert 1 <= ai <= 100;
        
        if ((index + 1) % 2 == 0 && ai % 2 == 1) {
            //@ assert count_condition(index, ai) == 1;
            count += 1;
        } else {
            //@ assert count_condition(index, ai) == 0;
        }
        
        //@ assert 0 <= count <= index + 1;
        index += 1;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}

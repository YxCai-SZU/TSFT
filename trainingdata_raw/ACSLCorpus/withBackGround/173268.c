#include <stdbool.h>
#include <limits.h>

/*@ predicate is_positive(integer x) = x > 0;
    predicate is_within_range(integer x) = x > 0 && x <= 1000000000;
    predicate valid_array(int *a, integer n) = 
        n > 0 && n <= 200000 &&
        \forall integer i; 0 <= i < n ==> is_within_range(a[i]);
    predicate loop_invariant(int *a, integer n, integer index, integer count) =
        0 <= index <= n &&
        0 <= count <= index &&
        valid_array(a, n);
*/

/*@
    requires n > 0 && n <= 200000;
    requires \valid(a + (0..n-1));
    requires valid_array(a, n);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(int n, int *a) {
    int before = INT_MAX;
    int count = 0;
    int index = 0;
    
    /*@
        loop invariant loop_invariant(a, n, index, count);
        loop invariant index > 0 ==> \forall integer i; 0 <= i < index ==> is_within_range(a[i]);
        loop assigns before, count, index;
        loop variant n - index;
    */
    while (index < n) {
        int ai = a[index];
        
        //@ assert is_within_range(ai);
        
        if (before >= ai) {
            before = ai;
        } else {
            count += 1;
            before = ai;
        }
        
        //@ assert 0 <= count <= index + 1;
        index += 1;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}

/*@ lemma count_bounds: 
        \forall int *a, integer n; 
        valid_array(a, n) ==> 
        (\forall integer count; 0 <= count <= n ==> 0 <= count <= n); 
*/

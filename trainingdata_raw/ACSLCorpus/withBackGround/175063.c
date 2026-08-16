#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_index(integer i, integer n) = 0 <= i < n; */
/*@ predicate is_valid_value(integer v) = 1 <= v <= 100; */
/*@ predicate is_valid_array(int *arr, integer n) = 
      \forall integer i; 0 <= i < n ==> is_valid_value(arr[i]); */

/*@ lemma ans_bounds: 
      \forall integer n, integer i, integer ans; 
      1 <= n <= 100 && 0 <= i <= n && 0 <= ans <= i ==> 0 <= ans <= n; */

/*@ requires 1 <= n <= 100;
    requires \valid(a + (0 .. n-1));
    requires is_valid_array(a, n);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(int n, int *a) {
    int ans = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= ans <= i;
        loop invariant is_valid_array(a, n);
        loop assigns i, ans;
    */
    while (i < n) {
        int ai = a[i];
        
        //@ assert is_valid_value(ai);
        
        if (((i + 1) & 1) != 0 && (ai & 1) != 0) {
            ans += 1;
        }
        
        //@ assert 0 <= ans <= i+1;
        i += 1;
    }
    
    //@ assert 0 <= ans <= n;
    return ans;
}

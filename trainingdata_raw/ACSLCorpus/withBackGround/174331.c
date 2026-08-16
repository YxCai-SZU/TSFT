#include <stdbool.h>

/*@ predicate valid_vec(int *v, integer len) =
    len == 5 &&
    \forall integer i; 0 <= i < len ==> 0 <= v[i] && v[i] <= 123;
*/

/*@ predicate all_in_range(int *v, integer len, integer k) =
    \forall integer x; 0 <= x < len ==> (v[x] >= k || v[x] <= k + 1);
*/

/*@ lemma k_in_range: \forall integer k; 0 <= k && k <= 123 ==> 0 <= k && k <= 123; */

/*@
    requires \valid(v + (0 .. 4));
    requires valid_vec(v, 5);
    requires 0 <= k && k <= 123;
    ensures \result == true <==> all_in_range(v, 5, k);
    assigns \nothing;
*/
bool func(int *v, int k) {
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant \forall integer x; 0 <= x < i ==> (v[x] >= k || v[x] <= k + 1);
        loop invariant valid_vec(v, 5);
        loop invariant 0 <= k && k <= 123;
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        int a = v[i];
        
        //@ assert a >= 0 && a <= 123;
        
        i = i + 1;
    }
    
    //@ assert all_in_range(v, 5, k);
    return true;
}

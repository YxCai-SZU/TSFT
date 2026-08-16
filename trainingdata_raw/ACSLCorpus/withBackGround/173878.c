#include <stddef.h>

/*@
    predicate is_valid_array(size_t n, long long *p) =
        n >= 1 && n <= 200000 &&
        \valid(p + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> p[i] >= 1 && p[i] <= n &&
        \forall integer i, j; 0 <= i < j < n ==> p[i] != p[j];
*/

/*@
    lemma array_properties_preserved:
        \forall size_t n, long long *p, integer k;
        is_valid_array(n, p) && 0 <= k < n ==>
            \forall integer i; 0 <= i < k ==> p[i] >= 1 && p[i] <= n &&
            \forall integer i, j; 0 <= i < j < k ==> p[i] != p[j];
*/

/*@
    requires is_valid_array(n, p);
    ensures 1 <= \result <= n;
    assigns \nothing;
*/
int func(size_t n, long long *p) {
    int result = 1;
    size_t index = 1;
    long long p_min = p[0];
    
    /*@
        loop invariant 1 <= index <= n;
        loop invariant 1 <= result <= index;
        loop invariant p_min >= 1 && p_min <= n;
        loop invariant \forall integer i; 0 <= i < index ==> p[i] >= 1 && p[i] <= n;
        loop invariant \forall integer i, j; 0 <= i < j < index ==> p[i] != p[j];
        loop assigns index, result, p_min;
        loop variant n - index;
    */
    while (index < n) {
        long long p_index = p[index];
        
        //@ assert p_index >= 1 && p_index <= n;
        //@ assert \forall integer i; 0 <= i < index ==> p[i] != p_index;
        
        if (p_index < p_min) {
            p_min = p_index;
            result += 1;
        }
        index += 1;
    }
    
    //@ assert 1 <= result <= n;
    return result;
}

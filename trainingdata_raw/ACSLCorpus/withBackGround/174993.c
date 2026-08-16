#include <stddef.h>

/*@
    predicate valid_params(size_t n, int *p) =
        n >= 1 && n <= 200000 &&
        \valid(p + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> p[i] >= 1 && p[i] <= (int)n &&
        \forall integer i, j; 0 <= i < j < n ==> p[i] != p[j];
*/

/*@
    lemma count_bound: \forall size_t n, int *p, size_t idx; 
        valid_params(n, p) && idx <= n ==> idx <= n;
*/

/*@
    requires valid_params(n, p);
    ensures \result <= n;
    assigns \nothing;
*/
size_t func(size_t n, int *p) {
    size_t count = 0;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop assigns index, count;
        loop variant n - index;
    */
    while (index < n) {
        size_t left = index;
        size_t right = index;
        
        /*@
            loop invariant 0 <= left <= index;
            loop assigns left;
            loop variant left;
        */
        while (left > 0 && p[left - 1] >= p[index]) {
            //@ assert left > 0;
            left -= 1;
        }
        
        /*@
            loop invariant index <= right < n;
            loop assigns right;
            loop variant n - right - 1;
        */
        while (right < n - 1 && p[right + 1] >= p[index]) {
            //@ assert right < n - 1;
            right += 1;
        }
        
        count += 1;
        //@ assert count <= index + 1;
        index = right + 1;
        //@ assert count <= index;
    }
    
    //@ assert count <= n;
    return count;
}

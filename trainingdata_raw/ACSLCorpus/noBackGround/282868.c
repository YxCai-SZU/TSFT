#include <stddef.h>
#include <stdint.h>

/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \valid((p) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (int64_t)(n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    assigns \nothing;
    ensures 1 <= \result <= n;
*/
int32_t func(size_t n, const int64_t *p) {
    int32_t result = 1;
    size_t index = 1;
    int64_t min_bound = p[0];
    
    /*@
        loop invariant 1 <= index <= n;
        loop invariant 1 <= result <= index;
        loop invariant ((n) >= 1 && (n) <= 200000 &&
        \valid((p) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (int64_t)(n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
        loop invariant min_bound >= 1 && min_bound <= (int64_t)n;
        loop invariant \forall integer k; 0 <= k < index ==> p[k] >= 1 && p[k] <= (int64_t)n;
        loop assigns index, result, min_bound;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert p[index] >= 1 && p[index] <= (int64_t)n;
        
        if (p[index] <= min_bound) {
            min_bound = p[index];
            result += 1;
        }
        
        index += 1;
    }
    
    //@ assert 1 <= result <= n;
    return result;
}

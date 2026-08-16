#include <stddef.h>
#include <stdint.h>

/*@
    requires 3 <= N <= 20;
    requires \valid(p + (0 .. N-1));
    requires (((N)) == (N) &&
        3 <= (N) <= 20 &&
        \forall size_t k; 0 <= k < ((N)) ==> 1 <= (p)[k] <= (int64_t)(N) &&
        \forall size_t k, size_t l; 0 <= k < l < ((N)) ==> (p)[k] != (p)[l]);
    assigns \nothing;
    ensures 0 <= \result <= (int64_t)(N - 2);
*/
int64_t func(size_t N, const int64_t* p) {
    int64_t count = 0;
    size_t i = 1;
    
    /*@
        loop invariant 1 <= i <= N - 1;
        loop invariant 0 <= count <= (int64_t)(i - 1);
        loop invariant (((N)) == (N) &&
        3 <= (N) <= 20 &&
        \forall size_t k; 0 <= k < ((N)) ==> 1 <= (p)[k] <= (int64_t)(N) &&
        \forall size_t k, size_t l; 0 <= k < l < ((N)) ==> (p)[k] != (p)[l]);
        loop assigns i, count;
        loop variant N - i;
    */
    while (i < N - 1) {
        int64_t p_i_minus_1 = p[i - 1];
        int64_t p_i = p[i];
        int64_t p_i_plus_1 = p[i + 1];
        
        //@ assert p_i_minus_1 != p_i && p_i != p_i_plus_1;
        
        if (p_i_minus_1 < p_i && p_i < p_i_plus_1) {
            count += 1;
        }
        if (p_i_minus_1 > p_i && p_i > p_i_plus_1) {
            count += 1;
        }
        i += 1;
    }
    
    //@ assert count <= (int64_t)(N - 2);
    return count;
}

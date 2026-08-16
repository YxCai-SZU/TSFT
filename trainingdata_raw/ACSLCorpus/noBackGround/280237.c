#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 3 && (n) <= 20 &&
        \forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (int)(n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    ensures \result >= 0 && \result <= (int)n - 2;
    assigns \nothing;
*/
int func(size_t n, int* p) {
    int ans = 0;
    size_t i = 1;
    
    //@ ghost int* ghost_p = p;
    //@ ghost size_t ghost_n = n;
    
    /*@ loop invariant 1 <= i <= n - 1;
        loop invariant ((ghost_n) >= 3 && (ghost_n) <= 20 &&
        \forall integer i; 0 <= i < (ghost_n) ==> (ghost_p)[i] >= 1 && (ghost_p)[i] <= (int)(ghost_n) &&
        \forall integer i, j; 0 <= i < j < (ghost_n) ==> (ghost_p)[i] != (ghost_p)[j]);
        loop invariant ((ans) >= 0 && (ans) <= (i) - 1 && (i) < (ghost_n));
        loop invariant i < ghost_n;
        loop assigns ans, i;
        loop variant ghost_n - i;
    */
    while (i < n - 1) {
        int p_im1 = p[i - 1];
        int p_i = p[i];
        int p_ip1 = p[i + 1];
        
        //@ assert p_im1 >= 1 && p_im1 <= (int)ghost_n;
        //@ assert p_i >= 1 && p_i <= (int)ghost_n;
        //@ assert p_ip1 >= 1 && p_ip1 <= (int)ghost_n;
        //@ assert p_im1 != p_i && p_i != p_ip1 && p_im1 != p_ip1;
        
        if ((p_im1 < p_i && p_i < p_ip1) || (p_im1 > p_i && p_i > p_ip1)) {
            ans += 1;
        }
        
        //@ assert ((ans) >= 0 && (ans) <= (i + 1) - 1 && (i + 1) < (ghost_n));
        i += 1;
    }
    
    //@ assert ans >= 0 && ans <= (int)ghost_n - 2;
    return ans;
}

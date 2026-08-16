#include <stdbool.h>
#include <stddef.h>

/*@ requires n >= 0 && \valid(an + (0 .. n-1));
    requires m >= 0 && \valid(bn + (0 .. m-1));
    requires (\forall integer i, j; 0 <= i < j < (m) ==> (bn)[i] != (bn)[j]);
    ensures \result >= 0 && \result <= m;
*/
int func(int n, int* an, int m, int* bn) {
    int ans = 0;
    size_t index = 0;
    
    //@ ghost int* an_ghost = an;
    //@ ghost int* bn_ghost = bn;
    //@ ghost int n_ghost = n;
    //@ ghost int m_ghost = m;
    
    /*@ loop invariant 0 <= index <= m;
        loop invariant ans >= 0;
        loop invariant ans <= (int)index;
        loop invariant (\forall integer i, j; 0 <= i < j < (m_ghost) ==> (bn_ghost)[i] != (bn_ghost)[j]);
        loop invariant n_ghost >= 0;
        loop invariant m_ghost >= 0;
        loop assigns ans, index;
        loop variant m - index;
    */
    while (index < (size_t)m) {
        int v = bn[index];
        bool found = false;
        size_t an_index = 0;
        
        /*@ loop invariant 0 <= an_index <= n_ghost;
            loop invariant found == false || found == true;
            loop invariant (\forall integer i, j; 0 <= i < j < (m_ghost) ==> (bn_ghost)[i] != (bn_ghost)[j]);
            loop invariant n_ghost >= 0;
            loop invariant m_ghost >= 0;
            loop assigns found, an_index;
            loop variant n_ghost - an_index;
        */
        while (an_index < (size_t)n) {
            if (an[an_index] == v) {
                found = true;
                break;
            }
            an_index++;
        }
        
        if (found) {
            ans++;
        }
        index++;
    }
    return ans;
}

#include <stdbool.h>
#include <stddef.h>

/*@
   requires 2 <= n <= 50;
   requires \valid(p + (0 .. n-1));
   requires (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
   requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= (n));
   assigns \nothing;
   ensures \result <= n - 2;
*/
size_t func(size_t n, int *p) {
    size_t count = 0;
    size_t i = 1;

    /*@
       loop invariant 1 <= i <= n - 1;
       loop invariant count <= i - 1;
       loop assigns i, count;
       loop variant n - i;
    */
    while (i < n - 1) {
        int p_i_minus_1 = p[i - 1];
        int p_i = p[i];
        int p_i_plus_1 = p[i + 1];

        //@ assert 0 <= i - 1 < n;
        
        if ((p_i_minus_1 < p_i && p_i < p_i_plus_1) || 
            (p_i_minus_1 > p_i && p_i > p_i_plus_1)) {
            count += 1;
        }
        
        //@ assert count <= i;
        i += 1;
    }
    
    //@ assert count <= n - 2;
    return count;
}

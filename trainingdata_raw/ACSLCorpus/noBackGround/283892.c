#include <stdbool.h>

/*@
    requires 3 <= n <= 20;
    requires \valid(p+(0..n-1));
    requires (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= (n));
    ensures 0 <= \result <= n-2;
    assigns \nothing;
*/
int func(int n, int *p) {
    int count = 0;
    unsigned int i = 1;
    
    /*@
        loop invariant 1 <= i <= n-1;
        loop invariant (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= (n));
        loop invariant 0 <= count <= i-1;
        loop assigns i, count;
        loop variant n-i;
    */
    while (i < (unsigned int)(n - 1)) {
        unsigned int i_1 = i + 1;
        unsigned int i_2 = i - 1;
        
        //@ assert i_1 < n;
        //@ assert i_2 < n;
        
        if ((p[i_2] < p[i] && p[i] < p[i_1]) || 
            (p[i_2] > p[i] && p[i] > p[i_1])) {
            count += 1;
        }
        i += 1;
    }
    return count;
}

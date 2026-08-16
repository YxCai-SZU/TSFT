#include <stddef.h>
#include <stdbool.h>

/*@
    requires (3 <= (n) <= 20);
    requires \valid(p + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= (n));
    requires (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    assigns \nothing;
    ensures \result <= n-2;
*/
size_t func(size_t n, int *p) {
    size_t count = 0;
    size_t i = 1;
    
    /*@
        loop invariant 1 <= i <= n-1;
        loop invariant count <= i-1;
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= (n));
        loop invariant (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
        loop invariant (3 <= (n) <= 20);
        loop assigns i, count;
        loop variant n-i;
    */
    while (i < n - 1) {
        int p1 = p[i - 1];
        int p2 = p[i];
        int p3 = p[i + 1];
        
        //@ assert 0 <= i-1 < n && 0 <= i < n && 0 <= i+1 < n;
        
        if ((p1 < p2 && p2 < p3) || (p1 > p2 && p2 > p3)) {
            //@ assert (((p1) < (p2) && (p2) < (p3)) || ((p1) > (p2) && (p2) > (p3)));
            count += 1;
        }
        
        i += 1;
    }
    
    //@ assert count <= n-2;
    return count;
}

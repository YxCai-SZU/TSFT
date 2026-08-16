#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_vector(int *v, integer n) =
        n >= 3 && n <= 200000 &&
        \forall integer i; 0 <= i < n ==> 
            (*(v + i) == i + 1 || *(v + i) == -(i + 1));

    lemma vector_property:
        \forall int *v, integer n; valid_vector(v, n) ==>
            \forall integer i; 0 <= i < n ==> 
                (*(v + i) == i + 1 || *(v + i) == -(i + 1));
*/

/*@
    requires \valid(v + (0 .. n-1));
    requires n >= 3 && n <= 200000;
    requires valid_vector(v, n);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(size_t n, const int *v) {
    int m = 0;
    int p = 0;
    size_t i = 0;
    
    //@ assert m >= 0;
    //@ assert p >= 0;
    //@ assert p <= (int)i;
    
    /*@
        loop invariant 0 <= i <= n - 1;
        loop invariant 3 <= n <= 200000;
        loop invariant valid_vector(v, n);
        loop invariant m >= 0;
        loop invariant p >= 0;
        loop invariant p <= (int)i;
        loop assigns m, p, i;
        loop variant n - i;
    */
    while (i < n - 1) {
        int x = v[i];
        int y = v[i + 1];
        
        //@ assert x == i + 1 || x == -(i + 1);
        //@ assert y == (i + 1) + 1 || y == -((i + 1) + 1);
        
        if (x == y) {
            p += 1;
            //@ assert p >= 0;
        } else if (x < y) {
            //@ assert m >= 0;
            m = (m < p) ? m : p;
            //@ assert m >= 0;
            p = 0;
        } else {
            p = 0;
        }
        i += 1;
        //@ assert p <= (int)i;
    }
    
    //@ assert m >= 0;
    //@ assert p >= 0;
    m = (m < p) ? m : p;
    //@ assert m >= 0;
    return m;
}

#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((len) >= 3 && \valid((a) + (0 .. (len)-1)));
    ensures \result == ((\at((a)[(0)], Here)) < (\at((a)[(1)], Here)) && (\at((a)[(1)], Here)) < (\at((a)[(2)], Here)));
    assigns \nothing;
*/
bool func(int *a, size_t len) {
    int x0;
    int x1;
    int x2;
    
    //@ assert ((len) >= 3 && \valid((a) + (0 .. (len)-1)));
    x0 = a[0];
    x1 = a[1];
    x2 = a[2];
    
    //@ assert x0 == (\at((a)[(0)], Here));
    //@ assert x1 == (\at((a)[(1)], Here));
    //@ assert x2 == (\at((a)[(2)], Here));
    
    return x0 < x1 && x1 < x2;
}

/*@
    requires ((len) >= 3 && \valid((a) + (0 .. (len)-1)));
    ensures \result == ((\at((a)[(0)], Here)) < (\at((a)[(1)], Here)) && (\at((a)[(1)], Here)) < (\at((a)[(2)], Here)));
    assigns \nothing;
*/
bool func_odd_even(int *a, size_t len) {
    int x0;
    int x1;
    int x2;
    
    //@ assert ((len) >= 3 && \valid((a) + (0 .. (len)-1)));
    x0 = a[0];
    x1 = a[1];
    x2 = a[2];
    
    //@ assert x0 == x0 && x1 == x1 && x2 == x2;
    
    return x0 < x1 && x1 < x2;
}

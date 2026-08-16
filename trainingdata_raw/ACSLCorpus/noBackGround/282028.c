#include <stddef.h>
#include <stdbool.h>

/*@
    requires n > 0 && n <= 100;
    requires \valid(v + (0 .. n-1));
    requires ((n) > 0 && (n) <= 100 &&
        \forall size_t i; 0 <= i < (n) ==> (v)[i] > 0 && (v)[i] <= 100);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(size_t n, int *v) {
    int a;
    size_t i;
    
    //@ assert n > 0 && n <= 100;
    //@ assert ((n) > 0 && (n) <= 100 &&         \forall size_t i; 0 <= i < (n) ==> (v)[i] > 0 && (v)[i] <= 100);
    
    a = v[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant a >= 0;
        loop invariant ((n) > 0 && (n) <= 100 &&
        \forall size_t i; 0 <= i < (n) ==> (v)[i] > 0 && (v)[i] <= 100);
        loop invariant n > 0 && n <= 100;
        loop invariant a <= 100;
        loop assigns a, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert v[i] > 0 && v[i] <= 100;
        //@ assert a >= 0;
        
        if (a < v[i]) {
            a = a;
        } else {
            a = v[i];
        }
        
        //@ assert a >= 0;
        //@ assert a <= 100;
        
        i = i + 1;
    }
    
    //@ assert a >= 0;
    return a;
}

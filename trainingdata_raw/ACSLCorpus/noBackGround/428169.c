#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) > 0 && \valid((a) + (0 .. (n)-1)));
    ensures \exists integer i; 0 <= i < n && \result == ((a)[(i)]);
    ensures \forall integer i; 0 <= i < n ==> ((a)[(i)]) <= \result;
*/
int max_element(int *a, size_t n) {
    // Variable declarations at top of scope
    int max;
    size_t i;
    
    //@ assert n > 0;
    max = a[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant n > 0;
        loop invariant (\exists integer j; (0) <= j < (i) && (((a))[(j)]) == (max));
        loop invariant (\forall integer j; (0) <= j < (i) ==> (((a))[(j)]) <= (max));
        loop assigns max, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (a[i] > max) {
            max = a[i];
        }
        i = i + 1;
    }
    
    //@ assert (\exists integer j; (0) <= j < (n) && (((a))[(j)]) == (max));
    //@ assert (\forall integer j; (0) <= j < (n) ==> (((a))[(j)]) <= (max));
    return max;
}

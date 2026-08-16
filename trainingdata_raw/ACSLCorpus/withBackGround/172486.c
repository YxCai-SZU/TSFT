#include <stdbool.h>
#include <stddef.h>

/*@
    predicate zero_vector(int *arr, integer len) =
        \forall integer j; 0 <= j < len ==> arr[j] == 0;
*/

/*@
    requires 1 <= n <= 10000;
    requires 1 <= m <= 10000;
    ensures \result == (n * 2 < m);
*/
bool func(unsigned int n, unsigned int m) {
    int v[10000];
    unsigned int i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant zero_vector(&v[0], i);
        loop invariant 1 <= n <= 10000;
        loop invariant 1 <= m <= 10000;
        loop assigns i, v[0..n-1];
        loop variant n - i;
    */
    while (i < n) {
        v[i] = 0;
        i++;
    }
    
    //@ assert zero_vector(&v[0], n);
    
    return n * 2 < m;
}

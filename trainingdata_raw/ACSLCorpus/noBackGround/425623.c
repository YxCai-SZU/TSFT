#include <stdbool.h>
#include <stddef.h>

/*@ requires n >= 3 && n <= 200000;
    requires \valid(v + (0..n-1));
    requires (\forall integer i, j; 0 <= i < j < (n) ==> (v)[i] != (v)[j]);
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (v)[i] && (v)[i] <= (n));
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
size_t func(size_t n, const size_t v[]) {
    size_t count = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant count <= i;
        loop invariant (\forall integer i, j; 0 <= i < j < (n) ==> (v)[i] != (v)[j]);
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (v)[i] && (v)[i] <= (n));
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n - 2) {
        //@ assert i < n - 2;
        
        if (v[i] < v[i + 1] && v[i + 1] < v[i + 2]) {
            count++;
        }
        
        if (v[i] > v[i + 1] && v[i + 1] > v[i + 2]) {
            count++;
        }
        
        i++;
    }
    
    return count;
}

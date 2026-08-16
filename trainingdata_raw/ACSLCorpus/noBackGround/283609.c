#include <stdbool.h>
#include <stdint.h>

/*@ requires 3 <= n <= 200000;
    requires \valid(v + (0 .. n-1));
    requires (\forall integer i, j; 0 <= i < j < (n) ==> (v)[i] != (v)[j]);
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (v)[i] && (v)[i] <= (n));
    assigns \nothing;
    ensures \result <= n-2;
*/
uint32_t func(uint32_t n, int32_t *v) {
    uint32_t count = 0;
    uint32_t a = 1;
    
    /*@ loop invariant 1 <= a <= n-1;
        loop invariant count <= a-1;
        loop invariant (\forall integer i, j; 0 <= i < j < (n) ==> (v)[i] != (v)[j]);
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (v)[i] && (v)[i] <= (n));
        loop invariant 3 <= n <= 200000;
        loop assigns count, a;
        loop variant n-a;
    */
    while (a < n-1) {
        //@ assert 1 <= a && a < n;
        
        if ((v[a-1] < v[a] && v[a] < v[a+1]) || 
            (v[a-1] > v[a] && v[a] > v[a+1])) {
            count = count + 1;
        }
        a = a + 1;
    }
    return count;
}

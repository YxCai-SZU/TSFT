#include <stddef.h>

/*@ requires n >= 3 && n <= 200000;
    requires \valid(ps + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= ps[i] <= n;
    requires \forall integer i, j; 0 <= i < j < n ==> ps[i] != ps[j];
    ensures \result <= n - 2;
    assigns \nothing;
*/
size_t func(size_t n, int *ps) {
    size_t count = 0;
    size_t index = 1;
    
    /*@ loop invariant 1 <= index <= n-1;
        loop invariant count <= index - 1;
        loop invariant ((n) >= 3 && (n) <= 200000 &&
    \valid((ps) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> 1 <= (ps)[i] <= (n) &&
    \forall integer i, j; 0 <= i < j < (n) ==> (ps)[i] != (ps)[j]);
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n - 1) {
        int p = ps[index];
        int max_val;
        int min_val;
        
        if (p < ps[index - 1]) {
            if (ps[index + 1] < ps[index - 1]) {
                max_val = ps[index - 1];
            } else {
                max_val = ps[index + 1];
            }
            min_val = p;
        } else {
            if (ps[index + 1] < p) {
                max_val = p;
            } else {
                max_val = ps[index + 1];
            }
            min_val = ps[index - 1];
        }
        
        //@ assert max_val >= min_val;
        if (max_val - min_val == 1) {
            count++;
        }
        
        index++;
        //@ assert count <= index - 1;
    }
    
    //@ assert count <= n - 2;
    return count;
}

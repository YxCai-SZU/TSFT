#include <stdbool.h>
#include <stddef.h>

/*@ requires n > 0 && n <= 200000;
    requires \valid(p + (0 .. n-1));
    requires (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= (n));
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n, int *p) {
    int count = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant count >= 0;
        loop invariant count <= (int)index;
        loop invariant (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= (n));
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < (size_t)n) {
        int item = p[index];
        
        //@ assert (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
        //@ assert (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= (n));
        
        if ((int)index >= item - 1) {
            //@ assert count >= 0;
            count += 1;
            //@ assert count >= 0;
        }
        
        //@ assert count <= (int)index + 1;
        index += 1;
    }
    
    //@ assert count >= 0;
    //@ assert count <= n;
    return count;
}

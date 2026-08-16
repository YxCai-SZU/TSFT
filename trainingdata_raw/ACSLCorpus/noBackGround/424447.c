#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 1 && (n) <= 200000 &&
      \valid((p) + (0 .. (n)-1)) &&
      (\forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (n)) &&
      (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]));
    ensures \result >= 1 && \result <= n;
    assigns \nothing;
*/
int func(int n, int *p) {
    int min;
    int count;
    size_t index;
    
    //@ assert n >= 1 && n <= 200000;
    
    min = p[0];
    count = 1;
    index = 1;
    
    /*@ loop invariant 1 <= index <= (size_t)n;
        loop invariant 1 <= count <= (int)index;
        loop invariant \forall integer i; 0 <= i < n ==> p[i] >= 1 && p[i] <= n;
        loop invariant \forall integer i, j; 0 <= i < j < n ==> p[i] != p[j];
        loop assigns min, count, index;
        loop variant n - index;
    */
    while (index < (size_t)n) {
        int i = p[index];
        
        //@ assert i >= 1 && i <= n;
        
        if (i <= min) {
            //@ assert count >= 1;
            count += 1;
            min = i;
        }
        
        index += 1;
    }
    
    //@ assert count >= 1;
    //@ assert count <= n;
    return count;
}

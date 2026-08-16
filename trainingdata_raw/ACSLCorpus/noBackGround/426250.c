#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid(a + (0 .. len-1));
    requires ((len) >= 3 && (len) <= 200000 &&
    \forall integer i; 0 <= i < (len) ==> ((a)[i] == 0 || (a)[i] == 1));
    ensures \result >= 0;
    ensures \result <= len - 2;
*/
int func(int *a, size_t len) {
    int count = 0;
    size_t i = 0;
    
    //@ assert ((len) >= 3 && (len) <= 200000 &&     \forall integer i; 0 <= i < (len) ==> ((a)[i] == 0 || (a)[i] == 1));
    
    /*@ loop invariant 0 <= i <= len - 2;
        loop invariant count >= 0;
        loop invariant count <= (int)i;
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len - 2) {
        //@ assert 0 <= i < len - 2;
        
        if (a[i] == 1 && a[i + 1] == 1 && a[i + 2] == 0) {
            count += 1;
        }
        
        i += 1;
    }
    
    return count;
}

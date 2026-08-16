#include <stddef.h>
#include <stdint.h>

/*@
    requires \valid(x + (0 .. 4));
    requires ((5) == 5);
    requires \forall integer i; 0 <= i < 5 ==> ((0 <= (i) < (5)) ==> ((x)[(i)] == (i) + 1 || (x)[(i)] == 0));
    requires (\exists integer i; 0 <= i < (5) && (x)[i] == 0);
    ensures \result > 0;
    ensures \result <= 5;
*/
uint64_t func(int64_t* x) {
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= 5;
        loop invariant ((5) == 5);
        loop invariant \forall integer i; 0 <= i < 5 ==> ((0 <= (i) < (5)) ==> ((x)[(i)] == (i) + 1 || (x)[(i)] == 0));
        loop invariant (\exists integer i; 0 <= i < (5) && (x)[i] == 0);
        loop invariant (\forall integer k; 0 <= k < (index) ==> (x)[k] != 0);
        loop assigns index;
        loop variant 5 - index;
    */
    while (index < 5) {
        //@ assert ((0 <= (index) < (5)) ==> ((x)[(index)] == (index) + 1 || (x)[(index)] == 0));
        
        if (x[index] == 0) {
            //@ assert (\exists integer i; 0 <= i < (5) && (x)[i] == 0);
            return (uint64_t)index + 1;
        }
        
        //@ assert (\forall integer k; 0 <= k < (index + 1) ==> (x)[k] != 0);
        index += 1;
    }
    
    //@ assert !(\exists integer i; 0 <= i < (5) && (x)[i] == 0);
    return 0;
}

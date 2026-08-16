#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(xs + (0 .. 4));
    requires (\forall integer i; 0 <= i < 5 ==> ((xs)[(i)] == (i) + 1 || (xs)[(i)] == 0));
    requires (\exists integer i; 0 <= i < 5 && xs[i] == 0);
    ensures \result >= 1 && \result <= 5;
    ensures xs[\result - 1] == 0;
*/
int func(long long *xs) {
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant \valid(xs + (0 .. 4));
        loop invariant (\forall integer j; 0 <= j < i ==> xs[j] != 0);
        loop invariant (\exists integer j; i <= j < 5 && xs[j] == 0);
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        
        if (xs[i] == 0) {
            //@ assert xs[i] == 0;
            return i + 1;
        }
        
        //@ assert xs[i] != 0;
        i = i + 1;
    }
    
    return -1;
}


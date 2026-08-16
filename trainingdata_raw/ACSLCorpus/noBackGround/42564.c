#include <stdbool.h>

/*@ requires \valid(input + (0..4));
    requires (\forall integer i; 0 <= i < (5) ==> (((input)[i]) == (i)+1 || ((input)[i]) == 0));
    requires (\exists integer j; 0 <= j < (5) && (input)[j] == 0);
    ensures \result >= 1 && \result <= 5;
    ensures input[\result-1] == 0;
*/
int func(int input[5]) {
    int i = 0;
    
    /*@ loop invariant 0 <= i <= 5;
        loop invariant (\forall integer i; 0 <= i < (5) ==> (((input)[i]) == (i)+1 || ((input)[i]) == 0));
        loop invariant (\exists integer j; 0 <= j < (5) && (input)[j] == 0);
        loop invariant (\forall integer k; 0 <= k < (i) ==> (input)[k] != 0);
        loop invariant i < 5;
        loop assigns i;
    */
    while (i < 5) {
        //@ assert (\forall integer i; 0 <= i < (5) ==> (((input)[i]) == (i)+1 || ((input)[i]) == 0));
        if (input[i] == 0) {
            //@ assert input[i] == 0;
            return i + 1;
        }
        //@ assert input[i] != 0;
        i++;
    }
    
    // This line should never be reached due to preconditions
    return -1;
}

#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(numbers + (0..len-1));
    requires len >= 3;
    requires (\forall integer i; 0 <= i < (len) ==> (numbers)[i] > 0);
    ensures \result == (numbers[1] < numbers[2] && numbers[len-2] < numbers[len-1]);
*/
bool func(int *numbers, size_t len) {
    size_t index;
    
    // First loop
    index = 0;
    /*@
        loop invariant 0 <= index <= len;
        loop invariant (\forall integer i; 0 <= i < (len) ==> (numbers)[i] > 0);
        loop invariant len >= 3;
        loop assigns index;
        loop variant len - index;
    */
    while (index < len) {
        //@ assert (\forall integer i; 0 <= i < (len) ==> (numbers)[i] > 0);
        index++;
    }
    
    if (len < 3) {
        //@ assert len < 3;
        return false;
    }
    
    // Second loop
    index = 0;
    /*@
        loop invariant 0 <= index <= len - 2;
        loop invariant (\forall integer i; 0 <= i < (len) ==> (numbers)[i] > 0);
        loop invariant len >= 3;
        loop assigns index;
        loop variant len - 2 - index;
    */
    while (index < len - 2) {
        //@ assert (\forall integer i; 0 <= i < (len) ==> (numbers)[i] > 0);
        index++;
    }
    
    //@ assert len >= 3;
    return numbers[1] < numbers[2] && numbers[len-2] < numbers[len-1];
}

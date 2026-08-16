#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid(arr + (0 .. 4));
    requires ((5) == 5 &&
      (\forall integer i; 0 <= i < 5 ==> (arr)[i] == i+1 || (arr)[i] == 0) &&
      (\exists integer i; 0 <= i < 5 && (arr)[i] == 0));
    ensures \result > 0 && \result <= 5;
    ensures arr[\result - 1] == 0;
*/
size_t func(int* arr) {
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < 5 ==> arr[j] == j+1 || arr[j] == 0;
        loop invariant \exists integer j; 0 <= j < 5 && arr[j] == 0;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] != 0;
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert i < 5;
        if (arr[i] == 0) {
            //@ assert arr[i] == 0;
            //@ assert i >= 0;
            return i + 1;
        }
        i = i + 1;
    }
    
    //@ assert i == 5;
    //@ assert \forall integer j; 0 <= j < 5 ==> arr[j] != 0;
    //@ assert false;
    return 0;
}

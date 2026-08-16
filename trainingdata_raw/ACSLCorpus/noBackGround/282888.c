#include <stdbool.h>
#include <stddef.h>

/*@
requires \valid(arr + (0 .. len-1));
requires ((len) >= 5 &&
    \forall integer i; 0 <= i < 5 ==> ((arr)[i] == i + 1 || (arr)[i] == 0) &&
    \exists integer i; 0 <= i < 5 && (arr)[i] == 0);
assigns \nothing;
ensures \result == 0 || (1 <= (\result) <= 5 && (arr)[(\result) - 1] == 0);
*/
unsigned int func(int* arr, size_t len) {
    unsigned int i = 0;
    
    /*@
    loop invariant 0 <= i <= 5;
    loop invariant \forall integer j; 0 <= j < i ==> arr[j] != 0;
    loop assigns i;
    loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (arr[i] == 0) {
            //@ assert (1 <= (i + 1) <= 5 && (arr)[(i + 1) - 1] == 0);
            return i + 1;
        }
        i++;
    }
    //@ assert \forall integer j; 0 <= j < 5 ==> arr[j] != 0;
    return 0;
}

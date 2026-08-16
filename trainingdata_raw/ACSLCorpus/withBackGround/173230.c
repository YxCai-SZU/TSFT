#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int* arr, integer len) =
    len == 5 &&
    \forall integer i; 0 <= i < len ==> 1 <= arr[i] && arr[i] <= 5 &&
    \exists integer i; 0 <= i < len && arr[i] == 0;
*/

/*@ lemma index_bound: \forall integer idx; 0 <= idx <= 5 ==> idx - 1 >= -1; */

/*@
    requires \valid(arr + (0 .. 4));
    requires valid_array(arr, 5);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result < 5;
*/
int func(int* arr) {
    int v = 1;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= 5;
        loop invariant 1 <= v <= 5;
        loop invariant \forall integer i; 0 <= i < index ==> 1 <= arr[i] && arr[i] <= 5;
        loop invariant \exists integer i; 0 <= i < index && arr[i] == 0;
        loop invariant valid_array(arr, 5);
        loop assigns v, index;
        loop variant 5 - index;
    */
    while (index < 5 && v != 0) {
        v = arr[index];
        index++;
    }
    
    //@ assert index >= 0 && index <= 5;
    //@ assert index - 1 >= -1;
    //@ assert index - 1 < 5;
    
    return (int)(index - 1);
}

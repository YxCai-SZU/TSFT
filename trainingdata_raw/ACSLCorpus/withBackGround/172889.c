#include <stdbool.h>

/*@ predicate valid_index(integer i, integer size) = 0 <= i < size;
    predicate in_range(integer x) = 1 <= x && x <= 100;
    predicate valid_array(int *arr, integer size) = 
        size == 3 &&
        \forall integer i; valid_index(i, size) ==> in_range(arr[i]);
*/

/*@
    requires \valid_read(arr + (0 .. 2));
    requires valid_array(arr, 3);
    ensures \result == (arr[1] < arr[2] && arr[2] < arr[0] + arr[1]);
*/
bool func(int *arr) {
    int a;
    int b;
    int c;
    
    a = arr[0];
    b = arr[1];
    c = arr[2];
    
    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    
    return b < c && c < a + b;
}

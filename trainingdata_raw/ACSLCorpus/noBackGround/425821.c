#include <stdbool.h>

/*@
    requires \valid_read(arr + (0..2));
    requires (\forall integer i; (0 <= (i) < 3) ==> (1 <= ((arr)[i]) <= 100));
    ensures \result == (arr[1] < arr[0] + arr[2]);
*/
bool func(int *arr) {
    int b;
    int c;
    int d;
    
    b = arr[1];
    c = arr[0];
    d = arr[2];
    
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert (1 <= (d) <= 100);
    
    return b < c + d;
}

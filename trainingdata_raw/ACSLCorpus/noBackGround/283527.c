#include <stdbool.h>

/*@
    requires \valid_read(arr + (0 .. 2));
    requires ((len) >= 3 &&
        \forall integer i; 0 <= i < 3 ==> (1 <= ((arr)[i]) <= 13));
    ensures \result == (((arr[1]) < (arr[0]) && (arr[2]) < (arr[1])) ? 1 : (((arr[1]) < (arr[2]) && (arr[0]) < (arr[1])) ? 1 : 0));
*/
bool func(int *arr, int len) {
    int a;
    int b;
    int c;
    bool result;

    //@ assert ((len) >= 3 &&         \forall integer i; 0 <= i < 3 ==> (1 <= ((arr)[i]) <= 13));
    
    if (len < 3) {
        return false;
    }

    a = arr[0];
    b = arr[1];
    c = arr[2];

    //@ assert (1 <= (a) <= 13);
    //@ assert (1 <= (b) <= 13);
    //@ assert (1 <= (c) <= 13);

    result = (b < a && c < b) || (b < c && a < b);
    
    //@ assert result == (((b) < (a) && (c) < (b)) ? 1 : (((b) < (c) && (a) < (b)) ? 1 : 0));
    return result;
}

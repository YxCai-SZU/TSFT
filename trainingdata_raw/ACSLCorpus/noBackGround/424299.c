#include <stdbool.h>

/*@
    requires \valid(arr + (0 .. 2));
    requires (\forall integer i; 0 <= i < 3 ==> (1 <= ((arr)[i]) <= 13));
    ensures \result == (
        (arr[1] < arr[2] && arr[0] < arr[1]) ||
        (arr[0] < arr[2] && arr[1] == arr[2]) ||
        (arr[0] == arr[1] && arr[2] < arr[1])
    );
    assigns \nothing;
*/
bool func(int *arr) {
    int a;
    int b;
    int c;
    bool result;

    //@ assert (\forall integer i; 0 <= i < 3 ==> (1 <= ((arr)[i]) <= 13));
    a = arr[0];
    b = arr[1];
    c = arr[2];
    
    //@ assert (1 <= (a) <= 13);
    //@ assert (1 <= (b) <= 13);
    //@ assert (1 <= (c) <= 13);
    
    result = (b < c && a < b) || (a < c && b == c) || (a == b && c < b);
    return result;
}

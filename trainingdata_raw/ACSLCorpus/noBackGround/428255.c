#include <stdbool.h>

/*@
    requires \valid(arr + (0 .. 2));
    requires ((3) >= 3 &&
        \forall integer i; 0 <= i < 3 ==> (arr)[i] >= 1 && (arr)[i] <= 9);
    ensures \result == 1 <==> ((arr)[0] < (arr)[1] && (arr)[1] < (arr)[2]);
*/
bool is_increasing_sequence(int *arr) {
    //@ assert arr[0] >= 1 && arr[0] <= 9;
    return arr[0] < arr[1] && arr[1] < arr[2];
}

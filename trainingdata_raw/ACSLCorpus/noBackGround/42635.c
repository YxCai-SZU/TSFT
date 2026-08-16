#include <stdbool.h>

/*@
    requires \valid_read(arr + (0..2));
    requires -100 <= arr[0] <= 100;
    requires -100 <= arr[1] <= 100;
    requires -100 <= arr[2] <= 100;
    ensures \result <==> ((arr[0]) < (arr[1]) && (arr[1]) < (arr[2]));
*/
bool is_increasing(int arr[3]) {
    //@ assert -100 <= arr[0] <= 100;
    //@ assert -100 <= arr[1] <= 100;
    //@ assert -100 <= arr[2] <= 100;
    return arr[0] < arr[1] && arr[1] < arr[2];
}

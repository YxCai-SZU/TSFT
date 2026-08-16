#include <stdbool.h>

/*@
    requires \valid_read(arr + (0..2));
    requires len > 2;
    assigns \nothing;
    ensures \result == true ==> ((len) > 2 &&
        (arr)[0] < (arr)[1] &&
        (arr)[1] < (arr)[2]);
*/
bool is_strictly_increasing(int *arr, int len)
{
    int n = len;
    bool ret;

    if (n < 3) {
        ret = false;
        //@ assert ret == false;
        return ret;
    }

    if (arr[0] >= arr[1] || arr[1] >= arr[2]) {
        ret = false;
        //@ assert ret == false;
        return ret;
    }

    //@ assert arr[0] < arr[1] && arr[1] < arr[2];
    ret = true;
    //@ assert ret == true ==> ((len) > 2 &&         (arr)[0] < (arr)[1] &&         (arr)[1] < (arr)[2]);
    return ret;
}

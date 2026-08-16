#include <stdbool.h>

/*@
    requires \valid_read(arr + (0 .. 2));
    requires ((len) >= 3 &&
        (arr)[0] >= 1 && (arr)[0] <= 100 &&
        (arr)[1] >= 1 && (arr)[1] <= 100 &&
        (arr)[2] >= 1 && (arr)[2] <= 100);
    ensures \result == true <==> ((((arr))[0] + ((arr))[1]) == (arr)[2] ||
        (((arr))[1] + ((arr))[2]) == (arr)[0] ||
        (((arr))[0] + ((arr))[2]) == (arr)[1]);
*/
bool func(int* arr, int len) {
    bool result;
    int sum1_val;
    int sum2_val;
    int sum3_val;

    result = false;
    //@ assert len >= 3;
    sum1_val = arr[0] + arr[1];
    sum2_val = arr[1] + arr[2];
    sum3_val = arr[0] + arr[2];

    if (sum1_val == arr[2] || sum2_val == arr[0] || sum3_val == arr[1]) {
        result = true;
    }
    return result;
}

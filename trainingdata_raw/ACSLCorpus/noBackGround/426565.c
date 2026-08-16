#include <stdbool.h>
/*@
    requires ((len) >= 4 &&
        \valid((arr) + (0 .. (len)-1)) &&
        1 <= (arr)[0] && (arr)[0] <= 10000 &&
        1 <= (arr)[1] && (arr)[1] <= 10000 &&
        1 <= (arr)[2] && (arr)[2] <= 10000 &&
        1 <= (arr)[3] && (arr)[3] <= 10000);
    ensures \result == ((arr)[0] * (arr)[1]) || \result == ((arr)[2] * (arr)[3]);
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int* arr, int len) {
    int product1;
    int product2;
    int max_value;

    //@ assert 0 < len;
    //@ assert (0 <= (0) && (0) < (len));
    //@ assert (0 <= (1) && (1) < (len));
    //@ assert 1 <= arr[0] && arr[0] <= 10000;
    //@ assert 1 <= arr[1] && arr[1] <= 10000;
    //@ assert arr[0] * arr[1] <= 100000000;
    //@ assert arr[0] * arr[1] >= 1;
    product1 = arr[0] * arr[1];

    //@ assert 2 < len;
    //@ assert (0 <= (2) && (2) < (len));
    //@ assert (0 <= (3) && (3) < (len));
    //@ assert 1 <= arr[2] && arr[2] <= 10000;
    //@ assert 1 <= arr[3] && arr[3] <= 10000;
    //@ assert arr[2] * arr[3] <= 100000000;
    //@ assert arr[2] * arr[3] >= 1;
    product2 = arr[2] * arr[3];

    if (product1 > product2) {
        max_value = product1;
    } else {
        max_value = product2;
    }

    //@ assert max_value == product1 || max_value == product2;
    return max_value;
}

#include <stdbool.h>

/*@
    requires \valid_read(arr + (0 .. 2));
    requires ((len) >= 3 &&
        1 <= (arr)[0] <= 100 &&
        1 <= (arr)[1] <= 100 &&
        1 <= (arr)[2] <= 200);
    ensures \result == (((arr[2]) - ((arr[1]) - (arr[0]))) > 0);
*/
bool func(const int *arr, int len) {
    int a;
    int b;
    int c;
    bool result;

    a = arr[0];
    b = arr[1];
    c = arr[2];

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 200;

    result = (c - (b - a)) > 0;
    return result;
}

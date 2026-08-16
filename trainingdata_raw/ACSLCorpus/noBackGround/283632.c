#include <stdbool.h>

/*@
    requires \valid_read(arr + (0 .. 2));
    requires ((3) == 3 &&
    1 <= (arr)[0] && (arr)[0] <= 100 &&
    1 <= (arr)[1] && (arr)[1] <= 100 &&
    1 <= (arr)[2] && (arr)[2] <= 100);
    ensures \result == true <==> ((arr)[0] < (arr)[1] && (arr)[1] < (arr)[2]);
*/
bool func(int *arr) {
    int x0;
    int x1;
    int x2;
    bool result;

    x0 = arr[0];
    x1 = arr[1];
    x2 = arr[2];

    //@ assert 1 <= x0 && x0 <= 100;
    //@ assert 1 <= x1 && x1 <= 100;
    //@ assert 1 <= x2 && x2 <= 100;

    if (1 <= x0 && x0 < x1 && x1 < x2 && x2 <= 100) {
        result = true;
        //@ assert ((arr)[0] < (arr)[1] && (arr)[1] < (arr)[2]);
    } else {
        //@ assert !(x0 < x1 && x1 < x2);
        result = false;
    }

    return result;
}

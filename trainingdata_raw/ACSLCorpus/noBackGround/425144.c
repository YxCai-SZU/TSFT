#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. 2));
    requires ((3) == 3 &&
        1 <= (arr)[0] && (arr)[0] <= 100 &&
        1 <= (arr)[1] && (arr)[1] <= 20 &&
        1 <= (arr)[2] && (arr)[2] <= 2000);
    assigns \nothing;
    ensures \result == arr[2] || \result == arr[0] * arr[1] || \result == -1;
    ensures \result >= 1 || \result == -1;
*/
int func(int *arr) {
    int a;
    int b;
    int c;
    int result;

    a = arr[0];
    b = arr[1];
    c = arr[2];

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 20;
    //@ assert 1 <= c && c <= 2000;
    //@ assert ((a) * (b)) <= 2000;

    if (a * b < c) {
        //@ assert ((a) * (b)) >= 1;
        result = a * b;
    } else if (c < a * b) {
        //@ assert c >= 1;
        result = c;
    } else {
        result = -1;
    }

    return result;
}

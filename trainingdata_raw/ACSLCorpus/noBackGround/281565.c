#include <stdbool.h>

/*@ requires \valid_read(arr + (0 .. len-1));
    requires len >= 3;
    requires 1 <= arr[0] <= 100;
    requires 1 <= arr[1] <= 100;
    requires 1 <= arr[2] <= 100;
    ensures \result == (arr[0] + arr[1] >= arr[2] || arr[0] + arr[2] >= arr[1] || arr[1] + arr[2] >= arr[0]);
    assigns \nothing;
*/
bool func(int *arr, int len) {
    int a;
    int b;
    int c;
    bool result;

    //@ assert len >= 3;
    a = arr[0];
    //@ assert 1 <= a <= 100;
    b = arr[1];
    //@ assert 1 <= b <= 100;
    c = arr[2];
    //@ assert 1 <= c <= 100;

    //@ assert a == (\at((arr)[(0)], Here));
    //@ assert b == (\at((arr)[(1)], Here));
    //@ assert c == (\at((arr)[(2)], Here));

    result = (a + b >= c) || (a + c >= b) || (b + c >= a);
    return result;
}

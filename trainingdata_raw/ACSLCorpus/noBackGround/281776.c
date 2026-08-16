#include <stdbool.h>
/*@
    requires \valid(arr + (0 .. len-1));
    requires ((len) >= 3 &&
        \forall integer i; 0 <= i < 3 ==> 1 <= (arr)[i] && (arr)[i] <= 13);
    ensures \result <==> ((arr[1]) + (arr[2]) >= (arr[0]) || (arr[1]) + (arr[0]) >= (arr[2]) || (arr[2]) + (arr[0]) >= (arr[1]));
*/
bool func(int* arr, int len) {
    bool result = false;
    int a = 0;
    int b = 0;
    int c = 0;

    //@ assert ((len) >= 3 &&         \forall integer i; 0 <= i < 3 ==> 1 <= (arr)[i] && (arr)[i] <= 13);
    a = arr[0];
    b = arr[1];
    c = arr[2];

    //@ assert 1 <= a && a <= 13;
    //@ assert 1 <= b && b <= 13;
    //@ assert 1 <= c && c <= 13;

    if (a + b >= c || a + c >= b || b + c >= a) {
        result = true;
    }

    //@ assert result <==> (a + b >= c || a + c >= b || b + c >= a);
    //@ assert result <==> ((a) + (b) >= (c) || (a) + (c) >= (b) || (b) + (c) >= (a));
    //@ assert result <==> ((arr[1]) + (arr[2]) >= (arr[0]) || (arr[1]) + (arr[0]) >= (arr[2]) || (arr[2]) + (arr[0]) >= (arr[1]));

    return result;
}

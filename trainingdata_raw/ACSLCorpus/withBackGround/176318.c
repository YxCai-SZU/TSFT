#include <stdbool.h>

/*@
    predicate valid_range(int* arr, integer len) =
        len >= 3 &&
        \forall integer i; 0 <= i < 3 ==> 1 <= arr[i] <= 13;

    predicate triangle_inequality(int a, int b, int c) =
        b + c > a && a + c > b && a + b > c;
*/

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires valid_range(arr, len);
    ensures \result <==> triangle_inequality(arr[0], arr[1], arr[2]);
*/
bool func(int* arr, int len) {
    int a;
    int b;
    int c;
    bool result;

    //@ assert len >= 3;
    if (len < 3) {
        return false;
    }

    a = arr[0];
    b = arr[1];
    c = arr[2];

    //@ assert 1 <= a && a <= 13;
    result = (b + c > a && a + c > b && a + b > c);

    //@ assert result <==> triangle_inequality(a, b, c);
    return result;
}

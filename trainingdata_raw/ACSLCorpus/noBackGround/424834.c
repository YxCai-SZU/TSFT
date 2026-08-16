#include <limits.h>

/*@
    requires ((len) >= 3 &&
        \forall integer i; 0 <= i < 3 ==> 1 <= (v)[i] <= 100);
    ensures \result >= 0;
    ensures \result <= ((v[0]) + (v[1])) || 
            \result <= ((v[1]) + (v[2])) || 
            \result <= ((v[2]) + (v[0]));
*/
int func(int *v, int len) {
    int result;
    int a;
    int b;
    int c;
    int temp;

    result = INT_MAX;
    a = v[0];
    b = v[1];
    c = v[2];

    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    //@ assert a <= b <= c;

    if (a + b < result) {
        result = a + b;
    }
    //@ assert result <= ((a) + (b));

    if (b + c < result) {
        result = b + c;
    }
    //@ assert result <= (((c)) + (c)) || result <= ((a) + (b));

    if (c + a < result) {
        result = c + a;
    }
    //@ assert result <= ((c) + (a)) || result <= (((c)) + (c)) || result <= ((a) + (b));

    return result;
}

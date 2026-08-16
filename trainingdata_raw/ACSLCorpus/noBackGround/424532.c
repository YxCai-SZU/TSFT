#include <limits.h>

/*@
    requires -1000 <= a <= 1000;
    requires -1000 <= b <= 1000;
    ensures \result == ((a) + (b)) || \result == ((a) * (b)) || \result == ((a) - (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) * (b));
    ensures \result >= ((a) - (b));
*/
int func(int a, int b) {
    int add;
    int mul;
    int sub;
    int result;

    //@ assert (-1000 <= (a) <= 1000);
    //@ assert (-1000 <= (b) <= 1000);
    add = a + b;
    //@ assert mul_bounds: ((a) * (b)) >= -1000000 && ((a) * (b)) <= 1000000;
    mul = a * b;
    sub = a - b;

    if (add > mul) {
        if (add > sub) {
            result = add;
        } else {
            result = sub;
        }
    } else {
        if (mul > sub) {
            result = mul;
        } else {
            result = sub;
        }
    }

    return result;
}

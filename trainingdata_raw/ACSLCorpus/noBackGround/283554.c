#include <stdbool.h>

/*@
    requires \valid(v + (0..2));
    requires ((3) == 3 &&
        1 <= (v)[0] <= 500 &&
        1 <= (v)[1] <= 500 &&
        1 <= (v)[2] <= 1000);
    ensures \result == (v[0] + v[1] >= v[2]);
    assigns \nothing;
*/
bool func(int *v) {
    int a;
    int b;
    int c;
    bool result;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert 1 <= a <= 500;
    //@ assert 1 <= b <= 500;
    //@ assert 1 <= c <= 1000;

    result = (a + b >= c);
    return result;
}

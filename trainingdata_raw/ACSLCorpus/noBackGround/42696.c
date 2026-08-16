#include <stdbool.h>

/*@
    requires \valid(v + (0..2));
    requires ((3) == 3 &&
        1 <= (v)[0] && (v)[0] <= 100 &&
        1 <= (v)[1] && (v)[1] <= 100 &&
        1 <= (v)[2] && (v)[2] <= 100 &&
        (v)[0] != (v)[1] &&
        (v)[0] != (v)[2] &&
        (v)[1] != (v)[2]);
    ensures \result == 1 <==> ((v)[0] < (v)[1] && (v)[1] < (v)[2]);
    assigns \nothing;
*/
bool func(int *v) {
    int a;
    int b;
    int c;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert a != b && a != c && b != c;
    return a < b && b < c;
}

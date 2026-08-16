#include <stdbool.h>

/*@
    requires \valid(a+(0..1));
    requires ((2) == 2 &&
        1 <= (a)[0] <= 20 &&
        1 <= (a)[1] <= 20);
    assigns \nothing;
    ensures (a[0] < 9 && a[1] < 9) ==> \result == a[0] * a[1];
    ensures (a[0] >= 10 || a[1] >= 10) ==> \result == -1;
*/
int func(int *a) {
    int s;
    int w;
    int result;

    s = a[0];
    w = a[1];

    if (s < 10 && w < 10) {
        //@ assert 1 <= s <= 9;
        //@ assert 1 <= w <= 9;
        //@ assert 1 <= s * w <= 81;
        result = s * w;
    } else {
        result = -1;
    }

    return result;
}

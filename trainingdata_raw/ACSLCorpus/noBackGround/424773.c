#include <stdbool.h>

/*@
    requires \valid_read(a + (0..2));
    requires ((a[0]) >= -100 && (a[0]) <= 100 &&
    (a[1]) >= -100 && (a[1]) <= 100 &&
    (a[2]) >= -100 && (a[2]) <= 100);
    assigns \nothing;
    ensures \result == (a[1] - a[0] == a[2] - a[1]);
*/
bool func(const int a[3]) {
    int a0;
    int a1;
    int a2;
    bool result;

    a0 = a[0];
    a1 = a[1];
    a2 = a[2];

    //@ assert ((a0) >= -100 && (a0) <= 100 &&     (a1) >= -100 && (a1) <= 100 &&     (a2) >= -100 && (a2) <= 100);

    //@ assert ((a1) - (a0) == (a2) - (a1)) || !((a1) - (a0) == (a2) - (a1));

    result = (a1 - a0 == a2 - a1);
    return result;
}

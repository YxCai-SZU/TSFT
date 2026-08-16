#include <stdbool.h>

/*@
    requires \valid_read(a + (0..2));
    requires 1 <= a[0] <= 100;
    requires 1 <= a[1] <= 100;
    requires 1 <= a[2] <= 100;

    ensures ((a[0]) == (a[1]) && (a[1]) == (a[2])) ==> \result == 1;
    ensures (((a[0]) == (a[1]) && (a[1]) != (a[2])) ||
        ((a[0]) != (a[1]) && (a[1]) == (a[2])) ||
        ((a[0]) == (a[2]) && (a[0]) != (a[1]))) ==> \result == 2;
    ensures ((a[0]) != (a[1]) && (a[1]) != (a[2]) && (a[0]) != (a[2])) ==> \result == 3;
*/
int func(const long long* a) {
    long long a0;
    long long a1;
    long long a2;

    a0 = a[0];
    a1 = a[1];
    a2 = a[2];

    if (a0 == a1 && a1 == a2) {
        //@ assert ((a0) == (a1) && (a1) == (a2));
        return 1;
    } else if (a0 == a1 || a1 == a2 || a0 == a2) {
        //@ assert (((a0) == (a1) && (a1) != (a2)) ||         ((a0) != (a1) && (a1) == (a2)) ||         ((a0) == (a2) && (a0) != (a1)));
        return 2;
    } else {
        //@ assert ((a0) != (a1) && (a1) != (a2) && (a0) != (a2));
        return 3;
    }
}

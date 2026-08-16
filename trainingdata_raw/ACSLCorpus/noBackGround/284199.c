#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result <= 3 && \result >= 1;
    ensures (a == b && a == c) ==> \result == 1;
    ensures (a != b && b != c && a != c) ==> \result == 3;
    ensures ((a == b && b != c) || (a != b && b == c) || (a == c && b != c)) ==> \result == 2;
*/
int func(int a, int b, int c) {
    int ans;
    ans = -1;

    if (a == b) {
        ans = (b == c) ? 1 : 2;
    } else if (b == c) {
        ans = 2;
    } else if (a == c) {
        ans = 2;
    } else {
        ans = 3;
    }

    //@ assert ans >= 1 && ans <= 3;
    //@ assert (a == b && a == c) ==> ans == 1;
    //@ assert (a != b && b != c && a != c) ==> ans == 3;
    //@ assert ((a == b && b != c) || (a != b && b == c) || (a == c && b != c)) ==> ans == 2;

    return ans;
}

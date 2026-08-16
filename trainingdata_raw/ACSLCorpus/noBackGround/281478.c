#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == ((((a) == (b) ? 1 : 0) + ((b) == (c) ? 1 : 0) + ((c) == (a) ? 1 : 0)) == 1);
*/
bool func(int a, int b, int c) {
    int cnt = 0;

    //@ assert (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);

    if (a == b) {
        cnt += 1;
    }
    if (b == c) {
        cnt += 1;
    }
    if (c == a) {
        cnt += 1;
    }

    //@ assert 0 <= cnt <= 3;
    //@ assert cnt == (((a) == (b) ? 1 : 0) + ((b) == (c) ? 1 : 0) + ((c) == (a) ? 1 : 0));
    //@ assert (cnt == 1) ==> ((((a) == (b) ? 1 : 0) + ((b) == (c) ? 1 : 0) + ((c) == (a) ? 1 : 0)) == 1);
    //@ assert (cnt != 1) ==> ((((a) == (b) ? 1 : 0) + ((b) == (c) ? 1 : 0) + ((c) == (a) ? 1 : 0)) != 1);

    return cnt == 1;
}

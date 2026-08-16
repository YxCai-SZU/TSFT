#include <stdbool.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
    ensures (a == b && a != c) ==> \result == c;
    ensures (a == c && a != b) ==> \result == b;
    ensures (b == c && a != b) ==> \result == a;
    assigns \nothing;
*/
long func(long a, long b, long c) {
    long result;
    long ans;

    if (a == b) {
        result = c;
        return result;
    } else if (a == c) {
        result = b;
        return result;
    } else if (b == c) {
        result = a;
        return result;
    } else {
        ans = a;
        if (a < b) {
            ans = b;
        }
        if (ans < c) {
            ans = c;
        }
        //@ assert ans == a || ans == b || ans == c;
        result = ans;
        return result;
    }
}

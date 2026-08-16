#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == (c <= b + d && c + d <= b + d + a);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int r;
    unsigned int l;
    bool ans;

    // Variable declarations at scope top
    r = b + d;
    l = c;
    ans = true;

    if (l > r) {
        ans = false;
    } else {
        //@ assert l <= r;
        r = r + a;
        //@ assert r == b + d + a;
        l = l + d;
        //@ assert l == c + d;
        if (l > r) {
            ans = false;
        }
    }

    // Final verification of postcondition
    //@ assert ans == (c <= b + d && c + d <= b + d + a);
    return ans;
}

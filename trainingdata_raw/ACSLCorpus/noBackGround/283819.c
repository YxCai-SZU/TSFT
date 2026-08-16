#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures ((\result) == (((a)) + ((b))) || (\result) == (((a)) - ((b))) || (\result) == (((a)) * ((b))));
    ensures ((\result) >= (((a)) + ((b))) && (\result) >= (((a)) - ((b))) && (\result) >= (((a)) * ((b))));
    assigns \nothing;
*/
int func(int a, int b) {
    int add;
    int sub;
    int mul;
    int ans;

    add = a + b;
    sub = a - b;
    //@ assert -10000 <= a * b <= 10000;
    mul = a * b;
    ans = add;
    if (sub > ans) {
        ans = sub;
    }
    if (mul > ans) {
        ans = mul;
    }
    return ans;
}

#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 1;
    ensures \result <= 3;
    ensures \result == 1 ==> (a == b && b == c);
    ensures \result == 2 ==> ((a == b && a != c) || (b == c && b != a) || (c == a && c != b));
    ensures \result == 3 ==> (a != b && b != c && c != a);
*/
int func(int a, int b, int c)
{
    int ans = -1;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);

    if (a == b && b == c) {
        ans = 1;
        //@ assert ans == 1;
        //@ assert a == b && b == c;
    } else if (a != b && b != c && c != a) {
        ans = 3;
        //@ assert ans == 3;
        //@ assert a != b && b != c && c != a;
    } else {
        ans = 2;
        //@ assert ans == 2;
        //@ assert (a == b && a != c) || (b == c && b != a) || (c == a && c != b);
    }

    //@ assert ans >= 1 && ans <= 3;
    return ans;
}

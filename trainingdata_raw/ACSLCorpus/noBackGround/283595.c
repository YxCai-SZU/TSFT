#include <stdbool.h>

/*@
    requires (3 <= (a) <= 20) && (3 <= (b) <= 20);
    ensures \result >= 0;
    ensures \result == ((a) == (b) ? (a) + (b) :
        (a) < (b)  ? (b) * 2 - 1 :
                 (a) * 2 - 1);
    assigns \nothing;
*/
int func(int a, int b)
{
    int res;

    if (a == b) {
        res = a + b;
    } else if (a < b) {
        res = b * 2 - 1;
    } else {
        res = a * 2 - 1;
    }

    //@ assert res >= 0;
    //@ assert res == ((a) == (b) ? (a) + (b) :         (a) < (b)  ? (b) * 2 - 1 :                  (a) * 2 - 1);

    return res;
}

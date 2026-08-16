#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (r) <= 4111);
    ensures \result == ((n) >= 10 ? (r) : (r) + 100 * (10 - (n)));
*/
int func(int n, int r)
{
    int result = 0;
    int temp_n = n;
    int temp_r = r;

    if (n >= 10) {
        result = r;
    } else {
        result = r + 100 * (10 - n);
    }

    //@ assert result == ((n) >= 10 ? (r) : (r) + 100 * (10 - (n)));
    //@ assert 0 <= result <= 4111 + 100 * 10;

    return result;
}

#include <stdbool.h>

/*@
    requires (1 <= (n) <= 20) && (1 <= (m) <= 20);
    ensures \result == n + m || \result == 2 * n || \result == 2 * m;
    assigns \nothing;
*/
int func(int n, int m)
{
    int min_val;
    int max_val;
    int result;

    //@ assert n + m <= 40;
    //@ assert 2 * n <= 40;
    //@ assert 2 * m <= 40;

    min_val = n < m ? n : m;
    max_val = n > m ? n : m;

    if (max_val - min_val < min_val) {
        result = max_val + min_val;
    } else {
        result = 2 * max_val;
    }

    return result;
}

#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (m) && (m) <= 100 &&
        1 <= (x) && (x) <= (n) &&
        1 <= (a) && (a) <= (n) &&
        1 <= (b) && (b) <= (m) &&
        (a) < (n) &&
        (b) < (m));
    ensures \result == (a + b >= n + m - x);
*/
bool func(int n, int m, int x, int a, int b)
{
    int n_a;
    int m_b;
    int max_val;

    n_a = n - a;
    m_b = m - b;

    //@ assert n_a >= 0 && m_b >= 0;

    if (n_a > m_b) {
        max_val = n_a;
    } else {
        max_val = m_b;
    }

    //@ assert max_val == n_a || max_val == m_b;
    //@ assert max_val >= n_a && max_val >= m_b;

    return a + b >= n + m - x;
}

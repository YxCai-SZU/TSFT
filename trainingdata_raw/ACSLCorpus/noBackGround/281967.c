#include <limits.h>

/*@
    requires (1 <= (n) <= 100) && (1 <= (m) <= 100);
    ensures \result == n * n - m * m;
    assigns \nothing;
*/
int find_difference_of_squares(int n, int m)
{
    // Variable declarations at scope top
    int n_square;
    int m_square;
    int difference;

    //@ assert (1 <= (n) <= 100);
    //@ assert (1 <= (m) <= 100);
    //@ assert ((n) * (n) <= 10000);
    //@ assert ((m) * (m) <= 10000);

    n_square = n * n;
    m_square = m * m;
    difference = n_square - m_square;

    //@ assert difference == n * n - m * m;
    return difference;
}

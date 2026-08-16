#include <limits.h>

/*@
    predicate in_range(integer v) = -2000 <= v <= 2000;
    logic integer square(integer x) = x * x;
    logic integer difference_of_squares(integer n, integer m) = square(n) - square(m);
*/

/*@
    requires in_range(n);
    requires in_range(m);
    ensures \result == difference_of_squares(n, m);
    assigns \nothing;
*/
int find_difference_of_squares(int n, int m)
{
    // Declare all variables at the top
    int n_square;
    int m_square;
    int difference;

    //@ assert n * n <= 2000 * 2000;
    //@ assert m * m <= 2000 * 2000;
    //@ assert n * n >= -2000 * 2000;
    //@ assert m * m >= -2000 * 2000;

    n_square = n * n;
    m_square = m * m;
    difference = n_square - m_square;

    //@ assert difference == difference_of_squares(n, m);
    return difference;
}

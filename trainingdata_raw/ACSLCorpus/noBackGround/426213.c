#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 100) && (1 <= (m) && (m) <= 100);
    ensures 0 <= \result <= 10000;
    assigns \nothing;
*/
int find_difference_of_squares(int n, int m)
{
    int n_square;
    int m_square;
    int square_difference;
    int difference;
    
    //@ assert n * n <= 100 * 100;
    //@ assert m * m <= 100 * 100;
    
    n_square = n * n;
    m_square = m * m;
    
    //@ assert 0 <= n_square <= 10000;
    //@ assert 0 <= m_square <= 10000;
    
    square_difference = n_square - m_square;
    
    if (square_difference < 0) {
        difference = -square_difference;
    } else {
        difference = square_difference;
    }
    
    //@ assert difference >= 0 && difference <= 10000;
    
    return difference;
}

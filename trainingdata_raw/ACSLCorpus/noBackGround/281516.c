#include <stdbool.h>

/*@
    requires (1 <= (n) <= 1000 &&
        1 <= (m) <= 1000 &&
        0 <= (k) <= (n) * (m));
    ensures \result == ((n * m - k) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m, unsigned int k)
{
    // Variable declarations at top of scope
    unsigned int total_pieces;
    unsigned int temp;
    bool is_even;

    //@ assert 1 <= n <= 1000;
    //@ assert 1 <= m <= 1000;
    //@ assert 0 <= k <= n * m;

    total_pieces = n * m;
    
    //@ assert total_pieces >= 1;
    //@ assert total_pieces <= 1000000;
    //@ assert total_pieces - k >= 0;

    temp = total_pieces - k;
    is_even = false;

    /*@
        loop invariant 0 <= temp <= total_pieces;
        loop invariant temp % 2 == (total_pieces - k) % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }

    is_even = (temp == 0);
    
    //@ assert is_even == ((n * m - k) % 2 == 0);
    return is_even;
}

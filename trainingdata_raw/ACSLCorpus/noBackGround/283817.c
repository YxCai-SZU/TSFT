#include <stdbool.h>

/*@
    requires (1 <= (n) <= 1000 && 1 <= (m) <= 1000 && 0 <= (k) <= (n) * (m));
    ensures \result == true <==> ((k) % 2 == (((n)) * ((m))) % 2 && (((n)) * ((m))) >= (k) && (k) >= 0);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m, unsigned int k)
{
    // Variable declarations at the top
    unsigned int total_squares;
    unsigned int remainder;
    bool result;

    //@ assert n * m <= 1000000;
    total_squares = n * m;

    if (total_squares > k) {
        remainder = total_squares - k;
    } else {
        remainder = k - total_squares;
    }

    if (k % 2 == total_squares % 2 && total_squares >= k && k >= 0) {
        //@ assert ((k) % 2 == (((n)) * ((m))) % 2 && (((n)) * ((m))) >= (k) && (k) >= 0);
        result = true;
    } else {
        //@ assert !((k) % 2 == (((n)) * ((m))) % 2 && (((n)) * ((m))) >= (k) && (k) >= 0);
        result = false;
    }

    return result;
}

#include <stdint.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures \result == ((n) <= 9 && (m) <= 9 ? (n) * (m) : -1);
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    int64_t result;

    //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20);
    
    if (n > 9 || m > 9) {
        result = -1;
        //@ assert result == ((n) <= 9 && (m) <= 9 ? (n) * (m) : -1);
        return result;
    }

    //@ assert n <= 9 && m <= 9;
    //@ assert 1 <= n * m <= 81;
    
    result = n * m;
    //@ assert result == ((n) <= 9 && (m) <= 9 ? (n) * (m) : -1);
    return result;
}

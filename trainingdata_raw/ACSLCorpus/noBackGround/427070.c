#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures \result >= 0;
    ensures \result == (((n) == 1 && (m) == 1) ? 1 :
        ((n) == 1 || (m) == 1) ? 0 :
        ((n) == 2 || (m) == 2) ? 0 :
        ((n) - 2) * ((m) - 2));
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    int64_t result;
    
    //@ assert (1 <= (n) <= 100 && 1 <= (m) <= 100);
    
    if (n == 1 && m == 1) {
        result = 1;
        //@ assert result == (((n) == 1 && (m) == 1) ? 1 :         ((n) == 1 || (m) == 1) ? 0 :         ((n) == 2 || (m) == 2) ? 0 :         ((n) - 2) * ((m) - 2));
        return result;
    } else if (n == 1 || m == 1) {
        result = 0;
        //@ assert result == (((n) == 1 && (m) == 1) ? 1 :         ((n) == 1 || (m) == 1) ? 0 :         ((n) == 2 || (m) == 2) ? 0 :         ((n) - 2) * ((m) - 2));
        return result;
    } else if (n == 2 || m == 2) {
        result = 0;
        //@ assert result == (((n) == 1 && (m) == 1) ? 1 :         ((n) == 1 || (m) == 1) ? 0 :         ((n) == 2 || (m) == 2) ? 0 :         ((n) - 2) * ((m) - 2));
        return result;
    } else {
        //@ assert n - 2 >= 0 && m - 2 >= 0;
        //@ assert (n - 2) * (m - 2) >= 0;
        //@ assert (n - 2) * (m - 2) <= 10000;
        result = (n - 2) * (m - 2);
        //@ assert result == (((n) == 1 && (m) == 1) ? 1 :         ((n) == 1 || (m) == 1) ? 0 :         ((n) == 2 || (m) == 2) ? 0 :         ((n) - 2) * ((m) - 2));
        return result;
    }
}


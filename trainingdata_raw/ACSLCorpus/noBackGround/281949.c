#include <stddef.h>

/*@
    requires (0 <= (n) && (n) <= 100 && 0 <= (m) && (m) <= 100);
    ensures \result <= n + m;
    ensures \result >= 0;
    assigns \nothing;
*/
size_t func(size_t n, size_t m)
{
    size_t result;
    
    if (n > m + 1) {
        //@ assert n > m + 1;
        result = n - (m + 1) + m;
        //@ assert result <= n + m;
        return result;
    } else if (n == m + 1) {
        //@ assert n == m + 1;
        result = m;
        //@ assert result <= n + m;
        return result;
    } else if (m > n + 1) {
        //@ assert m > n + 1;
        result = m - (n + 1) + n;
        //@ assert result <= n + m;
        return result;
    } else if (m == n + 1) {
        //@ assert m == n + 1;
        result = n;
        //@ assert result <= n + m;
        return result;
    } else {
        //@ assert m <= n + 1;
        result = n;
        //@ assert result <= n + m;
        return result;
    }
}

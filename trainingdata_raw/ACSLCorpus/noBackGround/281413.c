#include <stddef.h>

/*@
    requires (1 <= (n) && 1 <= (m) && (n) <= 100 && (m) <= 100);
    ensures \result <= m;
    ensures \result >= m - n;
    assigns \nothing;
*/
size_t func(size_t n, size_t m) {
    size_t t;
    
    //@ assert (1 <= (n) && 1 <= (m) && (n) <= 100 && (m) <= 100);
    
    if (n < m) {
        t = n;
        //@ assert t == n;
    } else {
        t = m;
        //@ assert t == m;
    }
    
    //@ assert t == ((n) < (m) ? (n) : (m));
    //@ assert m - t <= m;
    //@ assert m - t >= m - n;
    
    return m - t;
}

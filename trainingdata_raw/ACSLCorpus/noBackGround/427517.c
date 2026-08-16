#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (m) && (m) <= 100 &&
        (n) >= 0 &&
        (m) >= 0);
    ensures \result >= 0;
    ensures \result <= n + m;
    assigns \nothing;
*/
int func(int n, int m)
{
    int max_n;
    int sum;

    //@ assert (1 <= (n) && (n) <= 100 &&         1 <= (m) && (m) <= 100 &&         (n) >= 0 &&         (m) >= 0);
    
    if (n > m) {
        max_n = n;
    } else {
        max_n = m;
    }
    
    //@ assert max_n == ((n) > (m) ? (n) : (m));
    
    sum = max_n * 2 - (n + m);
    
    //@ assert sum == ((((n)) > ((m)) ? ((n)) : ((m))) * 2 - ((n) + (m)));
    //@ assert sum >= 0;
    
    return sum;
}

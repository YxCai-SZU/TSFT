#include <limits.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100 &&
        -100 <= (n) <= 100 && -100 <= (m) <= 100);
    ensures \result == ((n) > 0 && (m) > 0 ? (n) * (m) :
        (n) < 0 && (m) > 0 ? -((-(n)) * (m)) :
        (n) > 0 && (m) < 0 ? -((n) * (-(m))) :
        -((-(n)) * (-(m))));
    assigns \nothing;
*/
long long func(long long n, long long m) {
    long long ans;
    
    //@ assert n * m <= 10000;
    //@ assert -((-n) * (-m)) <= 10000;
    
    if (n > 0) {
        if (m > 0) {
            ans = n * m;
        } else {
            ans = -(n * -m);
        }
    } else {
        if (m > 0) {
            ans = -(n * m);
        } else {
            ans = -(-n * -m);
        }
    }
    
    return ans;
}

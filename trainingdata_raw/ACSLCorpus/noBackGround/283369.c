#include <stdbool.h>

/*@
    requires ((\valid(((v))) && \valid(((v))+1) && \valid(((v))+2) && \valid(((v))+3)) &&
        (1 <= ((v)[0]) <= 10000) &&
        (1 <= ((v)[1]) <= 10000) &&
        (1 <= ((v)[2]) <= 10000) &&
        (1 <= ((v)[3]) <= 10000));
    ensures \result >= 0;
    ensures \result == ((v[3]) * (v[0])) - ((v[2]) * (v[1])) || \result == 0;
    assigns \nothing;
*/
int func(int *v)
{
    // Variable declarations at top of scope
    int ans;
    
    //@ assert (1 <= (v[3]) <= 10000) && (1 <= (v[0]) <= 10000);
    //@ assert 0 <= ((v[3]) * (v[0])) <= 10000 * 10000;
    
    //@ assert (1 <= (v[2]) <= 10000) && (1 <= (v[1]) <= 10000);
    //@ assert 0 <= ((v[2]) * (v[1])) <= 10000 * 10000;
    
    //@ assert ((v[3]) * (v[0])) >= 0;
    //@ assert ((v[2]) * (v[1])) >= 0;
    
    ans = v[3] * v[0] - v[2] * v[1];
    
    if (ans < 0) {
        return 0;
    } else {
        return ans;
    }
}

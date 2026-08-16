#include <stdint.h>

/*@
    requires (\valid((s)) && \valid((s)+1) &&
        (s)[0] >= 1 && (s)[0] <= 100 &&
        (s)[1] >= 0 && (s)[1] <= 4111);
    ensures \result == ((s[0]) < 10 ? (s[1]) + 100 * (10 - (s[0])) : (s[1]));
*/
int64_t func(int64_t *s)
{
    int64_t ans = 0;
    
    //@ assert s[0] >= 1 && s[0] <= 100;
    //@ assert s[1] >= 0 && s[1] <= 4111;
    
    if (s[0] < 10) {
        //@ assert 100 * (10 - s[0]) >= 0;
        //@ assert 100 * (10 - s[0]) <= 1000;
        //@ assert s[1] + 100 * (10 - s[0]) <= 5111;
        ans = s[1] + 100 * (10 - s[0]);
    } else {
        ans = s[1];
    }
    
    //@ assert ans == ((s[0]) < 10 ? (s[1]) + 100 * (10 - (s[0])) : (s[1]));
    return ans;
}

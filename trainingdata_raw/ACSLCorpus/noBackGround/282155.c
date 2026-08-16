#include <stddef.h>

/*@
requires ((len) == 3 &&
    1 <= (v)[0] && (v)[0] <= 100 &&
    1 <= (v)[1] && (v)[1] <= 100 &&
    1 <= (v)[2] && (v)[2] <= 100);
ensures \result >= 0 && \result <= 3;
*/
int func(int *v, size_t len)
{
    int ans = 0;
    
    //@ assert ((len) == 3 &&     1 <= (v)[0] && (v)[0] <= 100 &&     1 <= (v)[1] && (v)[1] <= 100 &&     1 <= (v)[2] && (v)[2] <= 100);
    
    if (v[0] == v[1]) {
        ans += 1;
    }
    
    if (v[1] == v[2]) {
        ans += 1;
    }
    
    if (v[2] == v[0]) {
        ans += 1;
    }
    
    //@ assert ans == (((v[0]) == (v[1]) ? 1 : 0) +     ((v[1]) == (v[2]) ? 1 : 0) +     ((v[2]) == (v[0]) ? 1 : 0));
    //@ assert 0 <= ans && ans <= 3;
    
    if (ans == 3) {
        //@ assert ans == 3;
        return 1;
    } else if (ans == 0) {
        //@ assert ans == 0;
        return 3;
    } else {
        //@ assert ans == 1 || ans == 2;
        //@ assert ans >= 1 && ans <= 2;
        return 2;
    }
}

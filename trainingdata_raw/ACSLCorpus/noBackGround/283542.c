#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == a - b * 2 || \result == 0;
*/
int func(int a, int b) {
    int ans;
    int res;
    
    //@ assert b * 2 <= 200;
    //@ assert a - b * 2 >= -199;
    
    ans = a - b * 2;
    
    if (ans < 0) {
        //@ assert ans < 0;
        res = 0;
    } else {
        //@ assert ans >= 0;
        res = ans;
    }
    
    return res;
}

#ifdef TESTING
#include <assert.h>

int main() {
    assert(func(5, 2) == 1);
    assert(func(3, 2) == 0);
    assert(func(1, 1) == 0);
    return 0;
}
#endif

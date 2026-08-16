#include <limits.h>

/*@
    requires (1 <= (x) && (x) <= 100000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> x % 100 <= 5 * (x / 100);
    ensures \result == 0 ==> x % 100 > 5 * (x / 100);
*/
int func(int x) {
    int a;
    int cnt;
    int rem;
    int div;
    int result;
    
    a = x;
    cnt = 0;
    
    /*@
        loop invariant ((1 <= ((x)) && ((x)) <= 100000) && (((a)) >= 0) && (((cnt)) >= 0) && (a) == (x) - 100 * (cnt));
        loop assigns a, cnt;
        loop variant a;
    */
    while (a >= 100) {
        //@ assert a == x - 100 * cnt;
        a -= 100;
        cnt += 1;
    }
    
    rem = a;
    div = cnt;
    
    if (rem <= 5 * div) {
        //@ assert x % 100 <= 5 * (x / 100);
        result = 1;
    } else {
        //@ assert x % 100 > 5 * (x / 100);
        result = 0;
    }
    
    return result;
}

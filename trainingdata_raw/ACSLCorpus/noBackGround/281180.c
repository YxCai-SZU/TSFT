#include <limits.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == a + b || \result == a + c || \result == b + c;
    ensures \result >= a + b;
    ensures \result >= a + c;
    ensures \result >= b + c;
    assigns \nothing;
*/
long func(long a, long b, long c) {
    long ans = LONG_MIN;
    
    //@ assert ans == LONG_MIN;
    
    if (a + b > ans) {
        ans = a + b;
    }
    //@ assert ans == ((LONG_MIN) > (a + b) ? (LONG_MIN) : (a + b));
    
    if (a + c > ans) {
        ans = a + c;
    }
    //@ assert ans == ((((LONG_MIN) > (a + b) ? (LONG_MIN) : (a + b))) > (a + c) ? (((LONG_MIN) > (a + b) ? (LONG_MIN) : (a + b))) : (a + c));
    
    if (b + c > ans) {
        ans = b + c;
    }
    //@ assert ans == ((((((LONG_MIN) > (a + b) ? (LONG_MIN) : (a + b))) > (a + c) ? (((LONG_MIN) > (a + b) ? (LONG_MIN) : (a + b))) : (a + c))) > (b + c) ? (((((LONG_MIN) > (a + b) ? (LONG_MIN) : (a + b))) > (a + c) ? (((LONG_MIN) > (a + b) ? (LONG_MIN) : (a + b))) : (a + c))) : (b + c));
    
    //@ assert ans == a + b || ans == a + c || ans == b + c;
    //@ assert ans >= a + b;
    //@ assert ans >= a + c;
    //@ assert ans >= b + c;
    
    return ans;
}

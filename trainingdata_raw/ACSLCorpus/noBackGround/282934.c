#include <limits.h>

/*@
    requires 1 <= n <= 20;
    requires 1 <= a <= 50;
    requires 1 <= b <= 50;
    requires 1 <= c <= 50;
    requires 1 <= x <= 20000;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int a, int b, int c, int x) {
    int result = 0;
    int max_val = 0;
    
    //@ assert a <= 50 && b <= 50 && c <= 50;
    
    if (a > max_val) {
        max_val = a;
    }
    //@ assert max_val >= 0 && max_val <= 50;
    
    if (b > max_val) {
        max_val = b;
    }
    //@ assert max_val >= 0 && max_val <= 50;
    
    if (c > max_val) {
        max_val = c;
    }
    //@ assert max_val >= 0 && max_val <= 50;
    
    //@ assert ((a) <= 50 && (b) <= 50 && (c) <= 50 &&         (max_val) >= (a) && (max_val) >= (b) && (max_val) >= (c) &&         ((max_val) == (a) || (max_val) == (b) || (max_val) == (c)));
    
    //@ assert n * max_val <= 1000;
    //@ assert ((n) * (max_val)) <= 1000;
    
    if (n * max_val < x) {
        result += 1;
    }
    
    //@ assert result >= 0;
    return result;
}

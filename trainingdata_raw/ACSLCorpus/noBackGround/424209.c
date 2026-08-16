#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000 &&
        1 <= (k) && (k) <= 1000000000);
    ensures \result == 0 || \result == 1;
*/
int func(long n, long k) {
    long a = n;
    long b = k;
    int result;

    //@ assert ((1 <= ((n)) && ((n)) <= 1000000000 &&         1 <= ((k)) && ((k)) <= 1000000000) &&         (a) >= 0 && (b) >= 0 &&         (a) <= (n) && (b) <= (k));
    
    /*@
        loop invariant ((1 <= ((n)) && ((n)) <= 1000000000 &&
        1 <= ((k)) && ((k)) <= 1000000000) &&
        (a) >= 0 && (b) >= 0 &&
        (a) <= (n) && (b) <= (k));
        loop invariant ((a) + (b)) >= 0;
        loop assigns a, b;
        loop variant ((a) + (b));
    */
    while (a > 0 && b > 0) {
        //@ assert a > 0 && b > 0;
        
        if (a < b) {
            //@ assert a < b;
            b = b - a;
            //@ assert b >= 0;
        } else {
            //@ assert a >= b;
            a = a - b;
            //@ assert a >= 0;
        }
        
        //@ assert ((1 <= ((n)) && ((n)) <= 1000000000 &&         1 <= ((k)) && ((k)) <= 1000000000) &&         (a) >= 0 && (b) >= 0 &&         (a) <= (n) && (b) <= (k));
    }
    
    //@ assert a <= 0 || b <= 0;
    
    if (a == 1 || b == 1) {
        result = 1;
        //@ assert result == 1;
    } else {
        result = 0;
        //@ assert result == 0;
    }
    
    return result;
}

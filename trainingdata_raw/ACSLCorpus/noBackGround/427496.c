#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 10000 &&
        0 <= (a) && (a) <= 1000);
    ensures \result == (n % 500 <= a);
    assigns \nothing;
*/
bool func(int n, int a) {
    int n_unsigned;
    int remainder;
    
    //@ assert (1 <= (n) && (n) <= 10000 &&         0 <= (a) && (a) <= 1000);
    
    n_unsigned = n;
    if (n_unsigned < 0) {
        n_unsigned = -n_unsigned;
    }
    
    remainder = n_unsigned;
    
    /*@
        loop invariant 1 <= n && n <= 10000;
        loop invariant 0 <= a && a <= 1000;
        loop invariant 0 <= remainder;
        loop invariant remainder <= n_unsigned;
        loop invariant n_unsigned == n;
        loop invariant remainder % 500 == n_unsigned % 500;
        loop invariant remainder % 500 == ((n) % 500);
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 500) {
        //@ assert remainder >= 500;
        remainder -= 500;
        //@ assert remainder % 500 == n_unsigned % 500;
    }
    
    //@ assert remainder == ((n) % 500);
    
    if (remainder <= a) {
        //@ assert remainder <= a;
        return true;
    } else {
        //@ assert remainder > a;
        return false;
    }
}

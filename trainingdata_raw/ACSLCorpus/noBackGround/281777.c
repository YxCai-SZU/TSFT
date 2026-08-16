#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 1000000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> n % 7 == 0;
    ensures \result == 0 ==> n % 7 != 0;
    assigns \nothing;
*/
int func(long n) {
    long remainder;
    
    remainder = n;
    
    /*@
        loop invariant 1 <= n && n <= 1000000;
        loop invariant remainder >= 0;
        loop invariant remainder <= n;
        loop invariant remainder == n || remainder % 7 == n % 7;
        loop invariant remainder % 7 == n % 7;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 7) {
        //@ assert remainder >= 7;
        remainder -= 7;
    }
    
    //@ assert remainder == n % 7;
    
    if (remainder == 0) {
        //@ assert n % 7 == 0;
        return 1;
    } else {
        //@ assert n % 7 != 0;
        return 0;
    }
}

#include <stddef.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> ((x) % 100) <= 5 * ((x) / 100);
    ensures \result == 0 ==> ((x) % 100) > 5 * ((x) / 100);
*/
unsigned int func(unsigned int x) {
    unsigned int pay;
    unsigned int rem;
    unsigned int res;

    //@ assert (1 <= (x) <= 100000);
    pay = x / 100;
    rem = x % 100;
    
    //@ assert pay == ((x) / 100);
    //@ assert rem == ((x) % 100);
    //@ assert 5 * pay <= 50000;
    
    if (rem > 5 * pay) {
        //@ assert ((x) % 100) > 5 * ((x) / 100);
        res = 0;
    } else {
        //@ assert ((x) % 100) <= 5 * ((x) / 100);
        res = 1;
    }
    
    return res;
}

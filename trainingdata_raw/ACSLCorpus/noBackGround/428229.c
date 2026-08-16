#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == (((((x)) / 100) * 100 + 100) < x);
    assigns \nothing;
*/
bool func(unsigned int x) {
    unsigned int n;
    unsigned int no;
    
    //@ assert (1 <= (x) <= 100000);
    n = x / 100;
    
    //@ assert n == ((x) / 100);
    //@ assert n * 100 <= 100000;
    
    no = n * 100 + 100;
    //@ assert no == ((((x)) / 100) * 100 + 100);
    
    if (no < x) {
        //@ assert no < x;
        return true;
    } else {
        //@ assert !(no < x);
        return false;
    }
}

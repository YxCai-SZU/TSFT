#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == true <==> (x % 100) * 21 <= x;
    assigns \nothing;
*/
bool func(unsigned int x) {
    unsigned int n;
    unsigned int a;
    unsigned int twentyone_a;
    unsigned int i;
    
    n = x / 100;
    a = x % 100;
    
    twentyone_a = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= a;
        loop invariant twentyone_a == 21 * i;
        loop invariant a == x % 100;
        loop invariant i <= 100;
        loop assigns twentyone_a, i;
        loop variant a - i;
    */
    while (i < a) {
        //@ assert i < 100;
        twentyone_a += 21;
        i += 1;
    }
    
    //@ assert twentyone_a == 21 * a;
    
    if (twentyone_a <= x) {
        //@ assert (x % 100) * 21 <= x;
        return true;
    } else {
        //@ assert (x % 100) * 21 > x;
        return false;
    }
}

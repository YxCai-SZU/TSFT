#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && ((a) * (a) + (b) * (b) <= 10000);
    ensures \result == (((((a)) * ((a))) + (((b)) * ((b)))) >= 200);
    assigns \nothing;
*/
bool func(long a, long b)
{
    //@ assert ((a) * (a)) <= 10000;
    //@ assert ((b) * (b)) <= 10000;
    //@ assert ((((a)) * ((a))) + (((b)) * ((b)))) <= 10000;
    //@ assert ((a) * (a)) >= 0;
    //@ assert ((b) * (b)) >= 0;
    //@ assert ((((a)) * ((a))) + (((b)) * ((b)))) >= 0;
    //@ assert ((((a)) * ((a))) + (((b)) * ((b)))) <= 10000;
    
    if (a * a + b * b >= 200) {
        return true;
    } else {
        return false;
    }
}

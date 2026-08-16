#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    int c;
    
    c = a;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert ((a) * (b)) <= 10000;
    //@ assert c == a;
    //@ assert ((c) * (b)) == ((a) * (b));
    
    return c * b;
}

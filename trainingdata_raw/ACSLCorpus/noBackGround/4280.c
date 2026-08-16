#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    ensures \result == ((a) * (a));
    assigns \nothing;
*/
int func(int a) {
    int result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert ((a) * (a)) <= 10000;
    
    result = a * a;
    
    //@ assert result == ((a) * (a));
    return result;
}

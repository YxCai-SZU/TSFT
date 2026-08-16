#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100);
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result == (((n) * (a)) > b);
*/
bool func(int n, int a, int b)
{
    // Variable declarations at scope top
    bool result;
    unsigned int un;
    unsigned int ua;
    unsigned int ub;
    
    // Precondition assertions
    //@ assert (1 <= (n) <= 100);
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    
    // Multiplication safety proof
    //@ assert ((n) * (a)) <= 10000;
    
    un = (unsigned int)n;
    ua = (unsigned int)a;
    ub = (unsigned int)b;
    
    if (un * ua > ub) {
        //@ assert ((n) * (a)) > b;
        result = true;
    } else {
        //@ assert ((n) * (a)) <= b;
        result = false;
    }
    
    return result;
}

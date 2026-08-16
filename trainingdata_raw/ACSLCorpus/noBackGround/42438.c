#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result <==> (a + b == c || a + c == b || b + c == a);
    assigns \nothing;
*/
bool can_distribute_evenly(unsigned int a, unsigned int b, unsigned int c) {
    // Variable declarations at top of scope
    bool is_evenly_distributable;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert ((a) + (b)) <= 200;
    //@ assert ((a) + (c)) <= 200;
    //@ assert (((c)) + (c)) <= 200;

    is_evenly_distributable = (a + b == c) || (a + c == b) || (b + c == a);
    return is_evenly_distributable;
}

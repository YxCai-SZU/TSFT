#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Variable declarations at scope top
    int s1;
    int s2;
    int max_value;

    // Precondition verification
    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000) && (1 <= (d) <= 10000);

    // Product bounds verification
    //@ assert ((a) * (b)) >= 1 && ((a) * (b)) <= 100000000;
    //@ assert ((c) * (d)) >= 1 && ((c) * (d)) <= 100000000;

    s1 = a * b;
    s2 = c * d;

    // Product non-negativity
    //@ assert s1 >= 1;
    //@ assert s2 >= 1;

    // Manual max implementation
    if (s1 > s2) {
        max_value = s1;
        //@ assert max_value == s1;
    } else {
        max_value = s2;
        //@ assert max_value == s2;
    }

    // Final verification
    //@ assert max_value == s1 || max_value == s2;
    //@ assert max_value >= 1;

    return max_value;
}

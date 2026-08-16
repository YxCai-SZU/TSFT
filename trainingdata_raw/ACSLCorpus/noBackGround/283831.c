#include <stdbool.h>

/*@ requires \valid(s + (0..2));
    requires (1 <= (s[0]) <= 100) && 
             (1 <= (s[1]) <= 100) && 
             (1 <= (s[2]) <= 100);
    ensures \result == 1 <==> ((s[0]) + (s[1]) == (s[2]) || (s[1]) + (s[2]) == (s[0]) || (s[0]) + (s[2]) == (s[1]));
    assigns \nothing;
 */
bool func(unsigned int s[3]) {
    // Variable declarations at scope top
    bool result;

    //@ assert (1 <= (s[0]) <= 100);
    //@ assert (1 <= (s[1]) <= 100);
    //@ assert (1 <= (s[2]) <= 100);
    //@ assert s[0] + s[1] <= 200;
    //@ assert s[1] + s[2] <= 200;
    //@ assert s[0] + s[2] <= 200;

    result = (s[0] + s[1] == s[2]) || 
             (s[1] + s[2] == s[0]) || 
             (s[0] + s[2] == s[1]);

    return result;
}

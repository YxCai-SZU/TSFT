#include <stdbool.h>

/*@
    requires \valid_read(s + (0..2));
    requires (1 <= (s[0]) && (s[0]) <= 100) && (1 <= (s[1]) && (s[1]) <= 100) && (1 <= (s[2]) && (s[2]) <= 200);
    ensures \result == (s[0] <= s[2] && s[0] + s[1] >= s[2]);
    assigns \nothing;
*/
bool func(const long s[3])
{
    //@ assert (1 <= (s[0]) && (s[0]) <= 100);
    //@ assert (1 <= (s[1]) && (s[1]) <= 100);
    //@ assert (1 <= (s[2]) && (s[2]) <= 200);
    //@ assert ((s[0]) + (s[1]) <= 200);
    
    return s[0] <= s[2] && s[0] + s[1] >= s[2];
}

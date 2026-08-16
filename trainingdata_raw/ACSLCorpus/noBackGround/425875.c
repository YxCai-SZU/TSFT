#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == ((a == b && a != c) || (b == c && b != a) || (c == a && c != b));
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int state = 0;
    
    //@ assert 0 <= state <= 3;
    
    if (a == b) { state += 1; }
    //@ assert 0 <= state <= 3;
    
    if (b == c) { state += 1; }
    //@ assert 0 <= state <= 3;
    
    if (c == a) { state += 1; }
    //@ assert 0 <= state <= 3;
    
    return state == 1;
}

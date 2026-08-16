#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (b - a == c - b);
*/
bool func(int a, int b, int c)
{
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    if (a + c == b * 2) {
        return true;
    } else {
        return false;
    }
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (b - a == c - b);
*/
bool func2(int a, int b, int c)
{
    bool ans;
    
    if (b * 2 == a + c) {
        ans = true;
    } else {
        ans = false;
    }
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    return ans;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (b - a == c - b);
*/
bool func3(int a, int b, int c)
{
    bool ans = (b * 2 == a + c);
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    return ans;
}

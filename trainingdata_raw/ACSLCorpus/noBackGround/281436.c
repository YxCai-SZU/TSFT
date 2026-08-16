#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> ((a) == (b) && (b) == (c));
*/
bool func(int a, int b, int c)
{
    bool check = true;
    
    //@ assert check == true;
    
    if (a != b)
    {
        check = false;
    }
    
    //@ assert check == true <==> (a == b);
    
    if (b != c)
    {
        check = false;
    }
    
    //@ assert check == true <==> (a == b && b == c);
    
    if (c != a)
    {
        check = false;
    }
    
    //@ assert check == true <==> ((a) == (b) && (b) == (c));
    
    return check;
}

#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    requires (1 <= (d) <= 100);
    ensures \result == true <==> 
            a < ((c) + (d)) && c < ((a) + (d)) && b >= 0 && d >= 0;
*/
bool func(int a, int b, int c, int d)
{
    bool flag = false;
    
    //@ assert ((c) + (d)) <= 200;
    //@ assert ((a) + (d)) <= 200;
    
    if (a < c + d && c < a + d && b >= 0 && d >= 0)
    {
        flag = true;
    }
    
    //@ assert flag == true <==> a < ((c) + (d)) && c < ((a) + (d)) && b >= 0 && d >= 0;
    
    return flag;
}

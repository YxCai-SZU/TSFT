#include <stdbool.h>

/*@
  requires A > -2147483648 && A < 2147483647;
  requires B > -2147483648 && B < 2147483647;
  requires C > -2147483648 && C < 2147483647;
  ensures \result == true <==> ((A) < (B) && (B) < (C));
*/
bool func(int A, int B, int C)
{
    bool ans = false;
    
    if (A < B) 
    {
        if (B < C) 
        {
            ans = true;
        }
        else 
        {
            ans = false;
        }
    }
    else 
    {
        ans = false;
    }
    
    //@ assert ans == true <==> ((A) < (B) && (B) < (C));
    
    return ans;
}

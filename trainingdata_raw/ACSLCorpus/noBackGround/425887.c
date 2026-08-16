#include <stdbool.h>

/*@
  requires 1 <= a <= 10;
  requires 1 <= b <= 10;
  requires 1 <= c <= 10;
  ensures \result == true <==> ((((a)) < ((b)) && ((b)) < ((c))) || (((a)) > ((b)) && ((b)) > ((c))));
*/
bool func(int a, int b, int c)
{
    bool ans;
    //@ assert 1 <= a <= 10 && 1 <= b <= 10 && 1 <= c <= 10;
    
    if ((a < b && b < c) || (a > b && b > c))
    {
        ans = true;
    }
    else
    {
        ans = false;
    }
    
    //@ assert ans == true <==> ((((a)) < ((b)) && ((b)) < ((c))) || (((a)) > ((b)) && ((b)) > ((c))));
    return ans;
}

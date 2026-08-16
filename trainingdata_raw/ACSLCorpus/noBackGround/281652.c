#include <stdbool.h>

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  ensures \result == true <==> (((b) - (a) == (c) - (b)) && ((a) <= (c)) && ((c) <= (b)));
*/
bool func(int a, int b, int c)
{
    int flag = 0;
    
    //@ assert b - a <= 99;
    
    if (b - a == c - b) {
        flag += 1;
    }
    if (a <= c) {
        flag += 1;
    }
    if (c <= b) {
        flag += 1;
    }
    
    //@ assert flag == 3 ==> (((b) - (a) == (c) - (b)) && ((a) <= (c)) && ((c) <= (b)));
    
    return flag == 3;
}

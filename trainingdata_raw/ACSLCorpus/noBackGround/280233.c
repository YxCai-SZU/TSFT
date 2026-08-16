#include <stdbool.h>

/*@
  requires 1 <= a <= 9;
  requires 1 <= b <= 9;
  requires 1 <= c <= 9;
  ensures \result == true <==> (((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
*/
bool func(int a, int b, int c)
{
    bool result;
    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;
    
    if ((a < b && b < c) || (a > b && b > c)) {
        //@ assert (((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
        result = true;
    } else {
        //@ assert !(((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
        result = false;
    }
    
    //@ assert result == true <==> (((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
    return result;
}

/*@
  requires 1 <= a <= 9;
  requires 1 <= b <= 9;
  requires 1 <= c <= 9;
  ensures \result == 1 <==> (((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
*/
int func_i32(int a, int b, int c)
{
    int result;
    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;
    
    if ((a < b && b < c) || (a > b && b > c)) {
        //@ assert (((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
        result = 1;
    } else {
        //@ assert !(((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
        result = 0;
    }
    
    //@ assert result == 1 <==> (((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
    return result;
}


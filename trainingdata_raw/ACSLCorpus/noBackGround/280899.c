#include <stdbool.h>

/*@
  requires 1 <= x <= 100;
  requires 1 <= y <= 100;
  ensures \result == true <==> ((x) * 2 < (y) && (y) % 2 == 0 && (y) / 2 <= 200);
*/
bool func(unsigned int x, unsigned int y)
{
    bool ret;
    // Variable declarations at scope top
    unsigned int temp1;
    unsigned int temp2;
    unsigned int temp3;
    
    temp1 = x * 2;
    temp2 = y % 2;
    temp3 = y / 2;
    
    //@ assert temp1 == x * 2;
    //@ assert temp2 == y % 2;
    //@ assert temp3 == y / 2;
    
    if (temp1 < y && temp2 == 0 && temp3 <= 200)
    {
        //@ assert ((x) * 2 < (y) && (y) % 2 == 0 && (y) / 2 <= 200);
        ret = true;
    }
    else
    {
        //@ assert !((x) * 2 < (y) && (y) % 2 == 0 && (y) / 2 <= 200);
        ret = false;
    }
    
    return ret;
}

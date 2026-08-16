#include <stdbool.h>

/*@
  requires a < 0x80000000;
  requires b < 0x80000000;
  requires c < 0x80000000;
  requires d < 0x80000000;
  requires e < 0x80000000;
  requires k < 0x80000000;
  requires ((a) <= (b) && (b) <= (c) && (c) <= (d) && (d) <= (e));
  requires k <= 123;
  ensures \result == true <==> e - a <= k;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int k)
{
    unsigned int dist;

    //@ assert ((a) <= (b) && (b) <= (c) && (c) <= (d) && (d) <= (e));
    //@ assert k <= 123;
    
    dist = e - a;
    
    if (dist > k)
    {
        //@ assert dist > k;
        return false;
    }
    else
    {
        //@ assert dist <= k;
        return true;
    }
}

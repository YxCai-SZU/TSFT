#include <stdbool.h>

/*@
  requires a < 124 && b < 124 && c < 124 && d < 124 && e < 124 && k < 124;
  requires a < b && b < c && c < d && d < e;
  ensures \result == (e - a <= k);
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int k)
{
    unsigned int dist;
    dist = e - a;
    if (dist <= k)
    {
        //@ assert dist <= k;
        return true;
    }
    else
    {
        //@ assert dist > k;
        return false;
    }
}

/*@
  requires a < 124 && b < 124 && c < 124 && d < 124 && e < 124 && k < 124;
  requires a < b && b < c && c < d && d < e;
  ensures \result == (e - a <= k);
*/
bool func2(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int k)
{
    unsigned int dist;
    dist = e - a;
    if (dist <= k)
    {
        //@ assert dist <= k;
        return true;
    }
    else
    {
        //@ assert dist > k;
        return false;
    }
}

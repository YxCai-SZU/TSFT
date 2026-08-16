#include <stdbool.h>

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  requires a != b;
  ensures \result == true <==> (((a) < (c) && (c) < (b)) || ((a) > (c) && (c) > (b)));
*/
bool func(int a, int b, int c)
{
    int min;
    int max;
    
    if (a < b)
    {
        min = a;
        max = b;
    }
    else
    {
        min = b;
        max = a;
    }
    
    //@ assert min == a || min == b;
    //@ assert max == a || max == b;
    //@ assert min < max;
    
    return (c > min) && (c < max);
}

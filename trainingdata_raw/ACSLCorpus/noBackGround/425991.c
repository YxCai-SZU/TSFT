#include <stdbool.h>

/*@
  requires (0 <= (a) && (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e) && (e) <= 123);
  requires (0 <= (k) && (k) <= 123);
  ensures \result == (e - a <= k);
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int max_val;
    int min_val;
    int diff;
    bool result;

    if (e - a <= k)
    {
        return true;
    }
    else
    {
        //@ assert e - a > k;
        
        if (a > e)
        {
            max_val = a;
        }
        else
        {
            max_val = e;
        }
        
        //@ assert max_val == ((a) > (e) ? (a) : (e));
        
        if (a < e)
        {
            min_val = a;
        }
        else
        {
            min_val = e;
        }
        
        //@ assert min_val == ((a) < (e) ? (a) : (e));
        
        diff = max_val - min_val;
        
        //@ assert diff == ((a) > (e) ? (a) : (e)) - ((a) < (e) ? (a) : (e));
        
        if (diff <= k)
        {
            //@ assert ((a) > (e) ? (a) : (e)) - ((a) < (e) ? (a) : (e)) <= k;
            return true;
        }
        else
        {
            //@ assert diff > k;
            return false;
        }
    }
}

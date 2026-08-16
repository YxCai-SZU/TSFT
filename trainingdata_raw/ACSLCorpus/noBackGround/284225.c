#include <stdbool.h>

/*@
    requires ((h1) >= 0 && (h1) < 24 && (m1) >= 0 && (m1) < 60) && ((h2) >= 0 && (h2) < 24 && (m2) >= 0 && (m2) < 60);
    requires ((h1) <= (h2) && ((h1) == (h2) ==> (m1) <= (m2)));
    requires k >= 0;
    ensures \result >= 0 && \result <= 24 * 60;
    assigns \nothing;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int x;
    int result;

    x = 60 * (h2 - h1) + (m2 - m1);
    
    //@ assert x == (60 * ((h2) - (h1)) + ((m2) - (m1)));
    
    if (x < k)
    {
        result = 0;
    }
    else
    {
        //@ assert x - k >= 0;
        result = x - k;
    }
    
    return result;
}

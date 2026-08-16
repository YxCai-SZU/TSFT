#include <stdbool.h>

/*@
    requires (0 <= (a) < 0x80000000) && (0 <= (b) < 0x80000000) && (0 <= (c) < 0x80000000) && 
             (0 <= (d) < 0x80000000) && (0 <= (e) < 0x80000000);
    requires ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    requires k <= 123;
    ensures \result == (e - a <= k);
*/
bool func(unsigned int a, unsigned int b, unsigned int c, 
          unsigned int d, unsigned int e, unsigned int k)
{
    unsigned int f;
    int i;
    
    f = a;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant ((f) == (a) || (f) == (b) || (f) == (c) || (f) == (d) || (f) == (e));
        loop invariant (0 <= (a) < 0x80000000) && (0 <= (b) < 0x80000000) && (0 <= (c) < 0x80000000) && 
                     (0 <= (d) < 0x80000000) && (0 <= (e) < 0x80000000);
        loop invariant ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
        loop invariant k <= 123;
        loop assigns f, i;
    */
    while (i < 5)
    {
        //@ assert 0 <= i <= 5;
        
        if (i == 0) {
            f = a;
        } else if (i == 1) {
            f = b;
        } else if (i == 2) {
            f = c;
        } else if (i == 3) {
            f = d;
        } else if (i == 4) {
            f = e;
        }
        
        i = i + 1;
    }
    
    //@ assert ((f) == (a) || (f) == (b) || (f) == (c) || (f) == (d) || (f) == (e));
    return (e - a) <= k;
}

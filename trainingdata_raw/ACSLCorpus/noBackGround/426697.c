#include <stdbool.h>
#include <stdint.h>

/*@
    requires (1 <= (h) <= 10000 && 1 <= (a) <= 10000);
    ensures \result >= h / a;
    ensures h % a == 0 ==> \result == h / a;
    ensures h % a != 0 ==> \result == h / a + 1;
*/
unsigned int func(unsigned int h, unsigned int a)
{
    unsigned int c;
    
    c = h / a;
    
    if (h % a != 0)
    {
        //@ assert c < 4294967295;
        c = c + 1;
    }
    
    return c;
}

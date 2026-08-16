#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    requires a == (int64_t)a && b == (int64_t)b && c == (int64_t)c;
    ensures \result >= 0;
    ensures \result <= a + b + c;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t ret = 0;
    
    if (c > a + b + 1)
    {
        ret += c - (a + b + 1);
        int64_t c_new = a + b + 1;
        //@ assert ret >= 0;
        ret += (c_new > b) ? (c_new - b) : 0;
    }
    else
    {
        ret += (c - 1 > b) ? (c - 1 - b) : 0;
    }
    
    //@ assert ret <= a + b + c;
    return ret;
}

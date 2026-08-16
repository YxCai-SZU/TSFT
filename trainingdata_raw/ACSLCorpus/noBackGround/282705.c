#include <stdbool.h>

/*@ requires a < 0x80000000 && b < 0x80000000 && c < 0x80000000 &&
             d < 0x80000000 && e < 0x80000000 && k < 0x80000000 &&
             ((a) <= (b) && (b) <= (c) && (c) <= (d) && (d) <= (e) && (a) <= (e)) && e <= 123;
    ensures \result == true <==> (e - a <= k);
*/
bool func(unsigned int a, unsigned int b, unsigned int c,
          unsigned int d, unsigned int e, unsigned int k)
{
    bool result;
    
    //@ assert ((a) <= (b) && (b) <= (c) && (c) <= (d) && (d) <= (e) && (a) <= (e));
    
    result = (e - a <= k);
    return result;
}

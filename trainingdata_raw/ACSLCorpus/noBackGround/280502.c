#include <stdbool.h>

/*@ requires (0 <= (a) && (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e) && (e) <= 123) && (0 <= (k) && (k) <= 123);
    ensures \result == (((e) - (a)) <= k);
*/
bool func(unsigned int a, unsigned int b, unsigned int c, 
          unsigned int d, unsigned int e, unsigned int k)
{
    unsigned int dist;
    bool result;

    //@ assert 0 <= a && a < b && b < c && c < d && d < e && e <= 123;
    
    dist = e - a;
    
    //@ assert dist == ((e) - (a));
    
    if (dist <= k) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}

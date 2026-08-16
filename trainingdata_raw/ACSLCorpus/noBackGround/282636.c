#include <limits.h>

/*@
  requires (1 <= (a) && (a) <= 10000 &&
      1 <= (b) && (b) <= 10000 &&
      1 <= (c) && (c) <= 10000 &&
      1 <= (d) && (d) <= 10000);
  ensures \result == a + c || \result == b + d || \result == a + d || \result == b + c;
  assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int min_ab;
    unsigned int min_cd;
    unsigned int max1;
    unsigned int result;

    //@ assert (1 <= (a) && (a) <= 10000 &&       1 <= (b) && (b) <= 10000 &&       1 <= (c) && (c) <= 10000 &&       1 <= (d) && (d) <= 10000);
    
    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }
    //@ assert min_ab == ((a) < (b) ? (a) : (b));
    
    if (c < d) {
        min_cd = c;
    } else {
        min_cd = d;
    }
    //@ assert min_cd == ((c) < (d) ? (c) : (d));
    
    if (min_ab + c > a + min_cd) {
        max1 = min_ab + c;
    } else {
        max1 = a + min_cd;
    }
    //@ assert max1 == ((min_ab + c) > (a + min_cd) ? (min_ab + c) : (a + min_cd));
    
    if (max1 > b + d) {
        result = max1;
    } else {
        result = b + d;
    }
    //@ assert result == ((max1) > (b + d) ? (max1) : (b + d));
    
    //@ assert result == a + c || result == b + d || result == a + d || result == b + c;
    return result;
}

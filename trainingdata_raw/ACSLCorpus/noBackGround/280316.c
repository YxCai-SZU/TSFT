#include <stdbool.h>

/*@
  requires 1 <= a <= 9;
  requires 1 <= b <= 9;
  requires 1 <= c <= 9;
  ensures \result == 1 <==> (((a) == (b) && (a) != (c)) ||
      ((a) == (c) && (a) != (b)) ||
      ((b) == (c) && (b) != (a)));
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    bool ab;
    bool ac;
    bool bc;
    unsigned int count;
    
    ab = (a == b);
    ac = (a == c);
    bc = (b == c);
    count = 0;
    
    if (ab) {
        count += 1;
    }
    if (ac) {
        count += 1;
    }
    if (bc) {
        count += 1;
    }
    
    //@ assert count == (ab ? 1 : 0) + (ac ? 1 : 0) + (bc ? 1 : 0);
    //@ assert count == 1 ==> (((a) == (b) && (a) != (c)) ||       ((a) == (c) && (a) != (b)) ||       ((b) == (c) && (b) != (a)));
    
    return (count == 1);
}

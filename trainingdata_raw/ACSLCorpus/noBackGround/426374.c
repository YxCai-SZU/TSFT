#include <stdbool.h>

/*@
  requires 1 <= a <= 10;
  requires 1 <= b <= 10;
  requires 1 <= c <= 10;
  ensures \result == (a + b == c || a + c == b || b + c == a);
*/
bool func(unsigned long a, unsigned long b, unsigned long c) {
    bool result;
    //@ assert 1 <= a <= 10;
    //@ assert 1 <= b <= 10;
    //@ assert 1 <= c <= 10;
    
    if (a + b == c || a + c == b || b + c == a) {
        //@ assert a + b == c || a + c == b || b + c == a;
        result = true;
    } else {
        //@ assert a + b != c && a + c != b && b + c != a;
        result = false;
    }
    
    //@ assert result == (a + b == c || a + c == b || b + c == a);
    return result;
}

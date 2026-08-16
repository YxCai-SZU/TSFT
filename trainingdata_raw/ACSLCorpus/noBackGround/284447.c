#include <stdbool.h>

/*@ requires 1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9;
    ensures \result == 1 <==> (((a) == (b) && (c) != (a) && (c) != (b)) ||
      ((a) == (c) && (b) != (a) && (b) != (c)) ||
      ((b) == (c) && (a) != (b) && (a) != (c)));
*/
bool func(long a, long b, long c)
{
    int cnt = 0;
    //@ assert cnt == 0;
    
    if (a == b) {
        cnt += 1;
    }
    //@ assert cnt == (a == b ? 1 : 0);
    
    if (a == c) {
        cnt += 1;
    }
    //@ assert cnt == (a == b ? 1 : 0) + (a == c ? 1 : 0);
    
    if (b == c) {
        cnt += 1;
    }
    //@ assert cnt == (a == b ? 1 : 0) + (a == c ? 1 : 0) + (b == c ? 1 : 0);
    
    //@ assert cnt == 0 || cnt == 1 || cnt == 2 || cnt == 3;
    
    bool result = (cnt == 1);
    //@ assert result == 1 <==> (((a) == (b) && (c) != (a) && (c) != (b)) ||       ((a) == (c) && (b) != (a) && (b) != (c)) ||       ((b) == (c) && (a) != (b) && (a) != (c)));
    return result;
}

#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int min1;
    int min2;
    int result;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    min1 = (a < b) ? a : b;
    min2 = (min1 < c) ? min1 : c;
    
    result = 0;
    
    //@ assert min2 == (((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c))));
    
    if (a == min2) {
        result += 1;
    }
    if (b == min2) {
        result += 1;
    }
    if (c == min2) {
        result += 1;
    }
    
    //@ assert result >= 1 && result <= 3;
    
    return result;
}

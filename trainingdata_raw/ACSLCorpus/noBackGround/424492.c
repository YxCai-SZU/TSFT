#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100) && (0 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result <= a + b;
    assigns \nothing;
*/
int func(int a, int b)
{
    int max;
    int min;
    int diff;
    int result;

    //@ assert (0 <= (a) <= 100) && (0 <= (b) <= 100);
    
    if (a > b) {
        max = a;
        min = b;
    } else {
        max = b;
        min = a;
    }
    
    //@ assert max == ((a) > (b) ? (a) : (b));
    //@ assert min == ((a) > (b) ? (b) : (a));
    
    diff = max - min;
    
    //@ assert diff == ((((a)) > ((b)) ? ((a)) : ((b))) - (((a)) > ((b)) ? ((b)) : ((a))));
    
    if (diff < 2) {
        result = 0;
        //@ assert result >= 0;
        //@ assert result <= a + b;
        return result;
    } else {
        //@ assert diff >= 2;
        //@ assert diff - 2 >= 0;
        //@ assert diff - 2 <= a + b;
        result = diff - 2;
        return result;
    }
}

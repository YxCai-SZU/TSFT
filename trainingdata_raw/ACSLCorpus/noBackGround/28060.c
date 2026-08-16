#include <stdbool.h>

/*@
    requires (3 <= (a) && (a) <= 20);
    requires (3 <= (b) && (b) <= 20);
    ensures \result == ((a) + (b)) || \result == ((b) * 2 - 1) || \result == ((a) * 2 - 1);
    ensures \result >= ((a) + (b));
    ensures \result >= ((b) * 2 - 1);
    ensures \result >= ((a) * 2 - 1);
*/
int func(int a, int b)
{
    int max1;
    int max2;

    //@ assert (3 <= (a) && (a) <= 20);
    //@ assert (3 <= (b) && (b) <= 20);
    
    if (a + b > b * 2 - 1) {
        max1 = a + b;
    } else {
        max1 = b * 2 - 1;
    }
    
    //@ assert max1 >= a + b && max1 >= b * 2 - 1;
    
    if (max1 > a * 2 - 1) {
        max2 = max1;
    } else {
        max2 = a * 2 - 1;
    }
    
    //@ assert max2 >= max1 && max2 >= a * 2 - 1;
    //@ assert max2 >= a + b;
    //@ assert max2 >= b * 2 - 1;
    //@ assert max2 >= a * 2 - 1;
    
    return max2;
}

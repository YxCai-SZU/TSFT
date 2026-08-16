#include <stdbool.h>

/*@
    requires (3 <= (a) <= 20);
    requires (3 <= (b) <= 20);
    ensures \result == ((a) >= (b) + 1 ? 2 * (a) - 1 :
        (b) >= (a) + 1 ? 2 * (b) - 1 :
        (a) + (b));
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result = 0;
    //@ assert (3 <= (a) <= 20) && (3 <= (b) <= 20);
    
    if (a >= b + 1) {
        result = a * 2 - 1;
        //@ assert result == 2 * a - 1;
    } else if (b >= a + 1) {
        result = b * 2 - 1;
        //@ assert result == 2 * b - 1;
    } else {
        result = a + b;
        //@ assert result == a + b;
    }
    
    //@ assert result == ((a) >= (b) + 1 ? 2 * (a) - 1 :         (b) >= (a) + 1 ? 2 * (b) - 1 :         (a) + (b));
    //@ assert result >= 0;
    return result;
}

/*@
    requires \true;
    ensures \result == (a > b ? a : b);
    assigns \nothing;
*/
int max(int a, int b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}


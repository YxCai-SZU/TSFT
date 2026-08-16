#include <stdbool.h>

/*@ requires (1 <= (a) && (a) <= 100 &&
      1 <= (b) && (b) <= 100);
    ensures \result >= 0;
    ensures \result == a - b * 2 || \result == 0;
*/
int func(int a, int b)
{
    int res;
    //@ assert (1 <= (a) && (a) <= 100 &&       1 <= (b) && (b) <= 100);
    res = a - b * 2;
    
    if (res > 0) {
        //@ assert res == a - b * 2;
        return res;
    } else {
        //@ assert res <= 0;
        return 0;
    }
}

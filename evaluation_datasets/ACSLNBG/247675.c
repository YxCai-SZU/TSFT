#include <stdbool.h>


bool func(int k, int x)
{
    int en = 500;
    //@ assert (1 <= (k) * 500 <= 100 * 500);
    return k * en >= x;
}

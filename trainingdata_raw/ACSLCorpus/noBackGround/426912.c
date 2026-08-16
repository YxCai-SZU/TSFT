#include <stdbool.h>

/*@ requires (1 <= (d) && (d) <= 10000 &&
     1 <= (t) && (t) <= 10000 &&
     1 <= (s) && (s) <= 10000);
    ensures \result == true <==> d <= t * s;
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    int i;
    i = 0;
    
    /*@ loop invariant 0 <= i <= 10;
        loop invariant (1 <= (d) && (d) <= 10000 &&
     1 <= (t) && (t) <= 10000 &&
     1 <= (s) && (s) <= 10000);
        loop assigns i;
        loop variant 10 - i;
    */
    while (i < 10)
    {
        //@ assert 1 <= t * s <= 10000 * 10000;
        i = i + 1;
    }
    
    //@ assert t > 0 && s > 0;
    //@ assert t * s <= 10000 * 10000;
    
    if (d <= t * s)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(void)
{
    return 0;
}

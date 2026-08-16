#include <limits.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result <= (((((a)) > ((b)) ? ((a)) : ((b))) * 2) * ((((a)) > ((b)) ? ((b)) : ((a))) - 1) + ((((a)) > ((b)) ? ((b)) : ((a))) * 2) * ((((a)) > ((b)) ? ((a)) : ((b))) - 1));
    assigns \nothing;
*/
int func(int a, int b)
{
    int x;
    int y;
    int p;
    int result = 0;
    int temp_p;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);

    if (a > b) {
        x = a;
        y = b;
    } else {
        x = b;
        y = a;
    }

    //@ assert x == ((a) > (b) ? (a) : (b)) && y == ((a) > (b) ? (b) : (a));
    //@ assert (1 <= (x) <= 100 && 1 <= (y) <= 100);

    p = (x * 2) * (y - 1) + (y * 2) * (x - 1);
    //@ assert p == (((((a)) > ((b)) ? ((a)) : ((b))) * 2) * ((((a)) > ((b)) ? ((b)) : ((a))) - 1) + ((((a)) > ((b)) ? ((b)) : ((a))) * 2) * ((((a)) > ((b)) ? ((a)) : ((b))) - 1));
    //@ assert p >= 0;

    temp_p = p;

    /*@
        loop invariant 0 <= temp_p <= p;
        loop invariant result >= 0;
        loop invariant temp_p + 2 * result == p;
        loop assigns result, temp_p;
        loop variant temp_p;
    */
    while (temp_p >= 2)
    {
        //@ assert temp_p >= 2;
        result += 1;
        temp_p -= 2;
        //@ assert temp_p + 2 * result == p;
    }

    //@ assert temp_p < 2;
    //@ assert result == p / 2;
    //@ assert result >= 0;
    //@ assert result <= p;

    return result;
}

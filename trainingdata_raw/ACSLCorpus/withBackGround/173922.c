#include <stdbool.h>

/*@ predicate in_range_40(integer x) = -40 <= x <= 40; */
/*@ predicate in_range_100(integer x) = 1 <= x <= 100; */
/*@ predicate is_even(integer y) = y % 2 == 0; */
/*@ logic integer half(integer y) = y / 2; */

/*@
    requires in_range_40(X);
    ensures \result == (X >= 30);
    ensures \result ==> X >= 30;
    ensures !\result ==> X < 30;
*/
bool func(int X)
{
    //@ assert in_range_40(X);
    if (X >= 30)
    {
        //@ assert X >= 30;
        return true;
    }
    else
    {
        //@ assert X < 30;
        return false;
    }
}

/*@
    requires in_range_100(X);
    requires in_range_100(Y);
    requires is_even(Y);
    ensures \result == X + half(Y);
*/
int simple_calc(int X, int Y)
{
    int half_Y;
    //@ assert in_range_100(X);
    //@ assert in_range_100(Y);
    //@ assert is_even(Y);
    
    if (Y >= 0)
    {
        int count = 0;
        int temp_Y = Y;
        /*@
            loop invariant 0 <= temp_Y <= Y;
            loop invariant 0 <= count <= half(Y);
            loop invariant temp_Y == Y - 2 * count;
            loop assigns temp_Y, count;
        */
        while (temp_Y >= 2)
        {
            //@ assert temp_Y >= 2;
            temp_Y -= 2;
            count += 1;
        }
        half_Y = count;
        //@ assert half_Y == half(Y);
    }
    else
    {
        int count = 0;
        int temp_Y = Y;
        /*@
            loop invariant Y <= temp_Y <= 0;
            loop invariant half(Y) <= count <= 0;
            loop invariant temp_Y == Y - 2 * count;
            loop assigns temp_Y, count;
        */
        while (temp_Y <= -2)
        {
            //@ assert temp_Y <= -2;
            temp_Y += 2;
            count -= 1;
        }
        half_Y = count;
        //@ assert half_Y == half(Y);
    }
    
    int result = X + half_Y;
    //@ assert result == X + half(Y);
    return result;
}

#include <stdbool.h>

/*@
    requires \valid(v + (0..2));
    requires v[0] >= 0 && v[0] <= 100;
    requires v[1] >= 0 && v[1] <= 100;
    requires v[2] >= 0 && v[2] <= 100;
    requires ((v[0]) != (v[1]) && (v[1]) != (v[2]) && (v[0]) != (v[2]));
    ensures \result == 1 <==> ((((v[0])) < ((v[1])) && ((v[1])) < ((v[2]))) || (((v[0])) > ((v[1])) && ((v[1])) > ((v[2]))));
*/
bool func(int v[3])
{
    int a;
    int b;
    int c;
    bool inc_flag;
    bool dec_flag;
    bool result;

    a = v[0];
    b = v[1];
    c = v[2];
    inc_flag = false;
    dec_flag = false;

    //@ assert ((a) != (b) && (b) != (c) && (a) != (c));

    if (a < b)
    {
        inc_flag = true;
        //@ assert inc_flag ==> a < b;
    }
    else
    {
        dec_flag = true;
        //@ assert dec_flag ==> a > b;
    }

    if ((inc_flag && b < c) || (dec_flag && b > c))
    {
        //@ assert (inc_flag && b < c) || (dec_flag && b > c);
        result = true;
        //@ assert result == 1 <==> ((((a)) < ((b)) && ((b)) < ((c))) || (((a)) > ((b)) && ((b)) > ((c))));
        return result;
    }
    else
    {
        result = false;
        //@ assert result == 0 <==> !((((a)) < ((b)) && ((b)) < ((c))) || (((a)) > ((b)) && ((b)) > ((c))));
        return result;
    }
}

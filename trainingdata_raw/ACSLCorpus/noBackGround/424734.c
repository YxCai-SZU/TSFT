#include <limits.h>

/*@
    requires x != y;
    requires ((x) >= -1000000000 && (x) <= 1000000000);
    requires ((y) >= -1000000000 && (y) <= 1000000000);
    ensures \result >= 0;
    ensures \result <= 1000000000;
    ensures \result == ((((x) < (y) ? (y) - (x) : (x) - (y))) % 10 == 0 ? (((x) < (y) ? (y) - (x) : (x) - (y))) / 10 : (((x) < (y) ? (y) - (x) : (x) - (y))) / 10 + 1);
*/
int func(int x, int y)
{
    int abs_val;
    int z;
    int temp_abs_val;

    //@ assert x != y;
    //@ assert ((x) >= -1000000000 && (x) <= 1000000000);
    //@ assert ((y) >= -1000000000 && (y) <= 1000000000);

    if (x < y) {
        abs_val = y - x;
    } else {
        abs_val = x - y;
    }

    //@ assert abs_val == ((x) < (y) ? (y) - (x) : (x) - (y));
    //@ assert abs_val >= 0;

    z = 0;
    temp_abs_val = abs_val;

    /*@
        loop invariant temp_abs_val >= 0;
        loop invariant z >= 0;
        loop invariant z <= 1000000000;
        loop invariant temp_abs_val + 10 * z == abs_val;
        loop assigns temp_abs_val, z;
    */
    while (temp_abs_val >= 10)
    {
        //@ assert temp_abs_val >= 10;
        temp_abs_val -= 10;
        z += 1;
        //@ assert temp_abs_val >= 0;
        //@ assert z >= 0;
        //@ assert temp_abs_val + 10 * z == abs_val;
    }

    //@ assert temp_abs_val >= 0;
    //@ assert temp_abs_val < 10;
    //@ assert z >= 0;
    //@ assert temp_abs_val + 10 * z == abs_val;

    if (temp_abs_val != 0) {
        z += 1;
    }

    //@ assert z == ((abs_val) % 10 == 0 ? (abs_val) / 10 : (abs_val) / 10 + 1);
    //@ assert z >= 0;
    //@ assert z <= 1000000000;

    return z;
}

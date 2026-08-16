#include <stdbool.h>

/*@
    requires \valid(v+(0..2));
    requires ((3) == 3);
    requires ((3) > 0 ==> (v)[0] == 0);
    requires ((3) > 1 ==> (v)[1] > 0);
    requires ((3) > 2 ==> (v)[2] > 0);
    ensures \result == true <==> ((3) > 2 ==> (v)[1] <= (v)[2]);
*/
bool func(int *v)
{
    int s;
    int w;
    bool result;

    //@ assert ((3) == 3);
    //@ assert ((3) > 0 ==> (v)[0] == 0);
    //@ assert ((3) > 1 ==> (v)[1] > 0);
    //@ assert ((3) > 2 ==> (v)[2] > 0);

    s = v[1];
    w = v[2];

    //@ assert s > 0;
    //@ assert w > 0;

    result = s <= w;
    return result;
}

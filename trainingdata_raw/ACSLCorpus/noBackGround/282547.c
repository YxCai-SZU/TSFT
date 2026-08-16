#include <stdbool.h>

/*@
    requires \valid(v + (0..2));
    requires (1 <= (v[0]) <= 100);
    requires (1 <= (v[1]) <= 100);
    requires (1 <= (v[2]) <= 100);
    assigns \nothing;
    ensures 1 <= \result <= 3;
    ensures \result == 1 ==> (v[0] == v[1] && v[1] == v[2]);
    ensures \result == 2 ==> (v[0] == v[1] || v[1] == v[2] || v[0] == v[2]);
    ensures \result == 3 ==> (v[0] != v[1] && v[1] != v[2] && v[0] != v[2]);
*/
int func(int *v)
{
    int result;

    //@ assert (1 <= (v[0]) <= 100);
    //@ assert (1 <= (v[1]) <= 100);
    //@ assert (1 <= (v[2]) <= 100);

    if (v[0] == v[1] && v[1] == v[2]) {
        result = 1;
    } else if (v[0] == v[1] || v[1] == v[2] || v[0] == v[2]) {
        result = 2;
    } else {
        result = 3;
    }

    //@ assert 1 <= result <= 3;
    //@ assert result == 1 ==> (v[0] == v[1] && v[1] == v[2]);
    //@ assert result == 2 ==> (v[0] == v[1] || v[1] == v[2] || v[0] == v[2]);
    //@ assert result == 3 ==> (v[0] != v[1] && v[1] != v[2] && v[0] != v[2]);

    return result;
}

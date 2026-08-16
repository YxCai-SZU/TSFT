#include <stdbool.h>

/*@
    predicate has_one_at_index(int *v, integer i) =
        v[i] == 1;

    predicate valid_pair(int *v, integer i, integer j) =
        has_one_at_index(v, i) && has_one_at_index(v, j);

    predicate result_condition(int *v) =
        valid_pair(v, 4, 5) ||
        valid_pair(v, 0, 1) ||
        valid_pair(v, 0, 5) ||
        valid_pair(v, 1, 4);
*/

/*@
    requires \valid(v + (0..5));
    requires v[0] == 1 || v[1] == 1 || v[2] == 1 || v[3] == 1 || v[4] == 1 || v[5] == 1;
    requires \forall integer i; 0 <= i < 6 ==> v[i] == 1 || v[i] == 2 || v[i] == 3;
    ensures \result == true <==> result_condition(v);
*/
bool func(int *v)
{
    bool is_pass = false;

    //@ assert v[0] == 1 || v[1] == 1 || v[2] == 1 || v[3] == 1 || v[4] == 1 || v[5] == 1;

    if (v[4] == 1 && v[5] == 1)
    {
        is_pass = true;
    }
    else if (v[0] == 1 && v[1] == 1)
    {
        is_pass = true;
    }
    else if (v[0] == 1 && v[5] == 1)
    {
        is_pass = true;
    }
    else if (v[1] == 1 && v[4] == 1)
    {
        is_pass = true;
    }

    //@ assert is_pass == true <==> result_condition(v);
    return is_pass;
}

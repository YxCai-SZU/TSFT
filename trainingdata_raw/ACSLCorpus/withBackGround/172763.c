/*@
    predicate is_valid_input(integer a, integer b) =
        a != b &&
        (a == 1 || a == 2 || a == 3) &&
        (b == 1 || b == 2 || b == 3);

    predicate is_valid_output(integer res, integer a, integer b) =
        (res == 1 || res == 2 || res == 3) &&
        res != a &&
        res != b;

    logic integer compute_res(integer a, integer b) = 6 - a - b;

    lemma res_property:
        \forall integer a, b;
            is_valid_input(a, b) ==>
            (compute_res(a, b) == 1 || compute_res(a, b) == 2 || compute_res(a, b) == 3);
*/

/*@
    requires is_valid_input(a, b);
    ensures is_valid_output(\result, a, b);
*/
int func(int a, int b)
{
    int res;

    //@ assert a != b;
    //@ assert (a == 1 || a == 2 || a == 3) && (b == 1 || b == 2 || b == 3);
    
    res = 6 - a - b;
    
    //@ assert res == 1 || res == 2 || res == 3;
    //@ assert res != a && res != b;
    
    return res;
}

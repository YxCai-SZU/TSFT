/*@
predicate all_equal(integer x, integer y, integer z) = x == y && y == z;
predicate two_equal(integer x, integer y, integer z) = x == y || y == z || x == z;
predicate none_equal(integer x, integer y, integer z) = x != y && y != z && x != z;

lemma all_equal_implies_two_equal: \forall integer x, y, z; all_equal(x, y, z) ==> two_equal(x, y, z);
lemma two_equal_implies_not_none_equal: \forall integer x, y, z; two_equal(x, y, z) ==> !none_equal(x, y, z);
lemma none_equal_implies_not_two_equal: \forall integer x, y, z; none_equal(x, y, z) ==> !two_equal(x, y, z);
*/

/*@
requires \true;
ensures \result == 3 ==> all_equal(x, y, z);
ensures \result == 2 ==> two_equal(x, y, z);
ensures \result == 0 ==> none_equal(x, y, z);
assigns \nothing;
*/
int test_three_equal(int x, int y, int z)
{
    int ret;
    //@ ghost int x_val = x;
    //@ ghost int y_val = y;
    //@ ghost int z_val = z;

    if (x == y && y == z)
    {
        //@ assert all_equal(x_val, y_val, z_val);
        ret = 3;
    }
    else if (x == y || y == z || x == z)
    {
        //@ assert two_equal(x_val, y_val, z_val);
        ret = 2;
    }
    else
    {
        //@ assert none_equal(x_val, y_val, z_val);
        ret = 0;
    }
    return ret;
}

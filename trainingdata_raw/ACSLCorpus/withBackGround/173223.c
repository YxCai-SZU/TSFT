/*@
    predicate is_within_range(integer a) = -1000 <= a && a < 1000;
    logic integer double_spec(integer a) = 2 * a;
*/

/*@
    requires is_within_range(a);
    ensures \result == double_spec(a);
    assigns \nothing;
*/
int double_val(int a)
{
    int res;
    //@ assert is_within_range(a);
    res = a * 2;
    //@ assert res == double_spec(a);
    return res;
}

int main(void)
{
    int x;
    int r;
    x = 10;
    //@ assert is_within_range(x);
    r = double_val(x);
    //@ assert r == 20;
    return 0;
}

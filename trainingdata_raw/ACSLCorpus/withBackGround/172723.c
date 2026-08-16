/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer func_spec(integer a, integer b) = a * b;

    lemma product_in_range:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==> 1 <= func_spec(a, b) <= 10000;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == func_spec(a, b);
*/
int func(int a, int b)
{
    // Variable declarations at scope top
    int ans;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert 1 <= func_spec(a, b) <= 10000;

    ans = a * b;
    return ans;
}

int main()
{
    return 0;
}

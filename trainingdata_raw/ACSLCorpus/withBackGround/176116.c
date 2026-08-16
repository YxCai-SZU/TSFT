/*@
    predicate pos(int x) = x > 0;
    predicate less_than(int a, int b) = a < b;
*/

/*@
    requires x > 10;
    ensures \result > 0;
*/
int complex_calc_example(int x)
{
    int result;
    //@ assert x > 10;
    result = x - 3;
    //@ assert result > 0;
    return result;
}

/*@
    requires n > 0;
    ensures \result > 0;
*/
int nontrivial_conditionals(int n)
{
    int result;
    //@ assert n > 0;
    result = n;
    //@ assert result > 0;
    return result;
}

/*@
    requires k > 0;
    ensures \result > 0;
*/
int loop_invariants(int k)
{
    int i = 0;
    int result = k;
    /*@
        loop invariant 0 <= i <= k;
        loop invariant result == k;
        loop invariant result > 0;
        loop assigns i, result;
    */
    while (i < k)
    {
        //@ assert result > 0;
        i = i + 1;
    }
    //@ assert result > 0;
    return result;
}

/*@
    requires m > 0;
    ensures \result > 0;
*/
int assertion_example(int m)
{
    int result;
    //@ assert m > 0;
    result = m;
    //@ assert result > 0;
    return result;
}

/*@
    requires a > 0;
    requires b > 0;
    requires a < b;
    ensures \result > 0;
*/
int prove_range_of_calc(int a, int b)
{
    int result;
    //@ assert b > a;
    result = b - a;
    //@ assert result > 0;
    return result;
}

int main()
{
    return 0;
}

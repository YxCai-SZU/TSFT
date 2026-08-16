/*@
requires a == b + 2;
ensures \result >= b;
assigns \nothing;
*/
int proof_of_greater_than_or_equal(int a, int b)
{
    //@ assert a == b + 2;
    return a;
}

/*@
requires x == x;
ensures \result == 0;
assigns \nothing;
*/
int assert_same_value(int x)
{
    //@ assert x == x;
    return 0;
}

/*@
assigns \nothing;
*/
int main()
{
    int a;
    int b;
    int x;
    
    a = 5;
    b = 3;
    //@ assert a == b + 2;
    proof_of_greater_than_or_equal(a, b);
    
    x = 10;
    //@ assert x == x;
    assert_same_value(x);
    
    return 0;
}

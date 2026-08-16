/*@
    requires x >= 0;
    ensures \result <= x + 5;
*/
int transitivity_example(int x)
{
    //@ assert x <= x + 5;
    return x;
}

/*@
    requires x >= 0 && x < 100;
    ensures \result <= 99;
*/
int non_trivial_inequality(int x)
{
    //@ assert x <= 99;
    return x;
}

/*@
    requires x >= 0 && x < 100;
    ensures \result == x;
*/
int non_trivial_equality(int x)
{
    //@ assert x == x;
    return x;
}

/*@
    requires x >= 0;
    ensures \result <= x + 2;
*/
int different_transitivity(int x)
{
    //@ assert x <= x + 2;
    return x;
}

/*@
    requires x >= 0 && x < 100;
    ensures \result <= 99;
*/
int non_trivial_chain(int x)
{
    //@ assert x <= 99;
    return x;
}

/*@
    requires x >= 0 && x < 100;
    ensures \result <= 99;
*/
int very_non_trivial_chain(int x)
{
    //@ assert x <= 99;
    return x;
}

int main()
{
    return 0;
}

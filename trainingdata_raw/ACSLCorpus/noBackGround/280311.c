/*@
    requires a < b;
    ensures \result == 1;
    assigns \nothing;
*/
int calc_example_v(int a, int b)
{
    //@ assert a - 1 < b - 1;
    return 1;
}

/*@
    requires x <= y <= z;
    ensures \result == 1;
    assigns \nothing;
*/
int proof_add_is_transitive(int x, int y, int z)
{
    //@ assert x + 1 <= y + 1 <= z + 1;
    return 1;
}

/*@
    requires x == y && y == z;
    ensures \result == 1;
    assigns \nothing;
*/
int proof_equal_is_transitive(int x, int y, int z)
{
    //@ assert x == z;
    return 1;
}

/*@
    requires x < y && y < z;
    ensures \result == 1;
    assigns \nothing;
*/
int proof_less_is_transitive(int x, int y, int z)
{
    //@ assert x < z;
    return 1;
}

/*@
    requires x >= y && y >= z;
    ensures \result == 1;
    assigns \nothing;
*/
int proof_geq_is_transitive(int x, int y, int z)
{
    //@ assert x >= z;
    return 1;
}

/*@
    requires x <= y && y <= z;
    ensures \result == 1;
    assigns \nothing;
*/
int proof_leq_is_transitive(int x, int y, int z)
{
    //@ assert x <= z;
    return 1;
}

int main()
{
    return 0;
}

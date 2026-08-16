/*@
requires a <= b && b <= c;
ensures \result == 1;
assigns \nothing;
*/
int calc_example_2(int a, int b, int c)
{
    //@ assert a <= b && b <= c ==> a <= c;
    return 1;
}

/*@
requires a <= b && b <= c;
ensures \result == 1;
assigns \nothing;
*/
int proof_transitive(int a, int b, int c)
{
    //@ assert a <= b && b <= c ==> a <= c;
    return 1;
}

/*@
requires a <= b && b <= c;
ensures \result == 1;
assigns \nothing;
*/
int is_c_less_or_equal_to_a_and_b(int a, int b, int c)
{
    //@ assert a <= b && b <= c ==> a <= c;
    return 1;
}

/*@
requires a <= b && b <= c;
ensures \result == 1;
assigns \nothing;
*/
int different_relation(int a, int b, int c)
{
    //@ assert a <= b && b <= c ==> a <= c;
    return 1;
}

int main()
{
    return 0;
}

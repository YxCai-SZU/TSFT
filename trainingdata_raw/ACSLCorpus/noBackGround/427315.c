/*@
    requires x == y;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_7(int x, int y)
{
    //@ assert x + 0 == y;
    return 0;
}

/*@
    requires x == y;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_8(int x, int y)
{
    //@ assert x * 1 == y;
    return 0;
}

/*@
    requires x == y && x != 0;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_9(int x, int y)
{
    //@ assert x / 1 == y;
    return 0;
}

/*@
    requires x == y && x != 0;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_10(int x, int y)
{
    //@ assert x % 1 == y % 1;
    return 0;
}

int main()
{
    return 0;
}

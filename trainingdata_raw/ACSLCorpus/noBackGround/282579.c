/*@
    requires n > 0;
    ensures \result > 0;
    ensures \result == ((n) <= 0 ? 0 :
        (n) == 1 ? 1 :
        ((n) * ((n) + 1) * ((n) + 2)) / 6);
    assigns \nothing;
*/
int compute_tetrahedral_number(int n)
{
    int result;
    int i;
    result = 0;
    /*@
        loop invariant 0 <= i <= n + 1;
        loop invariant i == 0 ==> result == 0;
        loop invariant i > 0 ==> result == ((i - 1) <= 0 ? 0 :
        (i - 1) == 1 ? 1 :
        ((i - 1) * ((i - 1) + 1) * ((i - 1) + 2)) / 6);
        loop assigns i, result;
        loop variant n - i;
    */
    for (i = 0; i <= n; ++i)
    {
        if (i <= 0)
        {
            result = 0;
        }
        else if (i == 1)
        {
            result = 1;
        }
        else
        {
            //@ assert ((i - 1) <= 0 ? 0 :         (i - 1) == 1 ? 1 :         ((i - 1) * ((i - 1) + 1) * ((i - 1) + 2)) / 6) > 0;
            result = (i * (i + 1) * (i + 2)) / 6;
        }
    }
    //@ assert result == ((n) <= 0 ? 0 :         (n) == 1 ? 1 :         ((n) * ((n) + 1) * ((n) + 2)) / 6);
    //@ assert result > 0;
    return result;
}

/*@
    assigns \nothing;
*/
void example_tetrahedral_number()
{
    int n;
    int result;
    n = 5;
    //@ assert ((n) <= 0 ? 0 :         (n) == 1 ? 1 :         ((n) * ((n) + 1) * ((n) + 2)) / 6) > 0;
    result = compute_tetrahedral_number(n);
    //@ assert result > 0;
}

/*@
    assigns \nothing;
*/
int main()
{
    example_tetrahedral_number();
    return 0;
}

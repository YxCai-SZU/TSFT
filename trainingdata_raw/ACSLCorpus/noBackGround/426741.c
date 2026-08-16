/*@
    requires 1 <= n <= 9;
    ensures \result == 1 <==> ((n) == 3 || (n) == 5 || (n) == 7);
    assigns \nothing;
*/
int func(int n)
{
    int result;
    //@ assert 1 <= n <= 9;
    switch (n)
    {
        case 3:
        case 5:
        case 7:
            result = 1;
            break;
        default:
            result = 0;
            break;
    }
    //@ assert result == 1 <==> ((n) == 3 || (n) == 5 || (n) == 7);
    return result;
}

/*@
    requires a == b + c;
    ensures \true;
    assigns \nothing;
*/
void example_3(int a, int b, int c)
{
    //@ assert a == b + c;
    //@ assert a <= b + c + 1;
}

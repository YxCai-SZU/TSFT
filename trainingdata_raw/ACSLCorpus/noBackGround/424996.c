/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
int func(int r)
{
    int pi = 3;
    int result;

    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r <= 30000;

    result = pi * r * r;
    return result;
}

int main()
{
    return 0;
}

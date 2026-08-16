/*@
    requires (0 <= (r) && (r) <= 100);
    ensures \result == ((r) * (r));
    assigns \nothing;
*/
int func(int r)
{
    //@ assert (0 <= (r) && (r) <= 100);
    int result;
    result = r * r;
    //@ assert result == ((r) * (r));
    return result;
}

int main()
{
    return 0;
}

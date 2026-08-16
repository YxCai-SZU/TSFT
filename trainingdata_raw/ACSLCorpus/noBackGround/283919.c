/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == r * r;
    assigns \nothing;
*/
int func(int r)
{
    int result;
    //@ assert 1 <= r && r <= 100;
    //@ assert r * r <= 10000;
    result = r * r;
    return result;
}

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == r * r;
    assigns \nothing;
*/
int func2(int r)
{
    int result;
    //@ assert 1 <= r && r <= 100;
    //@ assert r * r <= 10000;
    result = r * r;
    return result;
}

int main()
{
    return 0;
}

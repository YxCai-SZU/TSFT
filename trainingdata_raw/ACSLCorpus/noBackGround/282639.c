/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (2 * (n) * 3);
    assigns \nothing;
*/
long func(long n)
{
    long result;
    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert n >= 1;
    //@ assert n <= 100;
    result = 2 * n * 3;
    //@ assert result == (2 * (n) * 3);
    return result;
}

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
long area_circle(long r)
{
    long area;
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert r >= 1;
    //@ assert r <= 100;
    //@ assert 3 * r * r <= 3 * 100 * 100;
    area = 3 * r * r;
    //@ assert area == (3 * (r) * (r));
    return area;
}

int main()
{
    return 0;
}

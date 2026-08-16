/*@
    requires (1 <= (r) && (r) <= 100);
    requires r == (int)r;
    ensures \result == (3 * (r) * (r));
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int r)
{
    int result;
    //@ assert 1 <= r && r <= 100;
    //@ assert r <= 100;
    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r <= 30000;
    result = 3 * r * r;
    return result;
}

/*@
    requires 1 <= r <= 100;
    ensures \result == 3 * r * r;
    assigns \nothing;
*/
int func(int r)
{
    int result;
    //@ assert 1 <= r && r <= 100;
    //@ assert 3 * r * r <= 3 * 100 * 100;
    result = 3 * r * r;
    return result;
}

int main()
{
    //@ assert (((1) > (2)) ? (1) : (2)) == 2;
    //@ assert (((1) < (2)) ? (1) : (2)) == 1;
    return 0;
}

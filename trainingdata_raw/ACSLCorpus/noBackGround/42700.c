/*@
    requires (1 <= (a) && (a) <= 100);
    ensures \result == 3 * a * a;
    assigns \nothing;
*/
int func(int a)
{
    // Variable declarations at top of scope
    int result;

    //@ assert 1 <= a && a <= 100;
    //@ assert 3 * a <= 300;
    //@ assert 3 * a * a <= 300 * 100;

    result = 3 * a * a;
    return result;
}

int main()
{
    return 0;
}

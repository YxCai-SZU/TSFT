/*@
    requires (1 <= (x) && (x) <= 100) && (1 <= (y) && (y) <= 100);
    ensures \result == x * y;
    assigns \nothing;
*/
int func(int x, int y)
{
    //@ assert (1 <= (x) && (x) <= 100);
    //@ assert (1 <= (y) && (y) <= 100);
    //@ assert 1 <= x * y && x * y <= 10000;
    return x * y;
}

int main()
{
    //@ assert ((10) >= (20) ? (10) : (20)) == 20;
    //@ assert ((-10) >= (-20) ? (-10) : (-20)) == -10;
    return 0;
}

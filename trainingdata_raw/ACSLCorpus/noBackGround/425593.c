/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (d) >= 0 &&
        (a) <= 100 && (b) <= 100 && (c) <= 100 && (d) <= 100);
    ensures \result == ((a * c) >= (b * d));
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    //@ assert a * c <= 10000;
    //@ assert b * d <= 10000;
    return (a * c) >= (b * d);
}

int main()
{
    return 0;
}

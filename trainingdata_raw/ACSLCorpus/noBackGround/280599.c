/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (m) && (m) <= 100);
    ensures \result == n * m;
    assigns \nothing;
*/
int func(int n, int m)
{
    //@ assert (1 <= (n) && (n) <= 100 &&         1 <= (m) && (m) <= 100);
    //@ assert n * m <= 10000;
    return n * m;
}

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (m) && (m) <= 100);
    ensures \result == n * m;
    assigns \nothing;
*/
int main_func(int n, int m)
{
    //@ assert (1 <= (n) && (n) <= 100 &&         1 <= (m) && (m) <= 100);
    //@ assert n * m <= 10000;
    return n * m;
}

int main()
{
    return 0;
}

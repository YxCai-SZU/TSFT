/*@
    requires ((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c));
    ensures \result == 1;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    //@ assert ((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c));
    return 1;
}

/*@
    requires (((a) <= (b) && (b) <= (c)) || ((a) >= (b) && (b) >= (c)));
    ensures \result == 1;
    assigns \nothing;
*/
int func2(int a, int b, int c)
{
    //@ assert (((a) <= (b) && (b) <= (c)) || ((a) >= (b) && (b) >= (c)));
    return 1;
}

int main(void)
{
    return 0;
}

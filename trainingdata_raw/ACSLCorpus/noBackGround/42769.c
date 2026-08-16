/*@
    requires ((2) <= (x) && (x) <= (10));
    ensures \result == x * 2 && \result <= 20;
    assigns \nothing;
*/
int func(int x)
{
    int result;
    //@ assert ((2) <= (x) && (x) <= (10));
    result = x * 2;
    //@ assert result <= 20;
    return result;
}

int main()
{
    int a;
    int b;
    int c;
    int x;
    int temp1;
    int temp2;
    int temp3;

    a = 5;
    b = 7;
    c = 9;
    //@ assert ((a) <= (b) && (b) <= (c));
    temp1 = a + 1;
    temp2 = b + 1;
    temp3 = c + 1;
    //@ assert ((temp1) <= (temp2) && (temp2) <= (temp3));

    x = 8;
    //@ assert ((2) <= (x) && (x) <= (10));
    int r = func(x);
    //@ assert r <= 20;

    return 0;
}

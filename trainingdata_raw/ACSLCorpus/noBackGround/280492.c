/*@
    requires a < b && b < c && c < d && d < e;
    ensures \result == 0;
    assigns \nothing;
*/
int func(int a, int b, int c, int d, int e)
{
    //@ assert ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    //@ assert a < e;
    return 0;
}

/*@
    requires a < b && b < c;
    ensures \result == 0;
    assigns \nothing;
*/
int func_2(int a, int b, int c)
{
    //@ assert ((a) < (b) && (b) < (c));
    //@ assert a < c;
    return 0;
}

/*@
    requires a < b && b < c && c < d;
    ensures \result == 0;
    assigns \nothing;
*/
int func_3(int a, int b, int c, int d)
{
    //@ assert ((a) < (b) && (b) < (c) && (c) < (d));
    //@ assert a < d;
    return 0;
}

/*@
    requires a < b && b < c && c < d && d < e;
    ensures \result == 0;
    assigns \nothing;
*/
int func_4(int a, int b, int c, int d, int e)
{
    //@ assert ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    //@ assert a < e;
    return 0;
}

/*@
    requires a < b && b < c;
    ensures \result == 0;
    assigns \nothing;
*/
int func_5(int a, int b, int c)
{
    //@ assert ((a) < (b) && (b) < (c));
    //@ assert a < c;
    return 0;
}

int main()
{
    int a, b, c, d, e;
    a = 1; b = 2; c = 3; d = 4; e = 5;
    
    func(a, b, c, d, e);
    func_2(a, b, c);
    func_3(a, b, c, d);
    func_4(a, b, c, d, e);
    func_5(a, b, c);
    
    return 0;
}

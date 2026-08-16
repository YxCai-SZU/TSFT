/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) + 3);
    assigns \nothing;
*/
int func_1(int n)
{
    int result;
    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert ((n) + 3) <= 103;
    result = n + 3;
    return result;
}

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == ((a) + (b) + 3);
    assigns \nothing;
*/
int func_2(int a, int b)
{
    int result;
    //@ assert (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    //@ assert ((a) + (b) + 3) <= 203;
    result = a + b + 3;
    return result;
}

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result == ((a) + (b) + (c) + 3);
    assigns \nothing;
*/
int func_3(int a, int b, int c)
{
    int result;
    //@ assert (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    //@ assert ((a) + (b) + (c) + 3) <= 303;
    result = a + b + c + 3;
    return result;
}

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100) && (1 <= (d) && (d) <= 100);
    ensures \result == ((a) + (b) + (c) + (d) + 3);
    assigns \nothing;
*/
int func_4(int a, int b, int c, int d)
{
    int result;
    //@ assert (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100) && (1 <= (d) && (d) <= 100);
    //@ assert ((a) + (b) + (c) + (d) + 3) <= 403;
    result = a + b + c + d + 3;
    return result;
}

int main()
{
    return 0;
}

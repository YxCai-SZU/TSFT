/*@
    requires (1 <= (a) && (a) <= 10) && (1 <= (b) && (b) <= 10) && (1 <= (c) && (c) <= 10);
    ensures a + b <= 20 && a + c <= 20 && b + c <= 20;
*/
void func_1(int a, int b, int c)
{
    //@ assert (1 <= (a) && (a) <= 10);
}

/*@
    requires (1 <= (a) && (a) <= 10) && (1 <= (b) && (b) <= 10) && (1 <= (c) && (c) <= 10);
    ensures a <= 10 && b <= 10 && c <= 10;
*/
void func_2(int a, int b, int c)
{
    //@ assert (1 <= (a) && (a) <= 10);
}

/*@
    requires (1 <= (a) && (a) <= 10) && (1 <= (b) && (b) <= 10) && (1 <= (c) && (c) <= 10);
    ensures (1 <= (a) && (a) <= 10) && (1 <= (b) && (b) <= 10) && (1 <= (c) && (c) <= 10);
*/
void func_3(int a, int b, int c)
{
    //@ assert (1 <= (a) && (a) <= 10);
}

/*@
    requires (1 <= (a) && (a) <= 10) && (1 <= (b) && (b) <= 10) && (1 <= (c) && (c) <= 10);
    ensures a + b + c <= 30;
*/
void func_4(int a, int b, int c)
{
    //@ assert (1 <= (a) && (a) <= 10);
}

int main(void)
{
    return 0;
}

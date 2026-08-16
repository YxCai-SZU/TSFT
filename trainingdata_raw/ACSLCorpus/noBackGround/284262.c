/*@
    requires x == y;
    requires y < x + 2;
    ensures x <= y + 2;
*/
void func_n(int x, int y)
{
    //@ assert x == y;
    //@ assert y < x + 2;
    //@ assert x <= y + 2;
}

/*@
    requires x == y;
    requires y > x - 3;
    ensures x >= y - 6;
*/
void func_m(int x, int y)
{
    //@ assert x == y;
    //@ assert y > x - 3;
    //@ assert x >= y - 6;
}

/*@
    requires x == y;
    requires y < x + 2;
    requires y > x - 3;
    ensures x <= y + 2;
    ensures x >= y - 6;
*/
void func_k(int x, int y)
{
    func_n(x, y);
    func_m(x, y);
}

/*@
    requires x == y;
    requires y < x + 2;
    requires y > x - 3;
    ensures x <= y + 2;
    ensures x >= y - 6;
*/
void test_20(int x, int y)
{
    func_k(x, y);
}

/*@
    requires x == y;
    requires y < x + 2;
    requires y > x - 3;
    ensures x <= y + 2;
    ensures x >= y - 6;
*/
void func_s(int x, int y)
{
    test_20(x, y);
}

int main()
{
    int x;
    int y;
    return 0;
}

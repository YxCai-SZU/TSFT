/*@
    requires x >= 0 && y >= 0 && x + y <= 100;
    ensures \true;
*/
void test_arith_property(int x, int y)
{
    //@ assert x * 2 <= x * 2 + y * 2;
}

/*@
    ensures \true;
*/
void test_max(int x, int y)
{
    //@ assert (((x) > (y)) ? (x) : (y)) >= x;
    //@ assert (((x) > (y)) ? (x) : (y)) >= y;
    //@ assert (((x) > (y)) ? (x) : (y)) == x || (((x) > (y)) ? (x) : (y)) == y;
}

/*@
    ensures \result == 0;
*/
int main()
{
    int result = 0;
    //@ assert (((5) > (3)) ? (5) : (3)) == 5;
    //@ assert (((2) > (7)) ? (2) : (7)) == 7;
    return result;
}

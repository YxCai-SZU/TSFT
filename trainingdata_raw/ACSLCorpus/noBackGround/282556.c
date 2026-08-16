/*@
    requires 0 <= x && x <= 10;
    requires 0 <= y && y <= 20;
    ensures \result >= 0;
    ensures \result <= 200;
*/
int calc_example_2(int x, int y)
{
    //@ assert ((x) >= 0 && (y) >= 0 ==> (x) * (y) >= 0);
    //@ assert ((x) >= 0 && (x) <= 10 && (y) >= 0 && (y) <= 20 ==> (x) * (y) <= 200);
    return x * y;
}

int main()
{
    return 0;
}

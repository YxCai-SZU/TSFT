/*@
    requires a < b && b < c;
    ensures a < c;
*/
void calc_example_3(int a, int b, int c)
{
    //@ assert a < b;
}

/*@
    requires d <= e && e <= f;
    ensures d <= f;
*/
void calc_example_4(int d, int e, int f)
{
    //@ assert d <= e;
}

/*@
    requires g == h && h == i;
    ensures g == i;
*/
void calc_example_5(int g, int h, int i)
{
    //@ assert g == h;
}

/*@
    requires x < y && y < z && z <= x + 10;
    ensures x < x + 10;
*/
void complex_calc_example(int x, int y, int z)
{
    //@ assert x < y;
}

int main() {
    return 0;
}

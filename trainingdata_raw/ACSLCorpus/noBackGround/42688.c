/*@
    requires ((x) <= 8 && (y) <= 8);
    ensures ((x) * (y) <= 1000);
*/
void bounds_check_nonlinear_arith(unsigned int x, unsigned int y, unsigned int z)
{
    //@ assert x <= 8 && y <= 8;
    //@ assert x * y <= 100;
    //@ assert x * y <= 1000;
}

/*@
    requires ((x) <= 8 && (y) <= 8);
    ensures ((x) * (y) <= 64);
*/
void bounds_check_nonlinear_arith2(unsigned int x, unsigned int y, unsigned int z)
{
    //@ assert x * y <= 64;
}

/*@
    requires ((a) > 0 && (b) > 0);
    ensures ((a) * (b) > 0);
*/
void nonlinear_arith_example(int a, int b)
{
    //@ assert a * b > 0;
}

/*@
    requires ((a) > 0 && (b) > 0);
    ensures ((a) * (b) > 0);
*/
void nonlinear_arith_example2(int a, int b)
{
    //@ assert a * b > 0;
}

/*@
    requires ((a) > 0 && (b) > 0);
    ensures ((a) * (b) > 0);
*/
void nonlinear_arith_example3(int a, int b)
{
    //@ assert a * b > 0;
}

/*@
    requires ((a) > 0 && (b) > 0);
    ensures ((a) * (b) > 0);
*/
void nonlinear_arith_example4(int a, int b)
{
    //@ assert a * b > 0;
}

/*@
    requires ((a) > 0 && (b) > 0);
    ensures ((a) * (b) > 0);
*/
void nonlinear_arith_example5(int a, int b)
{
    //@ assert a * b > 0;
}

int main() {
    return 0;
}

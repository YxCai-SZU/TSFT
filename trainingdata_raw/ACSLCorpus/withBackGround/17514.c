/*@
    predicate bounds(integer a, integer b, integer c) =
        a <= 8 && b <= 8 && c <= 8;

    logic integer product(integer a, integer b, integer c) = a * (b * c);

    lemma mul_assoc: \forall integer a, b, c; a > 0 && b > 0 && c > 0 ==> a * (b * c) == (a * b) * c;
*/

/*@
    requires 0 <= a <= 8;
    requires 0 <= b <= 8;
    requires 0 <= c <= 8;
    ensures \result == a * (b * c);
    ensures \result <= 512;
*/
unsigned int nonlinear_arithmetic_example_8(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert bounds(a, b, c);
    //@ assert b * c <= 64;
    //@ assert a * (b * c) <= 512;
    return a * (b * c);
}

/*@
    requires a > 0 && b > 0 && c > 0;
    ensures a * (b * c) == (a * b) * c;
*/
void nonlinear_arithmetic_example_7(int a, int b, int c)
{
    //@ assert mul_assoc: a * (b * c) == (a * b) * c;
}

int main()
{
    return 0;
}

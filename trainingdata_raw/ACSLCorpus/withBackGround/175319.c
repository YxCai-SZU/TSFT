/*@
    predicate mul_bounded(integer x, integer y) =
        x <= 8 && y <= 8 ==> x * y <= 100;

    lemma mul_commutative:
        \forall integer x, y;
        -100 <= x && x <= 100 && -100 <= y && y <= 100 ==>
        x * y == y * x;

    lemma mul_associative:
        \forall integer x, y, z;
        -100 <= x && x <= 100 && -100 <= y && y <= 100 && -100 <= z && z <= 100 ==>
        (x * y) * z == x * (y * z);
*/

/*@
    requires x <= 8 && y <= 8;
    ensures \result <= 1000;
*/
unsigned int mul_property(unsigned int x, unsigned int y)
{
    //@ assert mul_bounded(x, y);
    //@ assert x * y <= 1000;
    return x * y;
}

int main()
{
    unsigned int a;
    unsigned int b;
    unsigned int result;

    a = 5;
    b = 6;
    result = mul_property(a, b);
    return 0;
}

/*@
    predicate bounds_u32(integer v) = 0 <= v <= 4294967295;

    lemma mul_commutative:
        \forall integer x, y; bounds_u32(x) && bounds_u32(y) ==> x * y == y * x;

    lemma mul_associative:
        \forall integer a, b, c;
            bounds_u32(a) && bounds_u32(b) && bounds_u32(c) &&
            a * b <= 4294967295 && a * b * c <= 4294967295 ==>
            a * (b * c) == (a * b) * c;

    lemma mul_distributive_add:
        \forall integer x, y, z;
            bounds_u32(x) && bounds_u32(y) && bounds_u32(z) &&
            x * (y + z) <= 4294967295 ==>
            x * (y + z) == x * y + x * z;
*/

/*@
    requires 0 <= x && 0 <= y;
    ensures x * y == y * x;
*/
void verify_mul_is_commutative(unsigned int x, unsigned int y)
{
    //@ assert x * y == y * x;
}

/*@
    requires 0 <= a && 0 <= b && 0 <= c;
    requires a * b <= 4294967295 && a * b * c <= 4294967295;
    ensures a * (b * c) == (a * b) * c;
*/
void verify_mul_is_associative(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert a * (b * c) == (a * b) * c;
}

/*@
    requires 0 <= x && 0 <= y && 0 <= z;
    requires x * (y + z) <= 4294967295;
    ensures x * (y + z) == x * y + x * z;
*/
void verify_mul_is_distributive_add(unsigned int x, unsigned int y, unsigned int z)
{
    //@ assert x * (y + z) == x * y + x * z;
}

/*@
    predicate bounds_8(integer v) = 0 <= v <= 8;

    lemma mul_bounds_64:
        \forall integer a, b;
            bounds_8(a) && bounds_8(b) ==> 0 <= a * b <= 64;

    lemma mul_bounds_512:
        \forall integer a, b, c;
            bounds_8(a) && bounds_8(b) && bounds_8(c) ==> 0 <= a * b * c <= 512;
*/

/*@
    requires 0 <= a <= 8;
    requires 0 <= b <= 8;
    requires 0 <= c <= 8;
    ensures \result == a * b * c;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert bounds_8(a);
    //@ assert bounds_8(b);
    //@ assert bounds_8(c);
    
    //@ assert 0 <= a * b <= 64;
    //@ assert 0 <= a * b * c <= 512;
    
    return a * b * c;
}

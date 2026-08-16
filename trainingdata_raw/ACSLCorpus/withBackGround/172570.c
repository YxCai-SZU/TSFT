/*@
    predicate is_valid_u8(integer x) = 0 <= x < 256;

    logic integer double_val(integer x) = 2 * x;

    logic integer square_val(integer x) = x * x;

    lemma square_bounds: \forall integer x; 0 <= x < 8 ==> square_val(x) < 64;
*/

/*@
    requires 0 <= x < 64;
    ensures \result == double_val(x);
    ensures is_valid_u8(\result);
*/
unsigned char func(unsigned char x)
{
    unsigned char res;
    //@ assert 0 <= x < 64;
    res = 2 * x;
    //@ assert res == double_val(x);
    return res;
}

/*@
    requires 0 <= x < 8;
    ensures \result == square_val(x);
    ensures is_valid_u8(\result);
*/
unsigned char square(unsigned char x)
{
    unsigned char res;
    //@ assert 0 <= x < 8;
    //@ assert square_val(x) < 64;
    res = x * x;
    //@ assert res == square_val(x);
    return res;
}

/*@
    requires is_valid_u8(a) && is_valid_u8(b);
    ensures \result == a || \result == b;
    ensures \result >= a && \result >= b;
    ensures is_valid_u8(\result);
*/
unsigned char max(unsigned char a, unsigned char b)
{
    unsigned char res;
    if (a > b) {
        //@ assert a >= a && a >= b;
        res = a;
    } else {
        //@ assert b >= a && b >= b;
        res = b;
    }
    //@ assert res == a || res == b;
    return res;
}

int main()
{
    return 0;
}

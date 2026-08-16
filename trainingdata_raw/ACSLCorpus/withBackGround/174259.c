/*@
    predicate call_requires_multiply_by_x(integer x, integer factor) =
        x * factor < 4294967295;

    predicate call_ensures_multiply_by_x(integer x, integer factor, integer result) =
        result == x * factor;

    lemma call_ensures_implies_multiplication:
        \forall integer x, integer factor, integer result;
            call_ensures_multiply_by_x(x, factor, result) ==> result == x * factor;
*/

/*@
    requires call_requires_multiply_by_x(x, factor);
    ensures \result == x * factor;
    assigns \nothing;
*/
unsigned int multiply_by_x(unsigned int x, unsigned int factor)
{
    unsigned int res;
    res = x * factor;
    //@ assert res == x * factor;
    return res;
}

/*@
    requires call_requires_multiply_by_x(val, factor);
    requires \forall integer x, integer y, integer result;
        call_ensures_multiply_by_x(x, y, result) ==> result == x * y;
    ensures \result == val * factor;
    assigns \nothing;
*/
unsigned int apply_multiplication_factor(unsigned int val, unsigned int factor)
{
    unsigned int res;
    res = multiply_by_x(val, factor);
    //@ assert res == val * factor;
    return res;
}

int main()
{
    unsigned int a;
    unsigned int b;
    unsigned int result;
    
    a = 5;
    b = 2;
    result = apply_multiplication_factor(a, b);
    //@ assert result == a * b;
    
    return 0;
}

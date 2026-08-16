/*@
predicate positive(integer x) = x > 0;

lemma non_linear_arith_example:
    \forall integer a, b, c;
        positive(a) && positive(b) && positive(c) ==>
        a * b * c == b * c * a;

lemma non_linear_arith_example6:
    \forall integer a, b, c;
        0 <= a <= 100 && 0 <= b <= 100 && 0 <= c <= 100 ==>
        (a + b + c) * (a + b + c) == 
        a * a + b * b + c * c + 2 * (a * b + a * c + b * c);
*/

/*@
    requires 0 <= a <= 100 && 0 <= b <= 100 && 0 <= c <= 100;
    ensures \result == (a + b + c) * (a + b + c);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int sum;
    int result;

    sum = a + b + c;
    //@ assert sum == a + b + c;
    result = sum * sum;
    //@ assert result == sum * sum;
    //@ assert result == (a + b + c) * (a + b + c);
    return result;
}

int main()
{
    return 0;
}

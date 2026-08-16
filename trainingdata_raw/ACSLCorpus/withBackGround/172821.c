/*@
    predicate non_negative(integer x) = x >= 0;

    lemma distribution_lemma:
        \forall integer a, b, c;
            non_negative(a) && non_negative(b) && non_negative(c) ==>
            a * (b + c) == a * b + a * c;
*/

/*@
    requires non_negative(a) && non_negative(b) && non_negative(c);
    ensures \result == a * b + a * c;
    assigns \nothing;
*/
int calc_example_7(int a, int b, int c)
{
    int result;
    //@ assert a * (b + c) == a * b + a * c;
    result = a * b + a * c;
    return result;
}

int main()
{
    int a = 2;
    int b = 3;
    int c = 4;
    int res = calc_example_7(a, b, c);
    return 0;
}

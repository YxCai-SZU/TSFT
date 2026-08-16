/*@
    predicate multiplication_is_distributive(integer a, integer b, integer c) =
        a <= 2147483647 && b <= 2147483647 && c <= 2147483647 ==>
        a * (b + c) == a * b + a * c;

    predicate addition_is_commutative(integer a, integer b) =
        a <= 2147483647 && b <= 2147483647 ==>
        a + b == b + a;

    predicate addition_is_associative(integer a, integer b, integer c) =
        a <= 2147483647 && b <= 2147483647 && c <= 2147483647 ==>
        (a + b) + c == a + (b + c);

    lemma multiplication_distributive_lemma:
        \forall integer a, b, c;
            multiplication_is_distributive(a, b, c);

    lemma addition_commutative_lemma:
        \forall integer a, b;
            addition_is_commutative(a, b);

    lemma addition_associative_lemma:
        \forall integer a, b, c;
            addition_is_associative(a, b, c);
*/

/*@
    requires a <= 2147483647 && b <= 2147483647 && c <= 2147483647;
    ensures \result == a * b + a * c;
    assigns \nothing;
*/
int distributive_multiplication(int a, int b, int c)
{
    int tmp1;
    int tmp2;
    int result;

    tmp1 = b + c;
    //@ assert tmp1 == b + c;
    tmp2 = a * tmp1;
    //@ assert tmp2 == a * (b + c);
    result = a * b + a * c;
    //@ assert result == a * b + a * c;
    //@ assert tmp2 == result;
    return result;
}

/*@
    requires a <= 2147483647 && b <= 2147483647;
    ensures \result == b + a;
    assigns \nothing;
*/
int commutative_addition(int a, int b)
{
    int tmp1;
    int tmp2;
    int result;

    tmp1 = a + b;
    //@ assert tmp1 == a + b;
    tmp2 = b + a;
    //@ assert tmp2 == b + a;
    result = tmp2;
    //@ assert tmp1 == result;
    return result;
}

/*@
    requires a <= 2147483647 && b <= 2147483647 && c <= 2147483647;
    ensures \result == a + (b + c);
    assigns \nothing;
*/
int associative_addition(int a, int b, int c)
{
    int tmp1;
    int tmp2;
    int result;

    tmp1 = a + b;
    //@ assert tmp1 == a + b;
    tmp2 = tmp1 + c;
    //@ assert tmp2 == (a + b) + c;
    result = a + (b + c);
    //@ assert result == a + (b + c);
    //@ assert tmp2 == result;
    return result;
}

int main()
{
    return 0;
}

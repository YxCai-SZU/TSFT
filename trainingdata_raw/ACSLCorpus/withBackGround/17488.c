/*@
predicate eq_int(integer a, integer b) = a == b;

lemma axiom_equality: \forall integer n; eq_int(n, n);
lemma axiom_addition: \forall integer a, b; eq_int(a + b, b + a);
lemma axiom_multiplication: \forall integer a, b; eq_int(a * b, b * a);
*/

/*@
requires n == 10;
ensures \result == 20;
assigns \nothing;
*/
int calc_example_5(int n)
{
    //@ assert eq_int(n, 10);
    int result;
    result = n * 2;
    //@ assert eq_int(result, 20);
    return result;
}

int main()
{
    return 0;
}

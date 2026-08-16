/*@
predicate is_in_range(integer x) = 2 <= x && x <= 100;

lemma additive_assoc: \forall integer a, b, c; (a + b) + c == a + (b + c);
lemma additive_commut: \forall integer a, b; a + b == b + a;
lemma example_lemma: \forall integer x; is_in_range(x) ==> is_in_range(x);
*/

/*@
requires is_in_range(x);
ensures is_in_range(x);
*/
void lemma_example(int x)
{
    //@ assert is_in_range(x);
}

int main()
{
    return 0;
}

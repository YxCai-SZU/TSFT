/*@
predicate x_is_x_or_greater(integer x) = x <= x && x <= x + 3;

predicate x_plus_three_is_x_or_greater(integer x) = x + 3 <= x + 3;

lemma lemma_x_is_x_or_greater:
    \forall integer x; x_is_x_or_greater(x);

lemma lemma_x_plus_three_is_x_or_greater:
    \forall integer x; x_plus_three_is_x_or_greater(x);
*/

/*@
requires x >= 0;
ensures x <= x + 5;
*/
void calc_example_4(int x)
{
    //@ assert x_is_x_or_greater(x);
    //@ assert x_plus_three_is_x_or_greater(x);
    //@ assert x <= x + 5;
}

int main()
{
    return 0;
}

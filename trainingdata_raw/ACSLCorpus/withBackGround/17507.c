/*@
predicate eq_int(integer a, integer b) = a == b;
predicate lt_int(integer a, integer b) = a < b;
predicate le_int(integer a, integer b) = a <= b;

lemma multiple_intermediate_relations:
    \forall integer a, b;
    eq_int(a, b) && lt_int(b, a + 2) ==> le_int(a, b + 1 * 2);

lemma different_intermediate_relations:
    \forall integer a, b;
    eq_int(a, b) && lt_int(b, a + 2) ==> le_int(a, b + 1 * 2);

lemma final_example:
    \forall integer a, b;
    eq_int(a, b) && lt_int(b, a + 2) ==> le_int(a, b + 1 * 2);
*/

int main()
{
    return 0;
}

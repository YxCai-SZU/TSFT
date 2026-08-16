/*@
logic integer min(integer a, integer b) = (a < b) ? a : b;
logic integer max(integer a, integer b) = (a > b) ? a : b;

predicate min_is_a_or_b(integer a, integer b) =
    min(a, b) == a || min(a, b) == b;

predicate max_is_a_or_b(integer a, integer b) =
    max(a, b) == a || max(a, b) == b;

predicate min_le_max(integer a, integer b) =
    min(a, b) <= max(a, b);

logic integer spec_divmod_quot(integer x, integer y) = x / y;
logic integer spec_divmod_rem(integer x, integer y) = x % y;

lemma div_mod_example_2: \forall integer a, b; b > 0 ==> spec_divmod_rem(a, b) == a % b;

lemma min_max_lemma: \forall integer a, b; min(a, b) <= max(a, b);

lemma min_lemma: \forall integer a, b; min(a, b) == a || min(a, b) == b;

lemma max_lemma: \forall integer a, b; max(a, b) == a || max(a, b) == b;
*/

int main()
{
    return 0;
}

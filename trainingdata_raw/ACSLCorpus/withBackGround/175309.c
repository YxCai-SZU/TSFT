/*@
predicate is_greater_than_threshold(integer x, integer threshold) = x > threshold;

lemma establish_exists_greater_than_threshold:
    \forall integer threshold;
    (\exists integer x; is_greater_than_threshold(x, threshold)) ==>
    (\exists integer x; is_greater_than_threshold(x, threshold));
*/

int main()
{
    return 0;
}

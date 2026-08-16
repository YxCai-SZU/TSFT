/*@
predicate seqs_match_in_range_helper{L}(integer start, integer end) =
    \forall integer i; start <= i < end ==> \true;

lemma seqs_match_in_range_helper_lemma:
    \forall integer start, integer end;
    seqs_match_in_range_helper(start, end) ==>
    seqs_match_in_range_helper(start, end);
*/

int main() {
    //@ assert \true;
    return 0;
}

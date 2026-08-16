/*@
    predicate less_than_three(integer n) = n < 3;
    predicate less_than_five(integer n) = n < 5;
    logic integer plus_one(integer x) = x + 1;
    logic integer plus_three(integer n) = n + 3;
*/

/*@ lemma calc_example_t: \forall integer x; less_than_five(x) ==> plus_one(x) <= 6; */

/*@ lemma less_than_three_steps: \forall integer n; less_than_three(n) ==> plus_three(n) <= 6; */

int main() {
    //@ assert \true;
    return 0;
}

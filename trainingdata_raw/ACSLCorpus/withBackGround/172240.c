/*@
predicate eq_int(integer a, integer b) = a == b;
predicate le_int(integer a, integer b) = a <= b;
*/

/*@
lemma calc_example_8:
    \forall integer a, b, c;
        eq_int(a, b) && le_int(b, c) ==> le_int(a, c);
*/

int main() {
    //@ assert \true;
    return 0;
}

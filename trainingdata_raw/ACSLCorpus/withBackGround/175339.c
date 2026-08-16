/*@
predicate example_7_post(integer a) = a == a + 2 - 1 - 1;
predicate example_8_post(integer a) = a == a + 3 - 2 - 1;
predicate example_9_post(integer a) = a == a + 4 - 3 - 1;

lemma calc_example_7: \forall integer a; example_7_post(a);
lemma calc_example_8: \forall integer a; example_8_post(a);
lemma calc_example_9: \forall integer a; example_9_post(a);
*/

/*@
requires \true;
assigns \nothing;
ensures \true;
*/
int main() {
    int a;
    
    //@ assert example_7_post(a);
    //@ assert example_8_post(a);
    //@ assert example_9_post(a);
    
    return 0;
}

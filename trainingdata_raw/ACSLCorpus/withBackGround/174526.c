/*@
predicate add_commutativity_prop(integer a, integer b) =
    a + b == b + a;

predicate add_associativity_prop(integer a, integer b, integer c) =
    (a + b) + c == a + (b + c);

lemma add_commutativity_lemma:
    \forall integer a, b; add_commutativity_prop(a, b);

lemma add_associativity_lemma:
    \forall integer a, b, c; add_associativity_prop(a, b, c);
*/

/*@
requires \true;
ensures \true;
*/
int main() {
    int a;
    int b;
    int c;
    
    //@ assert add_commutativity_prop(0, 0);
    //@ assert add_associativity_prop(0, 0, 0);
    
    return 0;
}

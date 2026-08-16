/*@
predicate positive(integer x) = x > 0;

lemma non_linear_arith_example7:
  \forall integer a, b, c;
    positive(a) && positive(b) && positive(c) ==>
    a * b * c == b * c * a;

lemma lemma_commute_add_mul:
  \forall integer a, b, c;
    positive(a) && positive(b) && positive(c) ==>
    (a + b) * c == a * c + b * c;

lemma lemma_commute_add:
  \forall integer a, b, c;
    positive(a) && positive(b) && positive(c) ==>
    a + b == b + a;

lemma lemma_commute_mul:
  \forall integer a, b, c;
    positive(a) && positive(b) && positive(c) ==>
    a * b == b * a;

lemma lemma_commute_mul_assoc:
  \forall integer a, b, c;
    positive(a) && positive(b) && positive(c) ==>
    (a * b) * c == a * (b * c);

lemma lemma_commute_add_assoc:
  \forall integer a, b, c;
    positive(a) && positive(b) && positive(c) ==>
    (a + b) + c == a + (b + c);

lemma lemma_commute_mul_distributive:
  \forall integer a, b, c;
    positive(a) && positive(b) && positive(c) ==>
    a * (b + c) == a * b + a * c;

lemma lemma_commute_mul_distributive_rev:
  \forall integer a, b, c;
    positive(a) && positive(b) && positive(c) ==>
    a * b + a * c == a * (b + c);
*/

int main() {
    int a;
    int b;
    int c;
    
    a = 1;
    b = 2;
    c = 3;
    
    //@ assert positive(a);
    //@ assert positive(b);
    //@ assert positive(c);
    
    //@ assert a * b * c == b * c * a;
    //@ assert (a + b) * c == a * c + b * c;
    //@ assert a + b == b + a;
    //@ assert a * b == b * a;
    //@ assert (a * b) * c == a * (b * c);
    //@ assert (a + b) + c == a + (b + c);
    //@ assert a * (b + c) == a * b + a * c;
    //@ assert a * b + a * c == a * (b + c);
    
    return 0;
}

/*@
predicate positive(integer v) = v > 0;
predicate bounded(integer v) = v <= 8;

lemma commutative_mult:
  \forall integer x, y; positive(x) && positive(y) ==> x * y == y * x;

lemma associative_mult:
  \forall integer x, y, z; positive(x) && positive(y) && positive(z) ==> x * (y * z) == (x * y) * z;

lemma distributive_mult:
  \forall integer x, y, z; positive(x) && positive(y) && positive(z) ==> x * (y + z) == x * y + x * z;

lemma upper_bound:
  \forall integer x, y; 0 <= x && x <= 8 && 0 <= y && y <= 8 ==> x * y <= 64;
*/

/*@
  requires x > 0 && y > 0;
  ensures \result == 1;
  assigns \nothing;
*/
int verify_nonlinear_arith_facts(int x, int y) {
    //@ assert positive(x);
    return 1;
}

/*@
  requires 0 <= x && x <= 8 && 0 <= y && y <= 8;
  ensures \result == 1;
  assigns \nothing;
*/
int verify_upper_bound(int x, int y) {
    //@ assert bounded(x);
    return 1;
}

/*@
  assigns \nothing;
*/
int main() {
    int x;
    int y;
    int a;
    int b;
    
    x = 5;
    y = 3;
    //@ assert x > 0 && y > 0;
    verify_nonlinear_arith_facts(x, y);
    
    a = 6;
    b = 7;
    //@ assert 0 <= a && a <= 8 && 0 <= b && b <= 8;
    verify_upper_bound(a, b);
    
    return 0;
}

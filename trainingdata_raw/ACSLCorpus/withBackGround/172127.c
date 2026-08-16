/*@
predicate positive(integer x) = x > 0;

lemma trichotomy: \forall integer a, b, c;
    positive(a) && positive(b) && positive(c) ==>
    a*a > b*b + c*c || a*a == b*b + c*c || a*a < b*b + c*c;
*/

/*@
requires positive(a) && positive(b) && positive(c);
ensures \result == 0;
assigns \nothing;
*/
int func(int a, int b, int c) {
    //@ assert a*a > b*b + c*c || a*a == b*b + c*c || a*a < b*b + c*c;
    return 0;
}

/*@
requires positive(a) && positive(b) && positive(c);
ensures \result == 0;
assigns \nothing;
*/
int func2(int a, int b, int c) {
    //@ assert a*a > b*b + c*c || a*a == b*b + c*c || a*a < b*b + c*c;
    return 0;
}

int main() {
    int a = 1;
    int b = 1;
    int c = 1;
    //@ assert positive(a) && positive(b) && positive(c);
    func(a, b, c);
    func2(a, b, c);
    return 0;
}

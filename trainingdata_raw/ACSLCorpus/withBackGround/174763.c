/*@
    predicate positive(integer x) = x > 0;
    predicate no_overflow(integer l, integer w, integer h) = 
        l * w * h < 2147483647;
    
    lemma intermediate_bound: 
        \forall integer l, w, h; 
        positive(l) && positive(w) && positive(h) && no_overflow(l, w, h) ==> 
        l * w < 2147483647;
*/

/*@
    requires positive(l) && positive(w) && positive(h) && no_overflow(l, w, h);
    ensures \result == l * w * h;
    assigns \nothing;
*/
int cuboid_volume(int l, int w, int h) {
    // Variable declarations at scope top
    int volume;
    
    //@ assert positive(l) && positive(w) && positive(h);
    //@ assert no_overflow(l, w, h);
    //@ assert l * w < 2147483647;
    
    volume = l * w * h;
    //@ assert volume == l * w * h;
    return volume;
}

int main() {
    return 0;
}

/*@
    predicate positive(integer x) = x > 0;
    predicate bounded(integer x) = x <= 1000;
    predicate non_overflow_prism(integer l, integer w, integer h) = 
        l * w <= 1000 * 1000 && l * w * h <= 1000 * 1000 * 1000;
    predicate non_overflow_cube(integer s) = 
        s * s <= 1000 * 1000 && s * s * s <= 1000 * 1000 * 1000;
    logic integer volume_prism(integer l, integer w, integer h) = l * w * h;
    logic integer volume_cube_logic(integer s) = s * s * s;
    lemma prism_overflow_lemma: 
        \forall integer l, w, h; 
        positive(l) && positive(w) && positive(h) && 
        bounded(l) && bounded(w) && bounded(h) ==> 
        non_overflow_prism(l, w, h);
    lemma cube_overflow_lemma: 
        \forall integer s; 
        positive(s) && bounded(s) ==> 
        non_overflow_cube(s);
*/

/*@
    requires positive(l) && positive(w) && positive(h);
    requires bounded(l) && bounded(w) && bounded(h);
    ensures \result == volume_prism(l, w, h);
    assigns \nothing;
*/
int volume_rect_prism(int l, int w, int h) {
    //@ assert positive(l) && positive(w) && positive(h);
    //@ assert bounded(l) && bounded(w) && bounded(h);
    //@ assert non_overflow_prism(l, w, h);
    return l * w * h;
}

/*@
    requires positive(s) && bounded(s);
    ensures \result == volume_cube_logic(s);
    assigns \nothing;
*/
int volume_cube(int s) {
    //@ assert positive(s);
    //@ assert bounded(s);
    //@ assert non_overflow_cube(s);
    return s * s * s;
}

int main() {
    int vprism;
    int vcube;
    
    vprism = volume_rect_prism(2, 3, 4);
    //@ assert vprism == 24;
    
    vcube = volume_cube(5);
    //@ assert vcube == 125;
    
    return 0;
}

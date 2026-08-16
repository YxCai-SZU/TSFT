/*@
    predicate valid_input(integer base, integer height) =
        base >= 0 && height >= 0 && base <= 100 && height <= 100;
    
    predicate area_bound(integer base, integer height) =
        base * height / 2 <= 5000;
    
    lemma product_bound:
        \forall integer base, height;
        valid_input(base, height) ==> base * height <= 10000;
    
    lemma division_bound:
        \forall integer base, height;
        valid_input(base, height) && base * height <= 10000 ==> 
        base * height / 2 <= 5000;
*/

/*@
    requires valid_input(base, height);
    ensures area_bound(base, height);
*/
void triangle_area_example(int base, int height) {
    // Variable declarations at the top
    int product;
    int half_area;
    
    //@ assert base >= 0 && height >= 0;
    //@ assert base <= 100 && height <= 100;
    
    product = base * height;
    //@ assert product <= 10000;
    
    half_area = product / 2;
    //@ assert half_area <= 5000;
}

int main() {
    return 0;
}

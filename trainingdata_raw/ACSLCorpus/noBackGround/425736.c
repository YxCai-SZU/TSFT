/*@
    requires 1 <= l && l <= 6;
    requires 1 <= r && r <= 6;
    ensures \result <= 36;
    assigns \nothing;
*/
unsigned int lemma_nums(unsigned int l, unsigned int r) {
    // Variable declarations at scope top
    unsigned int product;

    //@ assert (1 <= (l) && (l) <= 6);
    //@ assert (1 <= (r) && (r) <= 6);
    
    product = l * r;
    
    //@ assert product <= 36;
    return product;
}

int main() {
    return 0;
}

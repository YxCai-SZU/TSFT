/*@
    predicate is_nonzero(integer x) = x != 0;
*/

/*@
    lemma and_inequality:
        \forall integer x, y;
            (x & y) == 1 && is_nonzero(x & 0xffffffff) ==>
            is_nonzero(x & 0xffffffff);
*/

int main() {
    unsigned int x;
    unsigned int y;
    
    //@ assert \true;
    
    return 0;
}

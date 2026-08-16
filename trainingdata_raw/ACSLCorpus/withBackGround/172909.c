/*@
    predicate f1(integer x, integer y) = x < y;
    predicate f2(integer x, integer y) = x == y;
    predicate f3(integer x, integer y) = x > y;
*/

/*@
    requires \valid_function(f);
    assigns \nothing;
    ensures \result == 1;
*/
int higher_order_relation(unsigned int x, unsigned int y, int (*f)(unsigned int, unsigned int)) {
    //@ assert \true;
    return 1;
}

/*@
    requires x < y;
    assigns \nothing;
    ensures \result == 1;
*/
int is_smaller(unsigned int x, unsigned int y) {
    //@ assert x < y;
    return 1;
}

/*@
    requires x == y;
    assigns \nothing;
    ensures \result == 1;
*/
int is_equal(unsigned int x, unsigned int y) {
    //@ assert x == y;
    return 1;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}

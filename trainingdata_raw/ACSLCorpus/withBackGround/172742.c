/*@
    predicate is_possible_x_cats(integer a, integer b, integer x) =
        x >= a && x <= b;
*/

/*@
    requires 0 <= a && a <= b && b <= 100;
    requires 0 <= x && x <= b;
    ensures \result <==> (x >= a && x <= b);
*/
int is_possible_x_cats(int a, int b, int x) {
    //@ assert x >= a && x <= b <==> (x >= a && x <= b);
    return x >= a && x <= b;
}

int main() {
    return 0;
}

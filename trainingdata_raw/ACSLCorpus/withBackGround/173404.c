/*@
    predicate is_valid_range(integer r) = 1 <= r && r <= 100;
    logic integer square(integer r) = r * r;
    lemma square_bounds: \forall integer r; is_valid_range(r) ==> 1 <= square(r) && square(r) <= 10000;
*/

/*@
    requires is_valid_range(r);
    ensures \result == square(r);
    assigns \nothing;
*/
int func(int r) {
    int result;
    //@ assert is_valid_range(r);
    result = r;
    if (r != 0) {
        //@ assert is_valid_range(r);
        //@ assert 1 <= square(r) && square(r) <= 10000;
        result = r * r;
    }
    //@ assert result == square(r);
    return result;
}

int main() {
    int r = 5;
    //@ assert is_valid_range(r);
    int result = func(r);
    //@ assert result == 25;
    return 0;
}

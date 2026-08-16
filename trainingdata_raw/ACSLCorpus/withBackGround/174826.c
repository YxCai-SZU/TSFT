/*@
    predicate is_valid_input(integer s) = 1 <= s && s <= 9;
    predicate matches_special(integer s) = s == 5 || s == 3 || s == 7;
*/

/*@
    requires is_valid_input(s);
    ensures \result == 1 <==> matches_special(s);
    assigns \nothing;
*/
int func(int s) {
    //@ assert is_valid_input(s);
    return (s == 5) || (s == 3) || (s == 7);
}

/*@
    requires (1 <= (x) && (x) <= 9);
    ensures \result == 1 ==> ((x) == 7 || (x) == 5 || (x) == 3);
    ensures \result == 1 ==> ((x) != 2);
    assigns \nothing;
*/
int func(int x) {
    int result;
    //@ assert (1 <= (x) && (x) <= 9);
    result = (x == 7 || x == 5 || x == 3);
    return result;
}

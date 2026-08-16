/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == (a * 3 <= b);
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b) {
    // Variable declarations at the top
    int result;

    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1 <= (((a)) * 3) && (((a)) * 3) <= 300);

    result = (a * 3 <= b);
    return result;
}

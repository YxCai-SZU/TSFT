/*@
    requires (1 <= (s) <= 100) && (1 <= (w) <= 100);
    ensures \result == (s <= w);
    assigns \nothing;
*/
int func(unsigned int s, unsigned int w) {
    int res;
    //@ assert (1 <= (s) <= 100);
    //@ assert (1 <= (w) <= 100);
    res = (s <= w);
    //@ assert ((res) == ((s) <= (w)));
    return res;
}

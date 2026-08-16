/*@
    requires \valid_read(lst + (0 .. len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result == len;
    ensures \result < 0x80000000;
*/
unsigned int count(const int *lst, unsigned int len) {
    unsigned int count = 0;
    unsigned int i = 0;

    /*@
        loop invariant i <= len;
        loop invariant count == i;
        loop invariant len < 0x80000000;
        loop invariant count < 0x80000000;
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert count == i;
        count += 1;
        i += 1;
        //@ assert count == i;
    }

    //@ assert count == len;
    return count;
}

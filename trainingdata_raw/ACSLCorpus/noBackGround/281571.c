/*@
    requires \valid(list_data + (0 .. len-1));
    requires (0 <= (len) < 0x80000000);
    ensures \result >= 0;
    ensures \result == len;
*/
int count_values(int *list_data, int len) {
    int count = 0;
    int i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant count == i;
        loop invariant count >= 0;
        loop invariant count <= i;
        loop invariant (0 <= (len) < 0x80000000);
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        count += 1;
        i += 1;
    }

    //@ assert i == len;
    //@ assert count == len;
    return count;
}

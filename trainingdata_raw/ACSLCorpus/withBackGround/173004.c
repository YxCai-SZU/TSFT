/*@
    predicate exists_positive(int *list, integer len) =
        \exists integer i; 0 <= i < len && list[i] > 0;
*/

/*@
    requires \valid(list1+(0..len-1));
    requires len >= 0;
    ensures \result == 1 <==> exists_positive(list1, len);
*/
int check_positive(int *list1, int len) {
    int i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> list1[j] <= 0;
        loop assigns i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (list1[i] > 0) {
            return 1;
        }
        i = i + 1;
    }
    return 0;
}

/*@
    predicate exists_odd(int *list, integer len) =
        \exists integer i; 0 <= i < len && (list[i] & 1) != 0;

    lemma odd_exists_implies_true:
        \forall int *list, integer len, integer i;
            0 <= i < len && (list[i] & 1) != 0 ==> exists_odd(list, len);
    lemma no_odd_implies_false:
        \forall int *list, integer len;
            (\forall integer j; 0 <= j < len ==> (list[j] & 1) == 0) ==> !exists_odd(list, len);
*/

/*@
    requires \valid(list1 + (0..len-1));
    requires len >= 0;
    assigns \nothing;
    ensures \result == 1 <==> exists_odd(list1, len);
    ensures \result == 0 <==> !exists_odd(list1, len);
*/
int find_odd(int *list1, int len) {
    int i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> (list1[j] & 1) == 0;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if ((list1[i] & 1) != 0) {
            //@ assert exists_odd(list1, len);
            return 1;
        }
        //@ assert (list1[i] & 1) == 0;
        i++;
    }
    //@ assert \forall integer j; 0 <= j < len ==> (list1[j] & 1) == 0;
    //@ assert !exists_odd(list1, len);
    return 0;
}

/*@
    predicate seq_eq{L1,L2}(int *s1, int *s2, integer len) =
        \forall integer i; 0 <= i < len ==> \at(s1[i],L1) == \at(s2[i],L2);
*/

/*@
    lemma ext_equal_tuple{L1,L2}:
        \forall int *s1, int *s2, integer len;
            len >= 2 && seq_eq{L1,L2}(s1, s2, len) ==>
                (\at(s1[0],L1) == \at(s2[0],L2)) && 
                (\at(s1[1],L1) == \at(s2[1],L2));
*/

int main() {
    return 0;
}

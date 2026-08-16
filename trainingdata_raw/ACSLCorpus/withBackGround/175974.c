#include <stdbool.h>

/*@ predicate is_equal_seq(int *s1, int *s2, integer len) =
      \forall integer i; 0 <= i < len ==> s1[i] == s2[i];
*/

/*@ predicate is_equal_set(int *s1, int *s2, integer len) =
      \forall integer i; 0 <= i < len ==> s1[i] == s2[i];
*/

/*@ lemma struct_equality:
      \forall int x1, int y1, int *seq1, int *seq2, int *set1, int *set2, integer len;
      x1 == x1 && y1 == y1 && 
      is_equal_seq(seq1, seq2, len) && 
      is_equal_set(set1, set2, len) ==> 
      \true;
*/

struct MyStruct {
    int x;
    int y;
    int *seq;
    int *set;
    int len;
};

/*@ requires s1->x == s2->x;
    requires s1->y == s2->y;
    requires s1->len == s2->len;
    requires \valid(s1->seq + (0 .. s1->len-1));
    requires \valid(s2->seq + (0 .. s2->len-1));
    requires \valid(s1->set + (0 .. s1->len-1));
    requires \valid(s2->set + (0 .. s2->len-1));
    requires is_equal_seq(s1->seq, s2->seq, s1->len);
    requires is_equal_set(s1->set, s2->set, s1->len);
    ensures \result == true;
*/
bool are_equal(struct MyStruct *s1, struct MyStruct *s2) {
    //@ assert s1->x == s2->x;
    //@ assert s1->y == s2->y;
    //@ assert s1->len == s2->len;
    //@ assert is_equal_seq(s1->seq, s2->seq, s1->len);
    //@ assert is_equal_set(s1->set, s2->set, s1->len);
    return true;
}

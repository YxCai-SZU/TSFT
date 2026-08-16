struct SeqSet {
    int *seq;
    int *set;
    int length;
};

/*@
    requires \valid(ss1.seq + (0 .. ss1.length-1));
    requires \valid(ss1.set + (0 .. ss1.length-1));
    requires \valid(ss2.seq + (0 .. ss2.length-1));
    requires \valid(ss2.set + (0 .. ss2.length-1));
    requires ss1.length == ss2.length;
    requires (\forall integer i; 0 <= i < (ss1.length) ==> \at((ss1.seq)[i], Here) == \at((ss2.seq)[i], Here));
    requires ((\forall integer i; 0 <= i < (ss1.length) ==> 
            (\exists integer j; 0 <= j < (ss1.length) && \at((ss1.set)[i], Here) == \at((ss2.set)[j], Here))) &&
        (\forall integer i; 0 <= i < (ss1.length) ==> 
            (\exists integer j; 0 <= j < (ss1.length) && \at((ss2.set)[i], Here) == \at((ss1.set)[j], Here))));
    ensures (\forall integer i; 0 <= i < (ss1.length) ==> \at((ss1.seq)[i], Here) == \at((ss2.seq)[i], Here));
    ensures ((\forall integer i; 0 <= i < (ss1.length) ==> 
            (\exists integer j; 0 <= j < (ss1.length) && \at((ss1.set)[i], Here) == \at((ss2.set)[j], Here))) &&
        (\forall integer i; 0 <= i < (ss1.length) ==> 
            (\exists integer j; 0 <= j < (ss1.length) && \at((ss2.set)[i], Here) == \at((ss1.set)[j], Here))));
*/
void compare_seq_set(struct SeqSet ss1, struct SeqSet ss2) {
    //@ assert (\forall integer i; 0 <= i < (ss1.length) ==> \at((ss1.seq)[i], Here) == \at((ss2.seq)[i], Here));
}

/*@
    requires \valid(s1 + (0 .. len-1));
    requires \valid(s2 + (0 .. len-1));
    requires (\forall integer i; 0 <= i < (len) ==> \at((s1)[i], Here) == \at((s2)[i], Here));
    ensures (\forall integer i; 0 <= i < (len) ==> \at((s1)[i], Here) == \at((s2)[i], Here));
*/
void ext_equal_seq(int *s1, int *s2, int len) {
    //@ assert (\forall integer i; 0 <= i < (len) ==> \at((s1)[i], Here) == \at((s2)[i], Here));
}

/*@
    requires \valid(s1 + (0 .. len-1));
    requires \valid(s2 + (0 .. len-1));
    requires ((\forall integer i; 0 <= i < (len) ==> 
            (\exists integer j; 0 <= j < (len) && \at((s1)[i], Here) == \at((s2)[j], Here))) &&
        (\forall integer i; 0 <= i < (len) ==> 
            (\exists integer j; 0 <= j < (len) && \at((s2)[i], Here) == \at((s1)[j], Here))));
    ensures ((\forall integer i; 0 <= i < (len) ==> 
            (\exists integer j; 0 <= j < (len) && \at((s1)[i], Here) == \at((s2)[j], Here))) &&
        (\forall integer i; 0 <= i < (len) ==> 
            (\exists integer j; 0 <= j < (len) && \at((s2)[i], Here) == \at((s1)[j], Here))));
*/
void ext_equal_set(int *s1, int *s2, int len) {
    //@ assert ((\forall integer i; 0 <= i < (len) ==>              (\exists integer j; 0 <= j < (len) && \at((s1)[i], Here) == \at((s2)[j], Here))) &&         (\forall integer i; 0 <= i < (len) ==>              (\exists integer j; 0 <= j < (len) && \at((s2)[i], Here) == \at((s1)[j], Here))));
}

int main() {
    return 0;
}

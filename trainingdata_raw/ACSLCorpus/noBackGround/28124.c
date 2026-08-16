struct C {
    int *a;
    int *b;
    int size_a;
    int size_b;
};

/*@
    requires \valid(a1 + (0..size_a-1)) && \valid(a2 + (0..size_a-1));
    requires \valid(b1 + (0..size_b-1)) && \valid(b2 + (0..size_b-1));
    requires size_a >= 0 && size_b >= 0;
    requires \forall integer i; 0 <= i < size_a ==> a1[i] == a2[i];
    requires \forall integer i; 0 <= i < size_b ==> (b1[i] != 0) == (b2[i] != 0);
    requires \forall integer i; 0 <= i < size_b ==> (b1[i] != 0) ==> b1[i] == b2[i];
    ensures \result == 1;
    assigns \nothing;
*/
int verify_struct_equality(int *a1, int *a2, int size_a, int *b1, int *b2, int size_b) {
    int i;
    
    //@ assert \forall integer j; 0 <= j < size_a ==> a1[j] == a2[j];
    
    i = 0;
    /*@
        loop invariant 0 <= i <= size_b;
        loop invariant \forall integer j; 0 <= j < i ==> (b1[j] != 0) == (b2[j] != 0);
        loop assigns i;
    */
    while (i < size_b) {
        //@ assert (b1[i] != 0) == (b2[i] != 0);
        i++;
    }
    
    i = 0;
    /*@
        loop invariant 0 <= i <= size_b;
        loop invariant \forall integer j; 0 <= j < i ==> (b1[j] != 0) ==> b1[j] == b2[j];
        loop assigns i;
    */
    while (i < size_b) {
        //@ assert (b1[i] != 0) ==> b1[i] == b2[i];
        i++;
    }
    
    return 1;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}

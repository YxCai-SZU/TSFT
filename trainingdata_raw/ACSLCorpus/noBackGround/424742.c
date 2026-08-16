int main() {
    // Declarations
    int elements1[10];
    int elements2[10];
    int i;
    
    // Initialization
    /*@
        loop invariant 0 <= i <= 10;
        loop invariant \forall integer j; 0 <= j < i ==> elements1[j] == j;
        loop invariant \forall integer j; 0 <= j < i ==> elements2[j] == j;
        loop assigns i, elements1[0..9], elements2[0..9];
     */
    for (i = 0; i < 10; i++) {
        elements1[i] = i;
        elements2[i] = i;
    }
    
    // Verification
    /*@
        loop invariant 0 <= i <= 10;
        loop invariant \forall integer j; 0 <= j < i ==> elements1[j] == elements2[j];
        loop assigns i;
     */
    for (i = 0; i < 10; i++) {
        //@ assert elements1[i] == elements2[i];
    }
    
    //@ assert (\forall integer i; 0 <= i < (10) ==> (&elements1[0])[i] == (&elements2[0])[i]);
    return 0;
}

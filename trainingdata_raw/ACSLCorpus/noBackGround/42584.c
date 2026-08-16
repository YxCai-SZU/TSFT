#include <stddef.h>

/*@
    assigns \nothing;
*/
void seq_operations(void) {
    int s[5];
    int sub1[3];
    int sub2[3];
    int i;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> s[j] == 10 * j;
        loop assigns i, s[0..4];
    */
    for (i = 0; i < 5; i++) {
        s[i] = 10 * i;
    }
    
    //@ assert \true;
    
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \forall integer j; 0 <= j < i ==> sub1[j] == s[j];
        loop assigns i, sub1[0..2];
    */
    for (i = 0; i < 3; i++) {
        sub1[i] = s[i];
    }
    
    //@ assert \true;
    
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \forall integer j; 0 <= j < i ==> sub2[j] == s[j + 2];
        loop assigns i, sub2[0..2];
    */
    for (i = 0; i < 3; i++) {
        sub2[i] = s[i + 2];
    }
    
    //@ assert \true;
}

/*@
    assigns \nothing;
*/
void seq_push_update(void) {
    int s[3];
    int len = 0;
    
    s[len++] = 10;
    //@ assert \true;
    
    s[len++] = 20;
    //@ assert \true;
    
    s[len++] = 30;
    //@ assert \true;
    
    s[1] = 25;
    //@ assert \true;
}

/*@
    assigns \nothing;
*/
void seq_add_subrange(void) {
    int s1[3] = {1, 2, 3};
    int s2[3] = {4, 5, 6};
    int combined[6];
    int sub1[3];
    int sub2[3];
    int i;
    
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \forall integer j; 0 <= j < i ==> combined[j] == s1[j];
        loop assigns i, combined[0..2];
    */
    for (i = 0; i < 3; i++) {
        combined[i] = s1[i];
    }
    
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \forall integer j; 0 <= j < i ==> combined[j + 3] == s2[j];
        loop assigns i, combined[3..5];
    */
    for (i = 0; i < 3; i++) {
        combined[i + 3] = s2[i];
    }
    
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \forall integer j; 0 <= j < i ==> sub1[j] == combined[j];
        loop assigns i, sub1[0..2];
    */
    for (i = 0; i < 3; i++) {
        sub1[i] = combined[i];
    }
    
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \forall integer j; 0 <= j < i ==> sub2[j] == combined[j + 3];
        loop assigns i, sub2[0..2];
    */
    for (i = 0; i < 3; i++) {
        sub2[i] = combined[i + 3];
    }
}

/*@
    assigns \nothing;
*/
int main(void) {
    seq_operations();
    seq_push_update();
    seq_add_subrange();
    return 0;
}

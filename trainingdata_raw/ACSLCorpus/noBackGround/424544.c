#include <stddef.h>

/*@
    assigns \nothing;
*/
void example7(void) {
    int s1_0[2];
    int s1_1[2];
    int flattened[4];
    int s2[2];
    int combined[6];
    int s3[3];
    int further_combined[9];
    
    s1_0[0] = 10;
    s1_0[1] = 20;
    s1_1[0] = 30;
    s1_1[1] = 40;
    
    flattened[0] = 10;
    flattened[1] = 20;
    flattened[2] = 30;
    flattened[3] = 40;
    
    //@ assert \forall integer i; 0 <= i < 4 ==> flattened[i] == flattened[i];
    
    s2[0] = 100;
    s2[1] = 200;
    
    combined[0] = 10;
    combined[1] = 20;
    combined[2] = 30;
    combined[3] = 40;
    combined[4] = 100;
    combined[5] = 200;
    
    //@ assert combined[3] == 40;
    //@ assert combined[4] == 100;
    
    s3[0] = 5;
    s3[1] = 15;
    s3[2] = 25;
    
    further_combined[0] = 10;
    further_combined[1] = 20;
    further_combined[2] = 30;
    further_combined[3] = 40;
    further_combined[4] = 100;
    further_combined[5] = 200;
    further_combined[6] = 5;
    further_combined[7] = 15;
    further_combined[8] = 25;
    
    //@ assert further_combined[6] == 5;
    //@ assert further_combined[7] == 15;
    //@ assert further_combined[8] == 25;
}

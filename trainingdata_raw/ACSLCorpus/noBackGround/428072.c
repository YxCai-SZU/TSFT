/*@
    requires 1 <= no1 <= 3;
    requires 1 <= no2 <= 3;
    requires 1 <= no3 <= 3;
    ensures \result >= 0;
    ensures \result <= 2;
    assigns \nothing;
*/
int min_rotor_diff(int no1, int no2, int no3)
{
    int no1_no2;
    int no2_no3;
    int no3_no1;
    int min;
    
    //@ assert (1 <= (no1) <= 3);
    //@ assert (1 <= (no2) <= 3);
    //@ assert (1 <= (no3) <= 3);
    
    if (no1 > no2) {
        no1_no2 = no1 - no2;
    } else {
        no1_no2 = no2 - no1;
    }
    
    if (no2 > no3) {
        no2_no3 = no2 - no3;
    } else {
        no2_no3 = no3 - no2;
    }
    
    if (no3 > no1) {
        no3_no1 = no3 - no1;
    } else {
        no3_no1 = no1 - no3;
    }
    
    //@ assert no1_no2 == ((no1) > (no2) ? (no1) - (no2) : (no2) - (no1));
    //@ assert no2_no3 == ((no2) > (no3) ? (no2) - (no3) : (no3) - (no2));
    //@ assert no3_no1 == ((no3) > (no1) ? (no3) - (no1) : (no1) - (no3));
    
    min = no1_no2;
    
    if (no2_no3 < min) {
        min = no2_no3;
    }
    
    if (no3_no1 < min) {
        min = no3_no1;
    }
    
    //@ assert min >= 0;
    //@ assert min <= 2;
    
    return min;
}

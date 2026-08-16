#include <stdbool.h>

/*@ requires \valid(v) && ((2) == 2 &&
    (v)[0] >= 1 && (v)[0] <= 100 &&
    (v)[1] >= 1 && (v)[1] <= 100);
    ensures \result == true <==> v[0] > v[1];
    assigns \nothing;
*/
bool func(int *v) {
    int d_hospital;
    int d_hotel;
    
    //@ assert v[0] >= 1 && v[0] <= 100;
    //@ assert v[1] >= 1 && v[1] <= 100;
    
    d_hospital = v[0];
    d_hotel = v[1];
    
    if (d_hospital > d_hotel) {
        //@ assert d_hospital > d_hotel;
        return true;
    } else {
        //@ assert d_hospital <= d_hotel;
        return false;
    }
}

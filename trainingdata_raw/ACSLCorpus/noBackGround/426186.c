#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid_read(v+(0..len-1));
    requires len > 0;
    requires \forall integer i; 0 <= i < len ==> (0 <= (v[i]) && (v[i]) <= 100);
    assigns \nothing;
    ensures \result == true ==> 
            (\forall integer i; 0 <= i < len ==> v[i] > 50);
    ensures \result == false ==> 
            (\exists integer i; 0 <= i < len && v[i] <= 50);
*/
bool process_list(const unsigned int* v, size_t len) {
    size_t j = 0;
    /*@ loop invariant 0 <= j <= len;
        loop invariant \forall integer i; 0 <= i < j ==> v[i] > 50;
        loop assigns j;
        loop variant len - j;
    */
    while (j < len) {
        //@ assert (0 <= (v[j]) && (v[j]) <= 100);
        int check_result = (v[j] > 50 ? 1 : 0);
        //@ assert ((check_result) == ((v[j]) > 50 ? 1 : 0));
        if (!check_result) {
            return false;
        }
        j = j + 1;
    }
    return true;
}

int main() {
    unsigned int threshold_list[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    size_t len = 11;
    
    //@ assert len > 0;
    //@ assert \forall integer i; 0 <= i < len ==> (0 <= (threshold_list[i]) && (threshold_list[i]) <= 100);
    bool result = process_list(threshold_list, len);
    //@ assert result == false;
    
    return 0;
}

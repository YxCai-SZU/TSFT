#include <stdbool.h>
#include <stddef.h>

/*@ requires start <= end;
    ensures \result == (test_value >= start && test_value <= end);
    assigns \nothing; */
bool check_range(int test_value, int start, int end) {
    bool result;
    //@ assert start <= end;
    result = (test_value >= start && test_value <= end);
    //@ assert result == (test_value >= start && test_value <= end);
    return result;
}

/*@ requires \valid(v+(0..len-1));
    requires len > 0;
    requires \forall integer i; 0 <= i < len ==> start <= end;
    ensures \result ==> \forall integer i; 0 <= i < len ==> ((start) <= (end) && (v[i]) >= (start) && (v[i]) <= (end));
    ensures !\result ==> \exists integer i; 0 <= i < len && !((start) <= (end) && (v[i]) >= (start) && (v[i]) <= (end));
    assigns \nothing; */
bool process_list(int *v, size_t len, int start, int end) {
    size_t j;
    bool all_in_range;
    
    //@ assert len > 0;
    //@ assert \forall integer i; 0 <= i < len ==> start <= end;
    
    all_in_range = true;
    j = 0;
    
    /*@ loop invariant 0 <= j <= len;
        loop invariant \forall integer i; 0 <= i < j ==> ((start) <= (end) && (v[i]) >= (start) && (v[i]) <= (end));
        loop invariant all_in_range ==> (j == 0 || \forall integer i; 0 <= i < j ==> ((start) <= (end) && (v[i]) >= (start) && (v[i]) <= (end)));
        loop invariant !all_in_range ==> \exists integer i; 0 <= i < j && !((start) <= (end) && (v[i]) >= (start) && (v[i]) <= (end));
        loop assigns j, all_in_range;
        loop variant len - j; */
    while (j < len) {
        bool check_result;
        check_result = check_range(v[j], start, end);
        
        if (!check_result) {
            all_in_range = false;
            //@ assert \exists integer i; 0 <= i < len && !((start) <= (end) && (v[i]) >= (start) && (v[i]) <= (end));
            return false;
        }
        //@ assert ((start) <= (end) && (v[j]) >= (start) && (v[j]) <= (end));
        j++;
    }
    
    //@ assert \forall integer i; 0 <= i < len ==> ((start) <= (end) && (v[i]) >= (start) && (v[i]) <= (end));
    return true;
}

int main() {
    int in_range_list[] = {-10, -7, -4, 0, 3, 6, 9};
    size_t list_len = sizeof(in_range_list) / sizeof(in_range_list[0]);
    bool result;
    
    //@ assert list_len > 0;
    //@ assert \forall integer i; 0 <= i < list_len ==> -10 <= 10;
    
    result = process_list(in_range_list, list_len, -10, 10);
    
    //@ assert result ==> \forall integer i; 0 <= i < list_len ==> ((-10) <= (10) && (in_range_list[i]) >= (-10) && (in_range_list[i]) <= (10));
    return 0;
}

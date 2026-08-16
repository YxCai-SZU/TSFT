#include <stddef.h>
#include <stdint.h>

/*@ requires n <= 100;
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (input_numbers)[i] && (input_numbers)[i] <= 100);
    assigns \nothing;
    ensures \result == 0 || \result == 1 || \result == -1; */
int func(size_t n, int input_numbers[]) {
    size_t a = 0;
    size_t b = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= a <= i;
        loop invariant 0 <= b <= i;
        loop invariant \forall integer j; 0 <= j < i ==> 1 <= input_numbers[j] && input_numbers[j] <= 100;
        loop assigns i, a, b;
        loop variant n - i; */
    while (i < n) {
        int v = input_numbers[i];
        
        //@ assert 1 <= v && v <= 100;
        
        if (v % 2 == 0) {
            if (v % 3 == 0 || v % 5 == 0) {
                a += 1;
            } else {
                b += 1;
            }
        }
        i += 1;
    }
    
    //@ assert i == n;
    //@ assert 0 <= a <= n;
    //@ assert 0 <= b <= n;
    
    if (a >= 1) {
        return 0;
    } else if (b >= 1) {
        return 1;
    } else {
        return -1;
    }
}

/*@ ensures \result == 0 || \result == 1 || \result == -1;
    assigns \nothing; */
int main() {
    int arr[3] = {2, 3, 4};
    return func(3, arr);
}

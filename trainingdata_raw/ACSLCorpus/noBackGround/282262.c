#include <limits.h>

/*@ requires ((length) >= 0 && (width) >= 0 && (length) * (width) <= INT_MAX);
    ensures \result == length * width;
    assigns \nothing;
*/
int area_rect(int length, int width) {
    //@ assert length >= 0;
    //@ assert width >= 0;
    //@ assert (long long)length * (long long)width <= INT_MAX;
    return length * width;
}

/*@ requires min <= max;
    ensures \result == (min <= num && num <= max);
    assigns \nothing;
*/
int is_within_range(int num, int min, int max) {
    int ret;
    ret = (num >= min && num <= max);
    //@ assert ret == (min <= num && num <= max);
    return ret;
}

/*@ ensures \result == a || \result == b || \result == c;
    ensures \result >= a && \result >= b && \result >= c;
    assigns \nothing;
*/
int max_of_three(int a, int b, int c) {
    int ret;
    if (a > b && a > c) {
        ret = a;
    } else if (b > c) {
        ret = b;
    } else {
        ret = c;
    }
    //@ assert ret >= a && ret >= b && ret >= c;
    return ret;
}

/*@ requires ((edge_length) >= 0 && (edge_length) * (edge_length) * (edge_length) <= INT_MAX);
    ensures \result == edge_length * edge_length * edge_length;
    assigns \nothing;
*/
int volume_cube(int edge_length) {
    //@ assert edge_length >= 0;
    //@ assert (long long)edge_length * (long long)edge_length * (long long)edge_length <= INT_MAX;
    
    //@ assert edge_length >= 0 && edge_length <= 1290;
    //@ assert edge_length * edge_length >= 0 && edge_length * edge_length <= 1290 * 1290;
    //@ assert edge_length * edge_length * edge_length >= 0 && edge_length * edge_length * edge_length <= 1290 * 1290 * 1290;
    
    return edge_length * edge_length * edge_length;
}

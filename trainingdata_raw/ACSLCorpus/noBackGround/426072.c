/*@
    requires a >= 0 && h >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int compute_triangle_area(int a, int h) {
    int area;
    //@ assert a >= 0 && h >= 0;
    area = (a * h) / 2;
    //@ assert area == (((a) * (h)) / 2);
    //@ assert area >= 0;
    return area;
}

int main() {
    int result1;
    int result2;
    
    //@ assert (((3) * (4)) / 2) >= 0;
    result1 = compute_triangle_area(3, 4);
    //@ assert result1 >= 0;
    
    //@ assert (((0) * (0)) / 2) >= 0;
    result2 = compute_triangle_area(0, 0);
    //@ assert result2 >= 0;
    
    return 0;
}

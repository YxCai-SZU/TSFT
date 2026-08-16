/*@
    requires (1 <= (a) <= 1000000000000);
    ensures \result == (((a) / 2) + ((a) % 2));
    assigns \nothing;
*/
long func(long a) {
    long result = 0;
    long temp_a = a;
    long count = 0;
    
    /*@
        loop invariant 0 <= temp_a <= a;
        loop invariant temp_a == ((a) - 2 * (count));
        loop invariant 0 <= count <= a / 2;
        loop assigns temp_a, count;
        loop variant temp_a;
    */
    while (temp_a >= 2) {
        //@ assert temp_a >= 2;
        temp_a -= 2;
        count += 1;
    }
    
    long remainder = (temp_a == 1) ? 1 : 0;
    
    result = count + remainder;
    
    //@ assert result == (((a) / 2) + ((a) % 2));
    return result;
}

int main() {
    return 0;
}

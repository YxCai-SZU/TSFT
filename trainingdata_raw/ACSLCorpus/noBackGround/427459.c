/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (2 * 314159 * r) / 100000;
    assigns \nothing;
*/
long long func(long long r)
{
    long long pi;
    long long scale;
    long long circumference;
    long long temp;
    long long count;
    
    pi = 314159;
    scale = 100000;
    circumference = 0;
    temp = 2 * pi * r;
    count = 0;
    
    //@ assert ((pi) == 314159);
    //@ assert ((scale) == 100000);
    //@ assert temp == (2 * (pi) * (r));
    
    /*@
        loop invariant ((1 <= ((r)) && ((r)) <= 100) &&
        (((pi)) == 314159) &&
        (((scale)) == 100000) &&
        (temp) >= 0 &&
        (temp) == (2 * ((pi)) * ((r))) - (count) * (scale) &&
        (count) >= 0);
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= scale) {
        //@ assert temp >= scale;
        temp -= scale;
        count += 1;
        //@ assert temp == (2 * (pi) * (r)) - count * scale;
    }
    
    //@ assert temp < scale;
    //@ assert temp >= 0;
    circumference = count;
    
    //@ assert circumference == (2 * 314159 * r) / 100000;
    return circumference;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}

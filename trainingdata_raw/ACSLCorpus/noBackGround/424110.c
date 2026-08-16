/*@
    requires 1 <= r && r <= 100;
    ensures \result == ((2 * ((r)) * ((314))) / (100));
    assigns \nothing;
*/
int func(long long r)
{
    // Variable declarations at top of scope
    long long precision_factor;
    long long pi;
    long long circumference;
    long long result;
    long long temp;
    long long count;
    
    precision_factor = 100;
    pi = 314;
    circumference = 2 * r * pi;
    result = 0;
    temp = circumference;
    count = 0;
    
    /*@
        loop invariant 1 <= r && r <= 100;
        loop invariant ((precision_factor) == 100);
        loop invariant ((pi) == 314);
        loop invariant ((circumference) == 2 * (r) * (pi));
        loop invariant ((temp) >= 0 && (count) * (precision_factor) + (temp) == (circumference));
        loop invariant count > 0 ==> result == count;
        loop assigns temp, count, result;
        loop variant temp;
    */
    while (temp >= precision_factor) {
        //@ assert temp >= precision_factor;
        temp -= precision_factor;
        count += 1;
        result = count;
    }
    
    //@ assert count * precision_factor + temp == circumference;
    return result;
}

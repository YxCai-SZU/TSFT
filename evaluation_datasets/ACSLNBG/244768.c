
unsigned long func(unsigned long n)
{
    unsigned long result;
    unsigned long remainder;
    
    result = (n / 11) * 2;
    remainder = n % 11;
    
    //@ assert result == (n / 11) * 2;
    
    if (remainder > 0 && remainder <= 6) {
        result += 1;
        //@ assert result == (n / 11) * 2 + 1;
    } else if (remainder > 6) {
        result += 2;
        //@ assert result == (n / 11) * 2 + 2;
    }
    
    //@ assert result == (((n) / 11) * 2 +          (((n) % 11) > 0 && ((n) % 11) <= 6 ? 1 :           (((n) % 11) > 6 ? 2 : 0)));
    //@ assert result <= 2 * (n / 11) + 2;
    //@ assert result >= 0;
    
    return result;
}

int main()
{
    //@ assert ((15) % 3 == 0 && (15) % 5 == 0);
    return 0;
}

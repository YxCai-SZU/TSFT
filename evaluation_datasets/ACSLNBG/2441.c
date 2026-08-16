
long func(long a, long b, long c, long d)
{
    long max_value;
    long current_value;

    //@ assert (-1000000000 <= (a) && (a) <= 1000000000);
    //@ assert (-1000000000 <= (c) && (c) <= 1000000000);
    //@ assert (-1000000000000000000 <= (a) * (c) && (a) * (c) <= 1000000000000000000);
    max_value = a * c;

    //@ assert (-1000000000000000000 <= (a) * (d) && (a) * (d) <= 1000000000000000000);
    current_value = a * d;
    if (current_value > max_value) {
        max_value = current_value;
    }

    //@ assert (-1000000000000000000 <= (b) * (c) && (b) * (c) <= 1000000000000000000);
    current_value = b * c;
    if (current_value > max_value) {
        max_value = current_value;
    }

    //@ assert (-1000000000000000000 <= (b) * (d) && (b) * (d) <= 1000000000000000000);
    current_value = b * d;
    if (current_value > max_value) {
        max_value = current_value;
    }

    return max_value;
}

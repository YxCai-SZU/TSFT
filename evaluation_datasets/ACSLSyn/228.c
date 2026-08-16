#include <stdbool.h>
#include <string.h>
#include <stddef.h>

/* Predicates from first snippet */
/*@ predicate is_even(integer x) = x % 2 == 0; */
/*@ predicate is_odd(integer x) = x % 2 != 0; */

struct Student {
    char* name;
    unsigned int age;
};

/*@ predicate is_adult(struct Student* s) = s->age >= 18; */

/*@ lemma age_preserved:
      \forall struct Student* s, char* new_name;
        is_adult(s) ==> is_adult(s); */

/* Predicates from second snippet */
/*@ predicate is_valid_range(int N) = 1 <= N <= 1000000; */
/*@ predicate is_valid_M(int M) = 1 <= M <= 10000; */
/*@ predicate is_valid_vector(int *v, int M) = 
      \forall integer i; 0 <= i < M ==> 1 <= v[i] <= 10000; */

/*@ lemma ans_bound_lemma: 
      \forall integer index, integer ans; 
      0 <= index && ans >= 0 && ans <= index * 10000 ==> 
      ans <= (index + 1) * 10000; */

/* Original func1: integer polynomial evaluation */
int func(int a)
{
    //@ assert 1 <= a && a <= 10;
    //@ assert a * a <= 10 * 10;
    //@ assert a * a * a >= 1 * 1 * 1;
    //@ assert a * a * a <= 10 * 10 * 10;
    return a + a * a + a * a * a;
}

/* Original func2: student name change */
struct Student change_name(struct Student* s, char* new_name)
{
    struct Student ret;
    //@ assert is_adult(s);
    ret.name = new_name;
    ret.age = s->age;
    //@ assert ret.age == s->age;
    return ret;
}

/* Original func3: vector sum and comparison */
int func_vec(int N, int M, int *v) {
    int ans = 0;
    int index = 0;
    
    while (index < M) {
        int val = v[index];
        //@ assert 1 <= val <= 10000;
        ans += val;
        //@ assert ans >= 0;
        //@ assert ans <= (index + 1) * 10000;
        index += 1;
    }
    
    if (ans <= N) {
        return N - ans;
    } else {
        return -1;
    }
}

/* Synthesized function: Student grade processing system
 * Scenario: A university system processes student records. Each student has an age and 
 * a vector of grades (values 1-10000). The system computes a polynomial transformation of 
 * the student's age (func), updates the student's name (change_name), and then checks 
 * if the sum of grades fits within a capacity N (func_vec). The final result indicates 
 * the remaining capacity or an error (-1).
 *
 * Data flow:
 * 1. Compute polynomial of age: poly = func(student->age)
 * 2. Create a new student record with updated name and same age
 * 3. Check if sum of grades (v of length M) fits within capacity N
 * 4. Return remaining capacity or -1
 *
 * High-level property: The output is either non-negative and bounded by N, or -1.
 */
int process_student_grades(struct Student* student, char* new_name, int N, int M, int *v) {
    int poly = func(student->age);
    //@ assert poly == student->age + student->age * student->age + student->age * student->age * student->age;
    
    struct Student updated = change_name(student, new_name);
    //@ assert updated.age == student->age;
    //@ assert is_adult(&updated);
    
    int remaining = func_vec(N, M, v);
    //@ assert (remaining >= 0 ==> remaining <= N) || (remaining == -1);
    
    //@ assert (remaining >= 0 ==> remaining <= N) || (remaining == -1);
    return remaining;
}

int main() {
    return 0;
}

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* First function: finds smallest divisor of x (or x itself if prime) */
/*@
    predicate is_valid_range(integer x) = 1 <= x <= 1000000000000000;
    
    lemma loop_decreases: \forall integer x, i; 
        is_valid_range(x) && 1 <= i <= x ==> x - i >= 0;
*/
uint64_t smallest_divisor(uint64_t x)
{
    uint64_t i;
    uint64_t result;

    i = 1;
    result = 0;

    while (i < x)
    {
        if (x % i == 0)
        {
            result = i;
            //@ assert result >= 1 && result <= x && x % result == 0;
            return result;
        }
        i = i + 1;
    }

    result = x;
    //@ assert result >= 1 && result <= x && x % result == 0;
    return result;
}

/* Second function: exercise data structure */
enum ExerciseTag { Running, Cycling, Swimming };

struct Exercise {
    enum ExerciseTag tag;
    union {
        struct { unsigned distance; unsigned speed; } Running;
        struct { unsigned distance; unsigned speed; } Cycling;
        struct { unsigned laps; unsigned pool_length; } Swimming;
    };
};

/*@
    predicate is_athletic(struct Exercise e) =
        (e.tag == Running && e.Running.distance > 10) ||
        (e.tag == Cycling && e.Cycling.distance > 50) ||
        (e.tag == Swimming && e.Swimming.laps > 20);

    logic integer get_distance(struct Exercise e) =
        e.tag == Running ? e.Running.distance :
        e.tag == Cycling ? e.Cycling.distance :
        e.Swimming.laps * e.Swimming.pool_length;
*/

/*@
    lemma get_distance_cycling:
        \forall struct Exercise e;
        e.tag == Cycling && e.Cycling.distance == 60 ==> get_distance(e) == 60;
*/

/* Third function: min of three integers */
/*@ predicate is_min(integer ret, integer a, integer b, integer c) =
      ret <= a && ret <= b && ret <= c;
*/
int min_of_three(int a, int b, int c)
{
   int min_val;
   min_val = a;
   //@ assert min_val <= a;
   if (b < min_val)
   {
      min_val = b;
   }
   //@ assert min_val <= a && min_val <= b;
   if (c < min_val)
   {
      min_val = c;
   }
   //@ assert is_min(min_val, a, b, c);
   return min_val;
}

/* Synthesized function: workout plan optimizer for a fitness app
   Given a target distance D, find the smallest divisor of D to determine 
   segment length, then create an exercise plan with that segment length 
   as the distance, and select the minimum of three pacing options.
   Scenario: A fitness app that creates structured interval workouts */
unsigned workout_optimizer(unsigned target_distance)
{
    uint64_t segment = smallest_divisor((uint64_t)target_distance);
    //@ assert segment >= 1 && segment <= (uint64_t)target_distance && (uint64_t)target_distance % segment == 0;
    
    struct Exercise exercise;
    exercise.tag = Cycling;
    exercise.Cycling.distance = (unsigned)segment;
    exercise.Cycling.speed = 25;
    //@ assert exercise.tag == Cycling;
    //@ assert exercise.Cycling.distance == (unsigned)segment;
    
    int pacing_a = (int)(segment / 2);
    int pacing_b = (int)(segment / 3);
    int pacing_c = (int)(segment / 4);
    int best_pacing = min_of_three(pacing_a, pacing_b, pacing_c);
    //@ assert is_min(best_pacing, pacing_a, pacing_b, pacing_c);
    
    //@ assert best_pacing <= (int)(segment / 3);
    return (unsigned)best_pacing;
}

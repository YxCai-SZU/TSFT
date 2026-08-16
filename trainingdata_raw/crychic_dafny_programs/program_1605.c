// Generated C + ACSL

/*@
    requires timePoints_len >= 2;
    requires timePoints != \null;
    requires \valid_read(timePoints + (0 .. timePoints_len-1));
    requires \forall integer i, j; 0 <= i < j < timePoints_len ==> timePoints[i] < timePoints[j];
    assigns \nothing;
    ensures \result != \null;
    ensures \valid(\result + (0 .. timePoints_len-1));
*/
int* parareal(int problem, int initialCondition, int* timePoints, int timePoints_len);

/*@
    requires paraSolution != \null;
    requires \valid_read(paraSolution + (0 .. timePoints_len-1));
    requires timePoints != \null;
    requires \valid_read(timePoints + (0 .. timePoints_len-1));
    requires timePoints_len >= 2;
    assigns \nothing;
    ensures \result != \null;
    ensures \valid(\result + (0 .. timePoints_len-1));
*/
int* tabulate(int* paraSolution, int* timePoints, int timePoints_len);

/*@
    requires timePoints_len >= 2;
    requires timePoints != \null;
    requires \valid_read(timePoints + (0 .. timePoints_len-1));
    requires \forall integer i, j; 0 <= i < j < timePoints_len ==> timePoints[i] < timePoints[j];
    assigns \nothing;
    ensures \result != \null;
    ensures \valid(\result + (0 .. timePoints_len-1));
*/
int* Solve(int problem, int initialCondition, int* timePoints, int timePoints_len)
{
  int* paraSolution = parareal(problem, initialCondition, timePoints, timePoints_len);
  /*@ assert paraSolution != \null; */
  /*@ assert \valid_read(paraSolution + (0 .. timePoints_len-1)); */
  
  int* solution = tabulate(paraSolution, timePoints, timePoints_len);
  /*@ assert solution != \null; */
  /*@ assert \valid(solution + (0 .. timePoints_len-1)); */
  
  return solution;
}

// skipped function tabulate due to unsupported type

// skipped function parareal due to unsupported type
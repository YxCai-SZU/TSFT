// Generated C + ACSL

typedef struct {
  int x;
  int y;
  int z;
} Vector3;

typedef struct {
  Vector3 position;
  Vector3 velocity;
} Particle;

Particle satellite;
Vector3 truePosition;
Vector3 trueVelocity;

/*@
    requires particlePositions_len == particleVelocities_len;
    requires particlePositions_len >= 0;
    requires particlePositions_len > 0 ==> \valid(particlePositions + (0 .. particlePositions_len-1));
    requires particleVelocities_len > 0 ==> \valid(particleVelocities + (0 .. particleVelocities_len-1));
    assigns truePosition, trueVelocity;
*/
void Initialize(int* particlePositions, int particlePositions_len, int* particleVelocities, int particleVelocities_len, int satPos, int satVel, int truePos, int trueVel)
{
  int i = 0;
  int particles = 0;
  /*@ assert particles >= 0 && particles <= 2147483647; */
/*@
  loop invariant 0 <= i <= particlePositions_len;
  loop invariant particlePositions_len > 0 ==> \valid(particlePositions + (0..particlePositions_len-1));
  loop invariant particleVelocities_len > 0 ==> \valid(particleVelocities + (0..particleVelocities_len-1));
  loop assigns i, particles;
  loop variant particlePositions_len - i;
*/
  while ((i < particlePositions_len))
    {
      int newParticle; /* unsupported init: Microsoft.Dafny.AllocateClass */
      particles = (particles + 0);
      i = (i + 1);
    }
  truePosition.x = truePos;
  trueVelocity.x = trueVel;
}

/*@
    assigns \nothing;
    ensures \result >= 0;
*/
int Distance(Vector3 v1, Vector3 v2)
{
  int dx = v1.x - v2.x;
  int dy = v1.y - v2.y;
  int dz = v1.z - v2.z;
  return dx * dx + dy * dy + dz * dz;
}

/*@
    requires tolerance >= 0;
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int VerifyPosition(int tolerance)
{
  int dist = Distance(satellite.position, truePosition);
  int isValid = (dist <= tolerance);
  /*@ assert isValid >= 0 && isValid <= 2147483647; */
  return isValid;
}
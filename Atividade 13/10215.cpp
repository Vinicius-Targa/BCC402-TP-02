// 10215 - The Largest/Smallest Box ...

/* Given the width and height of the box, you will have to find the value of x
 * for which the box has maximum and minimum volume */

/* os cálculos foram retirados do site:
 * https://sites.math.washington.edu/~conroy/general/boxanim/boxAnimation.htm
 e pesquisando "FOLDING BOX PROBLEM no google"
*/

#include <cmath>
#include <iostream>
#include <climits>
#include <iomanip>

//Definindo constante epsilon (para calcular o mínimo)
#define eps 1e-8

using namespace std;

// calcula o maior e menor volume que a caixa pode assumir
float *calculateBoxLimits(float L, float W) {
  //o cálculo do máximo é feito com a seguinte formula:
  float max = (W+L - sqrt(W*W-W*L+L*L))/6.0, min;

  if(W > L)
    min = L;
  else
    min = W;

  //é calculado o lado menor, e o main próximo do mínimo seria metade dom menor lado mais a epsilon
  min = min/2.0+eps;
  
  // preparando vetor de retorno
  float *ans = new float[3];
  ans[0] = max;
  ans[1] = 0.000;
  ans[2] = min;
  return ans;
}

int main() {
  float L, W, *ans;

  while (cin >> L >> W) {
    ans = calculateBoxLimits(L, W);

    cout << fixed << setprecision(3) << ans[0] << " " << ans[1] << " " << ans[2] << endl;

    delete[] ans;
  }
  return 0;
}
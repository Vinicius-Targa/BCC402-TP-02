// 10177 - (2/3/4)-D Sqr/Rects/Cubes/Boxes?

/* You can see a (4 × 4) grid below. Can you tell me how many squares and rectangles are hidden there? You can assume that squares are not rectangles. Perhaps one can count it by hand but can you count it for a (100 × 100) grid or a (10000 × 10000) grid. Can you do it for higher dimensions? That is can you count how many cubes or boxes of different size are there in a (10 × 10 × 10) sized cube or how many hyper-cubes or hyper-boxes of different size are there in a four-dimensional (5 × 5 × 5 × 5) sized hypercube. Remember that your program needs to be very efficient. You can assume that squares are not rectangles, cubes are not boxes and hyper-cubes are not hyper-boxes. */

/* os cálculos foram retirados do site: https://mba.hitbullseye.com/CAT/Chess-Puzzles.php */

#include <iostream>
#include <cmath>
using namespace std;

int* countCubeRectangles(int n){
  //a quantidade de quadrados pode ser dada por ∑n^d, onde d é a dimensão e n é o tamanho do lado.
  //Contando os Quadrados...
  int S2 = 0, S3 = 0, S4 = 0;
  for(int i = 1; i <= n; i++){
    S2 += pow(i, 2); 
    S3 += pow(i, 3); 
    S4 += pow(i, 4); 
  }

  //Para contar os retângulos, é usado a formula de combinação adaptada para as dimensões, e tirado o número de quadrados.
  //Contando os Retângulos...
  int R2, R3, R4;
  for(int i = 1; i <= n; i++){
    R2 = pow((i*(i+1))/2,2) - S2;
    R3 = pow((i*(i+1))/2,3) - S3;
    R4 = pow((i*(i+1))/2,4) - S4;
  }
  
  //montando o vetor de resposta
  int* ans = new int[6];
  ans[0] = S2;
  ans[1] = R2;
  ans[2] = S3;
  ans[3] = R3;
  ans[4] = S4;
  ans[5] = R4;
  return ans;
}

int main(){
  int n, max_iter = 100;
  int *ans;

  for(int i = 0; i < max_iter; i++){
    //se n for igual a zero, a execução para
    if(n == 0)
      break;
    
    cin >> n;

    ans = countCubeRectangles(n);

    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<" "<<ans[4]<<" "<<ans[5]<<endl;

    delete [] ans;
  }
  return 0;
}
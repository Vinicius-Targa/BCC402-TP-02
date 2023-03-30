#include <iostream>
#include <cmath>
#include <assert.h>

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

void testOne(){
  int n = 1, *vet;
  int expected[6] = {1, 0, 1, 0, 1, 0};

  vet = countCubeRectangles(n);

  assert(vet[0] == expected[0]);
  assert(vet[1] == expected[1]);
  assert(vet[2] == expected[2]);
  assert(vet[3] == expected[3]);
  assert(vet[4] == expected[4]);
  assert(vet[5] == expected[5]);

  cout<<"Test 01: OK!"<<endl;

  delete [] vet;
}

void testTwo(){
  int n = 2, *vet;
  int expected[6] = {5, 4, 9, 18, 17, 64};

  vet = countCubeRectangles(n);

  assert(vet[0] == expected[0]);
  assert(vet[1] == expected[1]);
  assert(vet[2] == expected[2]);
  assert(vet[3] == expected[3]);
  assert(vet[4] == expected[4]);
  assert(vet[5] == expected[5]);

  cout<<"Test 02: OK!"<<endl;

  delete [] vet;
}

void testThree(){
  int n = 3, *vet;
  int expected[6] = {14, 22, 36, 180, 98, 1198};

  vet = countCubeRectangles(n);

  assert(vet[0] == expected[0]);
  assert(vet[1] == expected[1]);
  assert(vet[2] == expected[2]);
  assert(vet[3] == expected[3]);
  assert(vet[4] == expected[4]);
  assert(vet[5] == expected[5]);

  cout<<"Test 03: OK!"<<endl;

  delete [] vet;
}

int main(){
  
  testOne();
  testTwo();
  testThree();
  
  return 0;
}
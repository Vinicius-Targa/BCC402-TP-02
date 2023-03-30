/* Os testes são feitos pela biblioteca assert, onde se compara os resultados esperados com os resultados que a função retorna,
 caso exista algum erro, o assert para a execução do programa e notifica */

#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

bool isPrime(int n){
  //se for 0 ou 1, não é primo
  if(n == 0) 
    return false;
   
  for(int i = 2; i < n; i++){
    //se o número ter um divisor, não é primo
    if(n % i == 0)
      return false;
  }
  
  //se passou por tudo isso, o número é primo
  return true;
}

void findSmallerPrimes(int n, vector<int> &primes){
  // Encontrar todos os primos de 1 até n, e armazenar no vector.
  for(int i = 1; i <= n; i++){
    if(isPrime(i)){
      primes.push_back(i);
    }
  }
}

vector<int> findSummationFourPrimes(int n){
  //Primeiro são encontrados os primos até o número n, depois é feita a combinação de todos esses primos de 4 em 4 para verificar se a soma é igual a n.
  //Se for igual a n, é impresso os números da soma, se nenhum dos casos for igual, é impresso 'impossível'.
  vector<int> primes, ans;
  bool ctrl = false;
  findSmallerPrimes(n, primes);

  //essa parte analisa as diversas combinações de 4 em 4 no vetor de primos, caso encontre a primeira resposta, ele diretamente imprime ela.
  for(long unsigned int i = 0; i < primes.size(); i++){
    for(long unsigned int j = 0; j < primes.size(); j++){
      for(long unsigned int k = 0; k < primes.size(); k++){
        for(long unsigned int l = 0; l < primes.size(); l++){
          if((primes[i]+primes[j]+primes[k]+primes[l]) == n){
            ans.push_back(primes[i]);
            ans.push_back(primes[j]);
            ans.push_back(primes[k]);
            ans.push_back(primes[l]);
            ctrl = true;
            goto end;
          }
        }
      }
    }
  }

  end:
    if(ctrl){
      return ans;
    }else{
      ans.push_back(-1);
      return ans;
    }
  
}

void testOne(){
  int ans[4] = {1, 1, 1, 1};
  
  vector<int> test = findSummationFourPrimes(4);
  for(long unsigned int i = 0; i < test.size(); i++){
    assert(ans[i] == test[i]);
  }
  cout<<"Test 01: OK!"<<endl;
}

void testTwo(){
  int ans[4] = {1, 1, 5, 73};
  
  vector<int> test = findSummationFourPrimes(80);
  for(long unsigned int i = 0; i < test.size(); i++){
    assert(ans[i] == test[i]);
  }
  cout<<"Test 02: OK!"<<endl;
}

void testThree(){
  int ans[4] = {1, 2, 13, 109};
  
  vector<int> test = findSummationFourPrimes(125);
  for(long unsigned int i = 0; i < test.size(); i++){
    assert(ans[i] == test[i]);
  }
  cout<<"Test 03: OK!"<<endl;
}

void testFour(){
  int ans[4] = {1, 1, 2, 1481};
  
  vector<int> test = findSummationFourPrimes(1485);
  for(long unsigned int i = 0; i < test.size(); i++){
    assert(ans[i] == test[i]);
  }
  cout<<"Test 04: OK!"<<endl;
}

int main(){
  testOne();
  testTwo();
  testThree();
  testFour();
  return 0;
}
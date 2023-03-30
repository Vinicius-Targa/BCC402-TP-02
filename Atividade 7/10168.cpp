// 10168 - Summation of Four Primes

/* Euler proved in one of his classic theorems that prime numbers are infinite in number. But can every
number be expressed as a summation of four positive primes? The definition of prime number for this problem is
“A prime number is a positive number which has exactly two distinct integer factors”. As for example
37 is prime as it has exactly two distinct integer factors 37 and 1. */

#include <iostream>
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

int main() {
  vector<int> ans;
  int n;
  
  //loop recebendo as entradas contínuas sem critério de parada.
  while(cin >> n){
    ans = findSummationFourPrimes(n);

    if(ans[0] == -1){
      cout<<"Impossible"<<endl;
    } else {
      cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<endl;
    }
    
    ans.clear();
  }

  return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>

static const int M = 10000;

class exercise{
  private:
  public:
    exercise(){};

    void run(int A[M],int B[M],int C[M],int D[M],int E[M]){
      for(int i=0;i<M;i++){
        A[i] = B[i]*C[i] - D[i]*E[i];
      }
    }

};



int main(){

  srand(time(NULL));
	
  exercise test;

  int A[M],B[M],C[M],D[M],E[M];

  for(int i=0;i<M;i++){
    B[i] = rand() % 20;
    C[i] = rand() % 20;
    D[i] = rand() % 20;
    E[i] = rand() % 20;
  }

  test.run(A,B,C,D,E);

  return 0;
}

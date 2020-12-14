#include <iostream>
#include <cstdlib>
#include <ctime>

static const int N = 5;
static const int M = 10;

//Function that returns the prosseced img
//void kernel(short img[N][M], short out[N][M]){
//  short p1,p2,p3,p4,p5;
//  ROW:for(int i;i<N;i++){
//    COL:for(int j;j<M;j++){
//      p1 = (j > 1) ? img[i][j-2]:0;
//      p2 = (j > 0) ? img[i][j-1]:0;
//      p3 = img[i][j];
//      p4 = (j < M-1) ? img[i][j+1]:0;
//      p5 = (j < M-2) ? img[i][j+2]:0;
//
//      out[i][j] = (p1 + p2 + p3 + p4 + p5)/5;
//    }
//  }
//}

//Class that has the function run that returns the prosseced img
class image{
  private:
    short int p[5];
  public:
    image(){};

    //Run function without memeory optimization 
    void run(short img[N][M],short out[N][M]){ 
      ROW:for(int i=0;i<N;i++){
	COL:for(int j=0;j<M;j++){
          p[0] = (j > 1) ? img[i][j-2]:0;
          p[1] = (j > 0) ? img[i][j-1]:0;
          p[2] = img[i][j];
          p[3] = (j < M-1) ? img[i][j+1]:0;
          p[4] = (j < M-2) ? img[i][j+2]:0;

          out[i][j] = (p[0] + p[1] + p[2] + p[3] + p[4]) / 5;	
	}
      }
    }

    //Run function with memery optimization
    void run_opt(short img[N][M],short out[N][M]){
      ROW:for(int k=0;k<N;k++){	
	COL:for(int l=0;l<M;l++){
	    if(l == 0){
	      p[0] = 0;
	      p[1] = 0;
	      p[2] = img[k][l];
	      p[3] = img[k][l+1];
	      p[4] = img[k][l+2];
	    }else if(l > 0 && l < M-2){
	      p[0] = p[1];
	      p[1] = p[2];
	      p[2] = p[3];
	      p[3] = p[4];
	      p[4] = img[k][l+2];
	    }else{
	      p[0] = p[1];
	      p[1] = p[2];
	      p[2] = p[3];
	      p[3] = p[4];
	      p[4] = 0;
	    }

	    out[k][l] = (p[0] + p[1] + p[2] + p[3] + p[4]) / 5;
	  }
	}
    }
    
};


int main(){

  srand(time(NULL));
  
  //Initiation of the variables and the classes
  int i,j;

  image image;
  
  short out[N][M];
  short img[N][M];

  std::cout << "******************** IMG ********************" << std::endl; 
  //Seting the values of the img 
  for(i = 0;i<N;i++){
    for(j = 0;j<M;j++){
      img[i][j] = rand() % 10; 
      std::cout << img[i][j] << ",";
    }
    std::cout << "\n";
  }

  //Execution of the function 
  image.run(img,out);
 
  std::cout << "******************** OUT ********************" << std::endl; 
  //Printing the results
  for(i = 0;i<N;i++){
    for(j = 0;j<M;j++){ 
      std::cout << out[i][j] << ",";
    }
    std::cout << "\n";
  }

  return 0;

}



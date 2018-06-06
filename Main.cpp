#include <iostream>
#include <iomanip>
using namespace std;

// X and Y dimension size
const int x_range = 50;
const int y_range = 1;
//Initialize array
double SPACE[x_range][y_range];
double DIFF_1[x_range][y_range];
double DIFF_2[x_range][y_range];

//dimension size and timestep
double x_size = 1;
double y_size = 1;
double timestep = 0.01;
int numT = 10000;
int n = 4;
int m = 5;
double differential(double a, double b)
{
  return ((b-a)/x_size);
}

int main()
{
  //Initialize SPACE
  int i=0;
  for (i=0;i<x_range;i++)
  {
      SPACE[i][y_range]=0;
      DIFF_1[i][y_range]=0;
      DIFF_2[i][y_range]=0;
  }

  SPACE[0][1] = n;
  SPACE[49][1] = m;

  for(int j=0;j<numT;j++)
  {
    //First differential
    for (i=0;i<x_range;i++)
    {
      DIFF_1[i][y_range]=differential(SPACE[i][y_range],SPACE[i+1][y_range]);
    }
    //Second differential
    for (i=0;i<(x_range-1);i++)
    {
      DIFF_2[i][y_range]=differential(DIFF_1[i][y_range],DIFF_1[i+1][y_range]);
    }
    for (i=0;i<x_range;i++)
    {
      SPACE[i][y_range] += timestep*DIFF_2[i-1][y_range];
    }
    SPACE[0][1] = n;
    SPACE[49][1] = m;
  }
  for (i=0;i<x_range;i++)
  {
    std::cout << std::setprecision(4);
    std::cout<< SPACE[i][y_range]<<" "<<endl;
  }
}

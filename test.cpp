#include<iostream>
#include<cstring>

using namespace std;

const int HGT = 4;
const int WID = 4;

int main()
{
  char pic[HGT][WID];
  int line = 4;
  std::cin.getline(pic[HGT][WID],line);

  std::cout << pic[HGT][WID];


  return 0;
}

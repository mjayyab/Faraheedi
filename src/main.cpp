#include <cstdlib>
#include <string>
#include <map>
#include <list>
#include <iostream>
#include <fstream>
using namespace std;

#include <transliterator.h>
using namespace Faraheedi;

int main(int argc, char **argv)
{
  ifstream fin("config/translit.map");
  if (!fin){
    cerr << "Cannot find translit.map" << endl;
    exit(1);
  }

  Transliterator tl(fin);

}

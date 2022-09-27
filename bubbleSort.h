#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <vector>
#include "header.h"
#include "Barco.h"
using namespace std;

void bubbleSort(vector<Barco *> &v){
  for (int i = 0; i < v.size(); i++){
    bool flag = true;
    for (int j = 0; j < v.size() - 1 - i; j++){
      if (*v[j] > *v[j + 1]){
        swap(v, j, j + 1);
        flag = false;
      }
    }
    if (flag)
      break;
  }
}

#endif

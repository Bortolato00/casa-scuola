#include <iostream>
#define N 100
using namespace std;

void selection_sort(int v[], int dim);

int main(){
    int a[N] = {-2,3,4,1,0,8,6,5,1,4,3,0};
    int dim = 12;
    selection_sort(a, dim);
    cout << endl;
    return 0;
}

void selection_sort(int v[], int dim)
{
    int comodo, ind_min;
    for(int i = 0; i < dim-1; i++){
        ind_min = i;
        for (int j = i+1; j < dim; j++){
            if (v[ind_min] > v[j]){
                ind_min = j;
            }
        }
        comodo=v[i];
        v[i]=v[ind_min];
        v[ind_min]= comodo;
    }
}


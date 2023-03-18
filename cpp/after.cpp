#include<iostream>
#include<algorithm>
using namespace std;

void before(int** x, int** y, int** z, int N){
    for (int i = 0; i < N; ++i)
	for (int j = 0; j < N; ++j) {
        int r = 0;
		for (int k = 0; k < N; ++k) r = r + y[i][k] * z[k][j];
        x[i][j] = r;
    }
}

void after(int** x, int** y, int** z, int N, int B){ // B是分块因子
    for (int jj = 0; jj < N; jj = jj + B)
        for (int kk = 0; kk < N; kk = kk + B)
            for (int i = 0; i < N; i = i + 1)
                for (int j = jj; j < min(jj + B - 1, N); j = j + 1) {    
                    int r = 0;
                    for (int k = kk; k < min(kk + B - 1, N); k = k + 1) 
                        r = r + y[i][k] * z[k][j];
                    x[i][j] = x[i][j] + r;
                }
}



int main()
{

}
#include <iostream>
using namespace std;

int main()
{
    int p[5] = {0,1,2,5,6};
    int wt[5] = {0,2,3,4,5};
    int m = 8; int n = 4;
    int K[n+1][m+1];
    for(int i=0; i <= n; i++){
        for(int w=0; w <= m; w++){
            if(i == 0 || w == 0)
                K[i][w] = 0;
            else if(wt[i] <= w){
                K[i][w] = max(p[i]+K[i-1][w-wt[i]], K[i-1][w]);
            }
            else{
                K[i][w] = K[i-1][w];
            }
            cout << K[i][w] << " ";
        }
        cout << '\n';
    }
    ;
    int op = K[n][m];
    cout << "\nOptimal solution is : " << op << "\n\n";
    int i=n,j=m;
    while(i>0 && j>=0) {
        if(K[i][j] == K[i-1][j]) {
            cout << "Object " << i << " is not included "<< "\n";
            i--;
        } else {
            cout << "Object " << i << " is included \n";
            j=j-wt[i];
            i--;
        }
    }
}

#include <iostream>
#include <string.h>
using namespace std;

void longsub(char* A, char* B, int m, int n)
{
    int lcs[m+1][n+1];
    for(int i=0; i <= m; i++){
        for(int j=0; j <= n; j++){
            if(i==0 || j==0)
                lcs[i][j] = 0;
            else if(A[i-1] == B[j-1])
                lcs[i][j] = lcs[i-1][j-1] + 1;
            else{
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }
    cout << lcs[m][n] << endl;
    int index = lcs[m][n];

    char L[index + 1];
    L[index] = '\0';
    int i = m; int j = n;
    while(i > 0 && j > 0){
        if(A[i-1] == B[j-1]){
            L[index - 1] = A[i-1];
            i--; j--; index--;
        }
        else if(lcs[i-1][j] > lcs[i][j-1]){
            i--;
        }
        else
            j--;
    }
    cout << "Longest Common Subsequence: " << L << endl;

}

int main()
{
    char A[20];
    char B[20];
    cin >> A >> B;
    int n = strlen(A);
    int m = strlen(B);
    longsub(A, B, n, m);
    return 0;
}

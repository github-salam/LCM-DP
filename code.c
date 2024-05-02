#include <stdio.h>
#include <string.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int LCS(char *s1, char *s2, int m, int n){
    int T[m+1][n+1];
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0) T[i][j] = 0;
            else if(s1[i-1] == s2[j-1]) T[i][j] = T[i-1][j-1] + 1; 
            else T[i][j] = max(T[i][j-1], T[i-1][j]);
        }
    }
    return T[m][n];
}

int main(){

    char s1[] = {'P','R','E','S','I','D','E','N','T'};
    char s2[] = {'P','R','O','V','I','D','E','N','C','E'};
    int m = strlen(s1);
    int n= strlen(s2);
    int longComSub = LCS(s1,s2,m,n);
    printf("result = %d\n", longComSub);

    return 0;
}
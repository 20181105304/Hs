#include<stdio.h>

int main()
{
    int n,i,t=0,q=0;
   
    scanf("%d",&n);
    int arr[n+1];
    
    for (i=1; i<=n; i++) {
        arr[i]=0;
    }
    
    
        if(n!=1){
            for (i=1; i<=n; i++) {
                if(arr[i]==0){
                    q++;
                }
                if(arr[i]==0&&(q%3)==0){
                    arr[i]=1;
                    t++;
                    if(t==n-1){
                        break;
                    }
                }
                if(i==n){
                    i=0;
                }
            }
        }
    for(i=1; i<=n; i++){
        if(arr[i]==0){
            printf("%d",i);
            break;
        }
    }
    
    return 0;
}


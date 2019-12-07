#include <stdio.h>
#include <math.h>

int search( int n );

int main()
{
    int number;

    scanf("%d",&number);
    printf("count=%d\n",search(number));
		
    return 0;
}

int search( int n )
{
	int i,j,count=0,a[4],cot=0;
	int num;
	for(i=101; i<=n; i++){
		num=i;
		for(j=0; j<3; j++){
			a[j]=num%10;
			num/=10;
		}
		
		for(j=0; j<3; j++){
			for(int k=0; k<3; k++){
				if(a[j]==a[k] && j!=k){
					count++;
				}
			}
		}
		
		if(count==2 && sqrt(i) == (int)sqrt(i)){
			cot++;
		}
		count=0;
	}
	
	return cot;
}

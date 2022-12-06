#include<stdio.h>
#include<math.h>

int akrmn(int x,int y){
	if(x == 0){
		return y+1;
	}
	if(y == 0){
		return akrmn(x-1,1);
	}
	else{
		return akrmn(x-1, akrmn(x,y-1));
	}
}

int main(){
	int a,x, y = 1;
	for(x = 0; x<=3; x++){
		a = akrmn(x,y);
		printf("For x = %d, y = 1, the value is %d\n",x,a);
	}
	printf("\n");
	return 0;
}

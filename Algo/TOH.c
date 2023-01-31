#include<stdio.h>

void hanoi(int n,char s, char d, char i){
	if(n == 1){
		printf("%c -> %c\n",s,d);
	}
	else {
		hanoi(n-1,s,i,d);
		printf("%c -> %c\n",s,d);
		hanoi(n-1,i,d,s);
	}
}

int main(){
	hanoi(3,'A','C','B');
	return 0;
}

#include<stdio.h>


int findComplement(int num) {
        unsigned mask = ~0;
		printf("mask= %d\n",mask);
        while (num & mask) mask <<= 1;
        return ~mask & ~num;
}

int main(){
	printf("%d\n",findComplement(5));
}


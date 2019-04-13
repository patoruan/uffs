#include <stdio.h>
#include <stdlib.h>
/* To make this code calculate and display the value correctly it is necessary to use arbitrary precision arithmetic,
 as I am just redoing some codes and I do not remember if the teacher demanded this when I studied the subject a few years ago, 
 I will not do it at this moment*/

int ePrimo(long long int x);

int main(){
	long long int ans=1, i;
	for(i=92; i <= 1478; i++)
		if(ePrimo(i))
			printf("%lld, ", i);
	printf("%lld\n", ans);
	
	return 0;
}

int ePrimo(long long int x){
	long long int i, cnt;
	for(i = 1, cnt=0; i <= x; i++)
		if(x%i==0)
			cnt++;
	if(cnt == 2)
		return 1;
	return 0;
}
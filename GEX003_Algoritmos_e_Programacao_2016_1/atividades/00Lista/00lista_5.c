#include <stdio.h>

int main(){
	int ans, v;
	double i;
	for(i=0, ans=0; 1; i=i+1){
		scanf("%d", &v);
		if(v<0)	break;
		ans+=v;
	}printf("%lf\n", (ans/i));

	return 0;
}
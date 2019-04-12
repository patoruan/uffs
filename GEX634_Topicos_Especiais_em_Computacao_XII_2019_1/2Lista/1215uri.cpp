#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <string>
#include <set>

using namespace std;

int main(){
	int i, j;
	char line[321], aux[321];
	memset(aux, '\0', 321);
	set<string> dictionary;
	
	while(scanf("%s", line) != EOF){
		//printf("line = %s\n", line);
		memset(aux, '\0', 321);
		for(i = 0, j = 0; i <= strlen(line) ; i++){//
			if(isalpha(line[i]) && line[i] != ' ' && line[i] != '\0'){
				aux[j] = line[i] <= 90 ? line[i]+=32 : line[i];//dwnLttr
				j++;
			}else if(isalpha(line[i]) == 0 && strlen(aux) > 0){
				//printf("FLAG word = %s\n", aux);
				//printf("FLAG = %c\n", line[i]);
				dictionary.insert(aux);
				memset(aux, '\0', 321);
				j = 0;
			}
		}
	} 
    for (auto it = dictionary.begin(); it != dictionary.end(); it++) 
        cout << *it << "\n"; 

	return 0;
}

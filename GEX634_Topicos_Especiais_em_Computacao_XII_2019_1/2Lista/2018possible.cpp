#include <stdio.h>
#include <stdlib.h>
#include <string.h> //########################################################################################################
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iterator>

using namespace std;

int main(){
	map<std::string, pair<int, pair<int, int>>> countryMedals;
	map<std::string, pair<int, pair<int, int>>>::iterator it; //Iterator
	char countryName[11234];int i=0, n;
	while(scanf("%[^\n]", countryName) != EOF){
		getchar();
		//printf("%s = %d\n", countryName, strlen(countryName));
		//Gold medal
		scanf("%[^\n]", countryName);
		getchar();
		//printf("%s = %d\n", countryName, strlen(countryName));
		it = countryMedals.find(countryName);
		if(it != countryMedals.end()){//If this country is in the map.
			countryMedals[countryName].first += 1; //Increment a gold medal in country.
		}else{//If country not is in the map.
			countryMedals.insert(pair<string, pair<int, pair<int, int>>>(countryName, make_pair(1, make_pair(0, 0))));
		}
		
		//Silver medal:
		scanf("%[^\n]", countryName);
		getchar();
		//printf("%s = %d\n", countryName, strlen(countryName));
		it = countryMedals.find(countryName);
		if(it != countryMedals.end()){//If this country is in the map.
			countryMedals[countryName].second.first += 1; //Increment a silver medal in country.
		}else{//If country not is in the map.
			countryMedals.insert(pair<string, pair<int, pair<int, int>>>(countryName, make_pair(0, make_pair(1, 0))));
		}

		//Cooper medal:
		scanf("%[^\n]", countryName);
		getchar();
		//printf("%s = %d\n", countryName, strlen(countryName));
		it = countryMedals.find(countryName);
		if(it != countryMedals.end()){//If this country is in the map.
			countryMedals[countryName].second.second += 1; //Increment a cooper medal in country.
		}else{//If country not is in the map.
			countryMedals.insert(pair<string, pair<int, pair<int, int>>>(countryName, make_pair(0, make_pair(0, 1))));
		}
		i+=3;
	}
	printf("Quadro de Medalhas\n");
	//Print the tree
	for (it = countryMedals.begin(); it != countryMedals.end(); it++)
		cout << it->first << " " << it->second.first << " " << it->second.second.first << " " << it->second.second.second << endl;
		//cout << it->first << " " << it->second.first << " " << it->second.second << endl;
	set<pair<std::string, pair<int, pair<int, int>>>> countryGolds;
	set<pair<std::string, pair<int, pair<int, int>>>>::iterator itGold;
	for(it = countryMedals.begin(); it != countryMedals.end(); it++){
		countryGolds.insert(make_pair(it->first, make_pair(it->second.first, make_pair(it->second.second.first, it->second.second.second))));
	}
	printf("\n\n\n");
	for(itGold = countryGolds.begin(); itGold != countryGolds.end(); itGold++)
		cout << itGold->first << " " << itGold->second.first << " " << itGold->second.second.first << " " << itGold->second.second.second << endl;
	return 0;
}
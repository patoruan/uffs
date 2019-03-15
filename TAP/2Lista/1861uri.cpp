#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <iterator>
#include <string>

using namespace std;

int main(){
	char murderer[12], murdered[12];
	map<string, pair<int, int>> murdererTree; //String == name, int == kill count, int == 1 live || 0 murdered.
	map<string,pair<int,int>>::iterator it0, it1; // Iterator to search on map.

	while(scanf("%s %s", murderer, murdered) != EOF){
		it0 = murdererTree.find(murderer); it1 = murdererTree.find(murdered);

		if(it0 != murdererTree.end()){//If the new murderer is in the list
			murdererTree[murderer].first += 1; //Increase kill count
		}else{
			murdererTree.insert(pair<string,pair<int,int>>(murderer, make_pair(1, 1))); //Allocate the murderer in tree
		}
	
		if(it1 != murdererTree.end()){
			murdererTree[murdered].second = 0;//Attributes 0 to means death.
		}else{
			murdererTree.insert(pair<string,pair<int,int>>(murdered, make_pair(0, 0))); /*Allocate the murdered who not appears murderer someone,
			 before be murdered in tree*/	
		}
	}

	printf("HALL OF MURDERERS\n");
	//Print the tree
	for (it0 = murdererTree.begin(); it0 != murdererTree.end(); it0++)
		if(it0->second.second == 1)
			cout << it0->first << " " << it0->second.first << endl;

	return 0;
}
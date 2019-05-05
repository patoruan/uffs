#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef tuple<int,int,int,int> tiiii;
priority_queue<tiiii> pq, auxPq;// int dia*multa para a priority, int Dia chegada, Dias para treino, multa por dias não treinado em espera

int main(){
	tiiii aux;
	long long int t, f, tot = 0, totDias=1, dEmtreino=0;

	while(cin >> t >> f){
		pq.push(make_tuple((t*f), totDias, t, f));
		auxPq.push(make_tuple((t*f), totDias, t, f));
		if(dEmtreino==0){
			aux=pq.top();pq.pop();// Coloca o valor da fila de prioridade em uma tupla auxiliar e remove da lista de prioridade
			tot += ( (totDias-get<1>(aux))*get<3>(aux) );// Aumenta o total da multa

			cout << "\n\n";
			cout << "Dia Atual: " << totDias << " - Dias chegada: " << get<1>(aux) << " - Dias de treino: " << get<2>(aux) << " - Multa: " << get<3>(aux) << " - Total: " << tot << endl;
			cout << "\n\n";

			dEmtreino=get<2>(aux);//Atualiza os dias de espera
		}totDias++;dEmtreino--;cout << "Total de dias :" << totDias << " - Dias em treino: " << dEmtreino << " - t: " << t << " - f: " << f << endl;
	}

	cout << "\n\n";
	while(!auxPq.empty()){
		aux=auxPq.top();auxPq.pop();
		cout << "Dia chegada: " << get<1>(aux) << " - Dias de treino: " << get<2>(aux) << " - Multa: " << get<3>(aux) << endl; 
	}
	cout << "\n\n";

	cout << "---------------------------------------------" << endl;
	
	while(!pq.empty()){
		if(dEmtreino==0){
			aux=pq.top();pq.pop();// Coloca o valor da fila de prioridade em uma tupla auxiliar e remove da lista de prioridade
			tot += ( (totDias-get<1>(aux))*get<3>(aux) );// Aumenta o total da multa

			cout << "\n\n";
			cout << "Dia Atual: " << totDias << " - Dias chegada: " << get<1>(aux) << " - Dias de treino: " << get<2>(aux) << " - Multa: " << get<3>(aux) << " - Total: " << tot << endl;
			cout << "\n\n";

			dEmtreino=get<2>(aux);//Atualiza os dias de espera
		}totDias++;dEmtreino--;cout << "Total de dias :" << totDias << " - Dias em treino: " << dEmtreino << endl;
	}
	cout << "Total de dias: " << totDias << endl;

	cout << tot << endl;
	return 0;
}
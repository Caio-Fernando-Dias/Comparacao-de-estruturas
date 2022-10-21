#include "binary/tree.hpp"
#include "binary/fila.hpp"
#include "avl/avl.hpp"
#include "rb/rb.hpp"

#include <unordered_map>
#include <map>
#include <vector>
#include <chrono>
#include <algorithm>
#include <set>

using namespace std::chrono;


int main(){

	ifstream arq;
	string aux;
	vector<string> pesquisa_float;

	arq.open("search.txt");
	if(arq.is_open()){
		while(!arq.eof()){
			getline(arq, aux);
			pesquisa_float.push_back(aux);
		}
	}
	arq.close();

	steady_clock::time_point t1 = steady_clock::now();
		steady_clock::time_point t2;

	duration <double> tempo_gastoBinary = duration_cast<duration<double>>(t1 - t1);
	duration <double> tempo_gastoAVL = duration_cast<duration<double>>(t1 - t1);
	duration <double> tempo_gastoRB = duration_cast<duration<double>>(t1 - t1);
	duration <double> tempo_gastoUnordered_map = duration_cast<duration<double>>(t1 - t1);
	duration <double> tempo_gastoMap = duration_cast<duration<double>>(t1 - t1);
	duration <double> tempo_gastoVector = duration_cast<duration<double>>(t1 - t1);

	//Insert Binary

	Tree_binary *raiz_binary = CreateTree_binary();
	Tree_binary *aux_binary = CreateTree_binary();
	Record_binary r_binary;

	t1 = steady_clock::now();
	arq.open("500000.txt");
	while(!arq.eof()){
		getline(arq, aux);
		r_binary.key = aux;
		r_binary.value = 1;
		insertTree_binary(&raiz_binary, r_binary);
	}
	arq.close();
	t2 = steady_clock::now();
	tempo_gastoBinary += duration_cast<duration<double>>(t2 - t1);

	//Insert AVL

	Tree_AVL *raiz_avl = CreateTree_AVL();
	Tree_AVL *aux_avl = CreateTree_AVL();
	Record_AVL r_avl;

	t1 = steady_clock::now();
	arq.open("500000.txt");
	while(!arq.eof()){
		getline(arq, aux);
		r_avl.key = aux;
		r_avl.value = 1;
		insertTree_AVL(&raiz_avl, r_avl);
	}
	arq.close();
	t2 = steady_clock::now();
	tempo_gastoAVL += duration_cast<duration<double>>(t2 - t1);

	//Insert RB

	Tree_RB *raiz_rb = CreateTree_RB();
	Tree_RB *aux_rb = CreateTree_RB();
	Record_RB r_rb;

	t1 = steady_clock::now();
	arq.open("500000.txt");
	while(!arq.eof()){
		getline(arq, aux);
		r_rb.key = aux;
		insertTree_RB(&raiz_rb, &raiz_rb, &raiz_rb, r_rb);
	}
	arq.close();
	t2 = steady_clock::now();
	tempo_gastoRB += duration_cast<duration<double>>(t2 - t1);

	//Insert Unordered_map

	unordered_map<string, int> hash;
	vector<string> arq_entrada;

	arq.open("500000.txt");
	if(arq.is_open()){
		while(!arq.eof()){
			getline(arq, aux);
			arq_entrada.push_back(aux);
		}
	}
	arq.close();

	t1 = steady_clock::now();
	for(long unsigned int i = 0; i < arq_entrada.size(); i++){
		hash.emplace(arq_entrada[i], 1);
	}
	t2 = steady_clock::now();
	tempo_gastoUnordered_map += duration_cast<duration<double>>(t2 - t1);

	//Insert Map

	map<string, int> map;

	t1 = steady_clock::now();
	for(long unsigned int i = 0; i < arq_entrada.size(); i++){
		map.insert(pair<string,int>(arq_entrada[i], i));
	}
	t2 = steady_clock::now();
	tempo_gastoMap += duration_cast<duration<double>>(t2 - t1);

	//Insert Vector

	vector<string> vector;

	t1 = steady_clock::now();
	arq.open("500000.txt");
	if(arq.is_open()){
		while(!arq.eof()){
			getline(arq, aux);
			vector.push_back(aux);
		}
	}
	arq.close();
	t2 = steady_clock::now();
	tempo_gastoVector += duration_cast<duration<double>>(t2 - t1);

	cout << endl;
	cout << " Insert in binary: " << tempo_gastoBinary.count() << endl;
	cout << " Insert in AVL: " << tempo_gastoAVL.count() << endl;
	cout << " Insert in RB: " << tempo_gastoRB.count() << endl;
	cout << " Insert in unordered_map: " << tempo_gastoUnordered_map.count() << endl;
	cout << " Insert in map: " << tempo_gastoMap.count() << endl;
	cout << " Insert in vector: " << tempo_gastoVector.count() << endl;
	cout << endl;

	tempo_gastoBinary = duration_cast<duration<double>>(t1 - t1);
	tempo_gastoAVL = duration_cast<duration<double>>(t1 - t1);
	tempo_gastoRB = duration_cast<duration<double>>(t1 - t1);
	tempo_gastoUnordered_map = duration_cast<duration<double>>(t1 - t1);
	tempo_gastoMap = duration_cast<duration<double>>(t1 - t1);
	tempo_gastoVector = duration_cast<duration<double>>(t1 - t1);

	//Search Binary

	t1 = steady_clock::now();
	for(long unsigned int i = 0; i < pesquisa_float.size(); i++){
		r_binary.key = pesquisa_float.at(i);
		pesquisa_binary(&raiz_binary, &aux_binary, r_binary);
	}
	t2 = steady_clock::now();
	tempo_gastoBinary += duration_cast<duration<double>>(t2 - t1);

	//Search AVL

	t1 = steady_clock::now();
	for(long unsigned int i = 0; i < pesquisa_float.size(); i++){
		r_avl.key = pesquisa_float.at(i);
		pesquisa_AVL(&raiz_avl, &aux_avl, r_avl);
	}
	t2 = steady_clock::now();
	tempo_gastoAVL += duration_cast<duration<double>>(t2 - t1);

	//Search RB

	t1 = steady_clock::now();
	for(long unsigned int i = 0; i < pesquisa_float.size(); i++){
		r_rb.key = pesquisa_float.at(i);
		pesquisa_RB(&raiz_rb, &aux_rb, r_rb);
	}
	t2 = steady_clock::now();
	tempo_gastoRB += duration_cast<duration<double>>(t2 - t1);

    //Search Unordered_map

	t1 = steady_clock::now();
    for(long unsigned int i = 0; i < pesquisa_float.size(); i++){
    	hash.find(pesquisa_float.at(i));
    }
    t2 = steady_clock::now();
    tempo_gastoUnordered_map += duration_cast<duration<double>>(t2 - t1);


	//Search Map 

    t1 = steady_clock::now();
	for(long unsigned int i = 0; i < pesquisa_float.size(); i++){
		map.find(pesquisa_float.at(i));
	}
	t2 = steady_clock::now();
	tempo_gastoMap += duration_cast<duration<double>>(t2 - t1);

	//Search Vector

	t1 = steady_clock::now();
	sort(vector.begin(), vector.end());
	for(long unsigned int i = 0; i < pesquisa_float.size(); i++){
		if(binary_search(vector.begin(), vector.end(), pesquisa_float.at(i))){
			//cout << "Found!!!" << endl;
		}else{
			//cout << "Not found!!!" << endl;
		}
	}
	t2 = steady_clock::now();
	tempo_gastoVector +=  duration_cast<duration<double>>(t2 - t1);

	cout << endl;
	cout << " Search in binary: " << tempo_gastoBinary.count() << endl;
	cout << " Search in AVL: " << tempo_gastoAVL.count() << endl;
	cout << " Search in RB: " << tempo_gastoRB.count() << endl;
	cout << " Search in unordered_map: " << tempo_gastoUnordered_map.count() << endl;
	cout << " Search in map: " << tempo_gastoMap.count() << endl;
	cout << " Search in vector: " << tempo_gastoVector.count() << endl;
	cout << endl;

	tempo_gastoBinary = duration_cast<duration<double>>(t1 - t1);
	tempo_gastoAVL = duration_cast<duration<double>>(t1 - t1);
	tempo_gastoRB = duration_cast<duration<double>>(t1 - t1);
	tempo_gastoUnordered_map = duration_cast<duration<double>>(t1 - t1);
	tempo_gastoMap = duration_cast<duration<double>>(t1 - t1);
	tempo_gastoVector = duration_cast<duration<double>>(t1 - t1);

	//Remove Binary

	t1 = steady_clock::now();
	for(long unsigned int i = 0; i < pesquisa_float.size(); i++){
			r_binary.key = pesquisa_float.at(i);
			removeTree_binary(&raiz_binary, r_binary);
	}
	t2 = steady_clock::now();
	tempo_gastoBinary += duration_cast<duration<double>>(t2 - t1);

	//Remove AVL

	t1 = steady_clock::now();
	for(long unsigned int i = 0; i < pesquisa_float.size(); i++){
			r_avl.key = pesquisa_float.at(i);
			removeTree_AVL(&raiz_avl, &raiz_avl, r_avl);
	}
	t2 = steady_clock::now();
	tempo_gastoAVL += duration_cast<duration<double>>(t2 - t1);

	//Remove RB

	t1 = steady_clock::now();
	for(long unsigned int i = 0; i < pesquisa_float.size(); i++){
		r_rb.key = pesquisa_float.at(i);
		//removeRB(&raiz_rb, &raiz_rb, r_rb);
	}
	t2 = steady_clock::now();
	tempo_gastoRB += duration_cast<duration<double>>(t2 - t1);

    //Remove Unordered_map

	t1 = steady_clock::now();
    for(long unsigned int i = 0; i < pesquisa_float.size(); i++){
    	if(hash.find(pesquisa_float.at(i)) == hash.end()){
    		//cout << "[ERROR]: Not found!!!" << endl;
    	}else{
    		hash.erase(pesquisa_float.at(i));
    	}
    }
    t2 = steady_clock::now();
    tempo_gastoUnordered_map += duration_cast<duration<double>>(t2 - t1);

	//Remove Map 

    t1 = steady_clock::now();
	for(long unsigned int i = 0; i < pesquisa_float.size(); i++){
		if(map.find(pesquisa_float.at(i)) == map.end()){
			//cout << "[ERROR]: Not found!!!" << endl;
		}else{
			map.erase(pesquisa_float.at(i));
		}
	}
	t2 = steady_clock::now();
	tempo_gastoMap += duration_cast<duration<double>>(t2 - t1);

	//Remove Vector

	t1 = steady_clock::now();
	for(long unsigned int i = 0; i < pesquisa_float.size(); i++){
		if(binary_search(vector.begin(), vector.end(), pesquisa_float.at(i))){
			lower_bound (vector.begin(), vector.end(), pesquisa_float.at(i));
		}
	}
	t2 = steady_clock::now();
	tempo_gastoVector += duration_cast<duration<double>>(t2 - t1);

	cout << endl;
	cout << " Remove in binary: " << tempo_gastoBinary.count() << endl;
	cout << " Remove in AVL: " << tempo_gastoAVL.count() << endl;
	cout << " Remove in RB: [ERRO] " << tempo_gastoRB.count() << endl;
	cout << " Remove in unordered_map: " << tempo_gastoUnordered_map.count() << endl;
	cout << " Remove in map: " << tempo_gastoMap.count() << endl;
	cout << " Remove in vector: " << tempo_gastoVector.count() << endl;
	cout << endl;

	return 0;
}

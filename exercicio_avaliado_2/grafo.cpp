/*
  
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * classe que modela um grafo. Possibilita encontrar recorrencia de vertices e arestas e o
  * numero N de termos consecutivos mais utilizados.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>
#include <string>
#include "grafo.h"
#include "texto.h"

using namespace std;

Grafo::Grafo(string nomeArquivo){
    Texto texto(nomeArquivo);
    palavras = texto.getPalavras();
    stringTexto = texto.getTexto();
    montarVertices();
    montarArestas();
}


int Grafo::retornarRecorrencia(string palavra){

    int contadorPalavra = 0;

    for (string palavraArmazenada: palavras){
        if (palavraArmazenada == palavra){
            contadorPalavra++;
        }
    }

    return contadorPalavra;
}

void Grafo::montarArestas(){
    string palavraAnterior;
    string proximaPalavra;
    //itera sobre o vetor de palavras e monta as arestas
    for(int index = 0; index < int(palavras.size()); index++ ){
        //verifica se a sequencia de palavras e valida (sem pontuacao entre a sequencia)
        if(find(begin(caracteres), end(caracteres), palavras[index]) == end(caracteres)){
            palavraAnterior = palavras[index];
        }
        else{
            continue;
        }
        
        if ((index + 1) < int(palavras.size())){
            proximaPalavra = palavras[index + 1];
            if(find(begin(caracteres), end(caracteres), proximaPalavra) == end(caracteres)){
                Vertice verticeAnterior;
                Vertice proximoVertice;
                verticeAnterior.setPalavra(palavraAnterior);
                verticeAnterior.setRecorrencia(retornarRecorrencia(palavraAnterior));
                proximoVertice.setPalavra(proximaPalavra);
                proximoVertice.setRecorrencia(retornarRecorrencia(proximaPalavra));

                Aresta aresta(verticeAnterior, proximoVertice);
                arestas.push_back(aresta);
            }
        }
    }
    //define a recorrencia de cada aresta
    for(int index = 0; index < int(arestas.size()); index++){
        arestas[index].setRecorrencia(recorrenciaAresta(arestas[index]));
    }
}

void Grafo::montarVertices(){
    Vertice vertice;
    //monta um vertice pra cada palavra valida
    for(string palavra: palavras){
        if(find(begin(caracteres), end(caracteres), palavra) == end(caracteres)){
            vertice.setPalavra(palavra);
            vertice.setRecorrencia(retornarRecorrencia(palavra));
            vertices.push_back(vertice);
        }
    }    
}

void Grafo::palavrasMaisUtilizadas(){

    vector<Vertice> palavrasMaisUtilizadas;
    //organiza em ordem desc de recorrencia
    palavrasMaisUtilizadas = vertices; 
    sort(
        palavrasMaisUtilizadas.begin(),
        palavrasMaisUtilizadas.end(),
        [](Vertice a, Vertice b){return a.getRecorrencia() > b.getRecorrencia();}
    );
    
    // remover duplicatas. So existe recorrencia > 1 se temos palavras repetidas
    //as palavras repitidas sao removidas antes da exibicao
    vector<Vertice> copia;
    copia.push_back(palavrasMaisUtilizadas[0]);
    bool existe = false;
    for (Vertice vertice: palavrasMaisUtilizadas){
        for(auto verticeCopia: copia){
            
            if(verticeCopia.getPalavra() == vertice.getPalavra() )
            {
                existe = true;
            }
        }
        
        //copia se nao existe repitido
        if(existe == false){
            copia.push_back(vertice);
        }

        existe = false;
    }
    //vetor ordenado e sem duplicatas
    palavrasMaisUtilizadas = copia;

    cout << "\nPalavras com recorrencia maior que 1:\n\n"
         << setw(20) << left << "Palavra"  << "\tRecorrencia\n\n";

    for(Vertice vertice: palavrasMaisUtilizadas){
        if(vertice.getRecorrencia() > 1){
            cout << setw(20) << left << vertice.getPalavra() << "\t"
                 << setw(20) << left << vertice.getRecorrencia() << endl;
        }
    } 
}

int Grafo::recorrenciaAresta(Aresta arestaInput){

    int recorrencia = 0;
    for (int index = 0; index < int(arestas.size()); index++){
        if(arestaInput.CompararVertices(arestas[index]) == true){
            recorrencia++;
        }
    }
    return recorrencia;
}


void Grafo::sequenciade2Termos(){

    int maiorRecorrencia = 0;
    //obtem valor da maior ocorrencia
    for (int index = 0; index < int(arestas.size()); index++){
        if(arestas[index].getRecorrencia() > maiorRecorrencia){
            maiorRecorrencia = arestas[index].getRecorrencia();
        }
    }

    //lista todas as palavras com mesma recorrencia
    vector<Aresta> arestasMaiorRecorrencia;
    bool arestaJaExiste = 0;
    for(auto aresta: arestas){
        if(aresta.getRecorrencia() == maiorRecorrencia){
            
            for(auto arestasListadas: arestasMaiorRecorrencia){
                if(aresta.getVerticeAnterior().getPalavra() == arestasListadas.getVerticeAnterior().getPalavra()){
                    if(aresta.getverticeSeguinte().getPalavra() == arestasListadas.getverticeSeguinte().getPalavra()){
                        arestaJaExiste = true;
                    }
                }
            }
            
            if(arestaJaExiste == false){
                arestasMaiorRecorrencia.push_back(aresta);
            }

            arestaJaExiste = false;
            
        }
    }

    cout << "Sequencia de duas palavras com maior recorrencia:\n\n";
    cout << setw(30) << left << "Sequencia"
        << "\tRecorrencia\n\n";
    for(auto aresta: arestasMaiorRecorrencia){
        string sequencia = aresta.getVerticeAnterior().getPalavra() + " - "
        + aresta.getverticeSeguinte().getPalavra();
        cout << setw(30) << left << sequencia << "\t"
             << aresta.getRecorrencia() << "\n";
    }
    
}


void Grafo::sequenciadeNTermos(){

    int nTermos; //numero de termos escolhidos
    cout << "\nSelecione o numero N de termos na sequencia:\n\n";
    cin >> nTermos;

    if(cin.fail()){
        cout << "\nOpcao invalida\n";
        exit(-1);
    }


    //agrupando sentencas (separa todas as frases ate a pontuacao)
    vector<vector<Aresta>> listagrupoSentencas;
    vector<Aresta> grupoArestas;
    for(int index = 0; index < int(arestas.size()); index++){
        
        if((index + 1) < int(arestas.size())){
            if(
                arestas[index].getverticeSeguinte().getPalavra() == 
                arestas[index + 1].getVerticeAnterior().getPalavra()){
                
                grupoArestas.push_back(arestas[index]);
                
            }
            else
            {
                grupoArestas.push_back(arestas[index]);
                listagrupoSentencas.push_back(grupoArestas);
                grupoArestas.clear();
                continue;
            }
        }
        else{
            grupoArestas.push_back(arestas[index]);
            listagrupoSentencas.push_back(grupoArestas);
            grupoArestas.clear();

        }
    }

    //organiza as sentencas obtidas anteriormente em strings
    vector<string> listaSentencas;
    string frase = "";
    for(auto arestas: listagrupoSentencas){
        frase = arestas[0].getVerticeAnterior().getPalavra() + " ";
        for(auto aresta: arestas){
             frase += aresta.getverticeSeguinte().getPalavra() + " ";
        }
        frase[frase.size() - 1] = '\0';
        listaSentencas.push_back(frase);
    }

    //organiza todas as sequencias possiveis de N termos em strings
    int numPalavras = 0; 
    int contador = 0; //indica qual a palavra estou considerando
    string grupoPalavras = "";
    vector<string> listaGrupoPalavras;
    for (auto frase: listaSentencas){
        istringstream iss(frase); //util para separar string em palavras
        string lerIss;
        while(iss){ //obtem a primeira palavra da sequencia de N termos
            iss >> lerIss;
            grupoPalavras = lerIss + " ";
            contador++;
            istringstream iss2(frase);

            //alinha o segundo iterador para buscar os N-1 termos restantes
            int contWhileSacrificio = 0;
            while(contador - contWhileSacrificio > 0){
                string stringSacrificio;
                iss2 >> stringSacrificio;
                contWhileSacrificio++;
            }
            numPalavras = 0;
            while (iss2) //busca os N-1 termos restantes
            {
                numPalavras++;
                iss2 >> lerIss;
                grupoPalavras += lerIss + " ";
                if((numPalavras == (nTermos - 1)) && iss2){
                    grupoPalavras[grupoPalavras.size() - 1] = '\0';
                    listaGrupoPalavras.push_back(grupoPalavras);
                    grupoPalavras = "";
                }
            }
            numPalavras = 0;
        }
        contador = 0;
    }

    map<string, int> sequenciasMaisUtilizadas; //mapeia string e recorrencia

    //verifica se a string possui terminacao '\0' correta
    //deve ser checado antes da comparacao
    vector<string> copia;
    for(auto frase: listaGrupoPalavras){
        if (frase[frase.size() - 1] == '\0' && frase[frase.size() - 2] == '\0'){
            frase = frase.substr(0, (frase.size() - 1));
        }
        copia.push_back(frase);
    }
    listaGrupoPalavras = copia; //string com terminacao correta

    //executa a busca para verificar as sequencias mais utilizadas
    for (int index = 0; index < int(listaGrupoPalavras.size()); index++){
        if(sequenciasMaisUtilizadas.find(listaGrupoPalavras[index]) == sequenciasMaisUtilizadas.end()){
            sequenciasMaisUtilizadas[listaGrupoPalavras[index]] = 1;
            //se nao existe o termo no vetor a recorrencia eh 1
        }
        else{
            sequenciasMaisUtilizadas[listaGrupoPalavras[index]]++;
            //caso o termo exista no vetor a recorrencia eh somada
        }
    }
    //o map nao possui chaves duplicadas

    //ordennando map por ordem de recorrencia usando vetor auxiliar
    vector<pair<string, int>> copiaElementos;
    //popula vetor auxiliar
    for(auto &it: sequenciasMaisUtilizadas){
        copiaElementos.push_back(it);
    }

    //define expressao de comparacao lambda
    auto cmp = [](const auto &a, const auto &b){
        return a.second > b.second;
    };

    //ordena o vetor por recorrencia
    sort(copiaElementos.begin(), copiaElementos.end(), cmp);

    cout << "\nSequencia de N palavras mais utilizadas no texto:\n\n";
    cout << setw(30) << left << "Sequencia"
        << "\tRecorrencia\n\n";
    
    bool existeRecorrencia = false;
    for(auto &it: copiaElementos){
        if(it.second > 1){
            cout << setw(30) << left << it.first << "\t"
                << setw(5) << left << it.second << endl;

            existeRecorrencia = true;
        }
    }

    if(existeRecorrencia == false){
        cout << "\nNao existe recorrencia com " << nTermos << " termos.\n";
    }
}


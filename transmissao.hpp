#ifndef __TRANSMISSAO_HPP__
#define __TRANSMISSAO_HPP__

#include "enlace.hpp"


using namespace std;

/**
 * 
 * 
 * @param mensagem_recebida
*/
void aplicacaoReceptora(string mensagem_recebida);

/**
 * 
 * 
 * @param bits
*/
string conversaoParaString (vector<bitset<8>> bits);

/**
 * 
 * 
 * @param bits
*/
void camadaAplicacaoReceptora (vector<bitset<8>> bits);

/**
 * 
 * 
 * @param mensagem
*/
vector<bitset<8>> conversaoParaBits (const string& mensagem);

/**
 * 
 * 
 * @param mensagem
*/
void camadaAplicacaoTransmissora(const string& mensagem);

/**
 * 
*/
void aplicacaoTransmissora();



#endif
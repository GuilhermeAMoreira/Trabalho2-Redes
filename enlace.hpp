#ifndef __ENLACE_HPP__
#define __ENLACE_HPP__

#include <vector>
#include <iterator>
#include <iostream>
#include <string>
#include <bitset>
#include <cstdint>

#include "transmissao.hpp"

using namespace std;

/**
 * 
 * 
 * @param bits
*/
vector<bitset<8>> meioComunicacao(vector<bitset<8>> bits);

/**
 * 
 * 
 * @param bits
*/
bool erroCRC32(vector<bitset<8>>& quadro);

/**
 * 
 * 
 * @param bits
*/
bool erroBitParidadeImpar(const vector<bitset<8>>& bits);

/**
 * 
 * 
 * @param bits
*/
bool erroBitParidadePar(const vector<bitset<8>>& bits);

/**
 * 
 * 
 * @param bits
*/
void camadaEnlaceErro(vector<bitset<8>> bits);

/**
 * 
 * 
 * @param bits
*/
void camadaEnlaceTransmissora (vector<bitset<8>> bits);

/**
 * 
 * 
 * @param bits
*/
void camadaEnlaceReceptora (vector<bitset<8>> bits);

#endif
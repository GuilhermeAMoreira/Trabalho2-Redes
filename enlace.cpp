#include "enlace.hpp"


vector<bitset<8>> meioComunicacao(vector<bitset<8>> bits) {
    int erro;
    int porcErro = 0;
    vector<bitset<8>> bitsA = bits;
    vector<bitset<8>> bitsB;

    for (size_t i = 0; i < bitsA.size(); ++i) {
        if (rand() % 100 <= porcErro)
            bitsB.push_back(bitsA[i]); // Use push_back para adicionar elementos ao vetor
        else
            bitsA[i] ^= bitsB[i]; // Use o operador ^ para fazer o XOR bit a bit
    }

    return bitsB;
}

bool erroCRC32(vector<bitset<8>>& quadro) {
    // implementacao do algoritmo
    // usando polinomio CRC-32 (IEEE 802)
    bitset<33> polinomio(0b100000100110000010001110110110111);
    // Quando declaramos o bitset como acima, a indexacao eh da seguinte forma:
    // [n]                             [0]
    //  100000100110000010001110110110111

    // Como no tratamento dos vetores estamos considerando como se o bit 0 (bitset[0])
    // fosse o mais significativo, isto eh, o bit mais a esquerda, eh necessario
    // espelhar o polinomio
    for (int i = 0; i < 17; i++) {
        bool temp = polinomio[32 - i];
        polinomio[32 - i] = polinomio[i];
        polinomio[i] = temp;
    }

    bitset<33> resto;
    // inicialmente o resto corresponde ao inicio do polinomio
    for (int i = 1; i < 34; i++)
        resto[i] = quadro[i - 1][0];

    // implementacao da divisao
    for (size_t i = 33; i < quadro.size() * 8; i++) {
        // shiftar proximo bit da mensagem para dentro de <resto>
        // obs: bit mais significativo de resto eh sempre 0
        resto = resto >> 1;  // rotacao para a esquerda
        resto[33] = quadro[i / 8][i % 8];

        if (resto[0]) {  // bit mais significativo eh 1
            // xor com o divisor
            resto ^= polinomio;
        }
    }

    // se nao houve nenhum erro, o resto deve ser zero
    bool erro = resto.count() != 0;
    if (erro)
        return true;
    return false;
}

bool erroBitParidadeImpar(const vector<bitset<8>>& bits) {
    bitset<8> paridade = 1;
    for (const bitset<8>& bit : bits)
        paridade ^= bit;
    
    if (paridade.count() % 2 == 0) {
        cout << "Erro de paridade ímpar!!!" << endl;
        return true;
    }

    return false;
}

bool erroBitParidadePar(const vector<bitset<8>>& bits) {
    bitset<8> paridade = 0;
    for (const bitset<8>& bit : bits)
        paridade ^= bit;
    
    if (paridade.count() % 2 != 0) {
        cout << "Erro de paridade par!!!" << endl;
        return true;
    }

    return false;
}

void camadaEnlaceErro(vector<bitset<8>> bits) {
    for (int tipoErro = 0; tipoErro < 3; tipoErro++) {
        switch (tipoErro) {
        case 0:         // bit paridade par
            if (erroBitParidadePar(bits)) {
                cout << "Erro de bit paridade par detectado." << endl;
            }
            break;
        case 1:         // bit paridade ímpar
            if (erroBitParidadeImpar(bits)) {
                cout << "Erro de bit paridade ímpar detectado." << endl;
            }
            break;
        case 2:         // CRC
            if (erroCRC32(bits)) {
                cout << "Erro de CRC detectado." << endl;
            }
            break;
        }
    }
}

void camadaEnlaceTransmissora (vector<bitset<8>> bits) {
    camadaEnlaceErro (bits);
}

void camadaEnlaceReceptora (vector<bitset<8>> bits) {
    camadaEnlaceErro (bits);
}
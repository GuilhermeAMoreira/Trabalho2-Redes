#include "transmissao.hpp"

void aplicacaoReceptora(string mensagem_recebida) {
    cout << "A mensagem recebida foi:" << mensagem_recebida << endl;
}

string conversaoParaString (vector<bitset<8>> bits) {
    string mensagem;
    for (const auto& b : bits)
        mensagem.push_back(static_cast<char>(b.to_ulong()));

    return mensagem;
}

void camadaAplicacaoReceptora (vector<bitset<8>> bits) {
    camadaEnlaceReceptora(bits);

    string mensagem_recebida = conversaoParaString(bits);

    aplicacaoReceptora(mensagem_recebida);
}

vector<bitset<8>> conversaoParaBits (const string& mensagem) {
    vector<bitset<8>> bits;
    //vector<bitset<8>>::iterator it_bits;

    for (char c : mensagem) {
        bits.push_back(bitset<8>(c));
    }
    
    return bits;
}

void camadaAplicacaoTransmissora(const string& mensagem) {
    vector<bitset<8>> bits = conversaoParaBits(mensagem);

    camadaEnlaceTransmissora(bits);

    vector<bitset<8>> bitsB =  meioComunicacao(bits);
    camadaAplicacaoReceptora(bitsB);
}

void aplicacaoTransmissora() {
    string mensagem_enviada;
    cout << "Escreva a mensagem que sera enviada: " << endl;
    getline(cin, mensagem_enviada);
    camadaAplicacaoTransmissora(mensagem_enviada);
}

/**
 * 
*/
int main() {
    aplicacaoTransmissora();
    return EXIT_SUCCESS;
}
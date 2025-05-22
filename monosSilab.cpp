// O objetivo desse arquivo é criar uma forma de encriptar palavras usando o método monossilábico, que recebe uma chave (um alfabeto desorganizado).
#include <string>
#include <iostream>
#include <cctype>
#include <locale.h>
#include <unordered_map>
using namespace std;

// Essa função transforma a letra minúscula em maiúscula usando a biblioteca cctype e a função toupper (caso haja) e retorna o número da posição da letra (entre 0 e 25).
int getLetterNumber(const char letra) 
{
    const char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int number = 26;
    char letraMaiuscula = toupper(letra);
    for (size_t i = 0; i < 26; i++) 
    {
        if (alfabeto[i] == letraMaiuscula) 
        {
            number = i;
            break;
        }
    }
    return number;
}

// Esta função recebe o texto e o normaliza, tornando-o legível para o código.
string normalizarTexto(string &input) {
    static unordered_map<char, char> mapa = {
        // Minúsculas
        { 'á', 'a' }, { 'à', 'a' }, { 'â', 'a' }, { 'ã', 'a' }, { 'ä', 'a' }, { 'å', 'a' },
        { 'é', 'e' }, { 'è', 'e' }, { 'ê', 'e' }, { 'ë', 'e' },
        { 'í', 'i' }, { 'ì', 'i' }, { 'î', 'i' }, { 'ï', 'i' },
        { 'ó', 'o' }, { 'ò', 'o' }, { 'ô', 'o' }, { 'õ', 'o' }, { 'ö', 'o' }, { 'ø', 'o' },
        { 'ú', 'u' }, { 'ù', 'u' }, { 'û', 'u' }, { 'ü', 'u' },
        { 'ñ', 'n' }, { 'ç', 'c' }, { 'ý', 'y' }, { 'ÿ', 'y' },
        { 'š', 's' }, { 'ž', 'z' }, { 'đ', 'd' }, { 'ß', 's' },

        // Maiúsculas
        { 'Á', 'A' }, { 'À', 'A' }, { 'Â', 'A' }, { 'Ã', 'A' }, { 'Ä', 'A' }, { 'Å', 'A' },
        { 'É', 'E' }, { 'È', 'E' }, { 'Ê', 'E' }, { 'Ë', 'E' },
        { 'Í', 'I' }, { 'Ì', 'I' }, { 'Î', 'I' }, { 'Ï', 'I' },
        { 'Ó', 'O' }, { 'Ò', 'O' }, { 'Ô', 'O' }, { 'Õ', 'O' }, { 'Ö', 'O' }, { 'Ø', 'O' },
        { 'Ú', 'U' }, { 'Ù', 'U' }, { 'Û', 'U' }, { 'Ü', 'U' },
        { 'Ñ', 'N' }, { 'Ç', 'C' }, { 'Ý', 'Y' },
        { 'Š', 'S' }, { 'Ž', 'Z' }, { 'Ð', 'D' }
    };

    string output;
    for (char c : input) {
        auto it = mapa.find(c);
        if (it == mapa.end()) {
            output += it -> second;
        } else if (static_cast<unsigned char>(c) < 128) {
            output += c;
        }
    }
    return output;
}

// Esta função serve para trocar as letras do string de acordo com a palavra.
void encriptarPalavra(char chave[], string palavra)
{
    string palavraEncriptada;
    for (char c : palavra) 
    {
        int numeroLetra = getLetterNumber(c);
        palavraEncriptada += chave[numeroLetra];
    }

    cout << "Palavra original: '" << palavra << "'.\n" << "Palavra encriptada: '" << palavraEncriptada << "'." << endl;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char chave[] = "CGAYSZDKURWBXTHJLOPQFEMVN";
    string palavra = "Pipoca";
    encriptarPalavra(chave, palavra);
    return 0;
}
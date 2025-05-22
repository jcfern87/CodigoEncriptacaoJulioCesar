#include <iostream>
#include <string>
#include <cctype>
#include <locale.h>
using namespace std;

// Esta função retorna a letra do alfabeto que é representada pelo valor encriptado.
char getEncryptedLetter(const char alfabeto[], int valorCifrado)
{
    return alfabeto[valorCifrado];
}

// Essa função transforma a letra minúscula em maiúscula usando a biblioteca cctype e a função toupper (caso haja) e retorna o número da posição da letra (entre 0 e 25).
int getLetterNumber(const char letra, const char alfabeto[]) 
{
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

string descriptografaPalavra(const string &palavraCodificada, int chave) 
{
    const char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char letraCodificada;
    string palavraDescodificada;
    for (char c : palavraCodificada)
    {
        letraCodificada = getEncryptedLetter(alfabeto, getLetterNumber(toupper(c), alfabeto) - chave);
        palavraDescodificada += letraCodificada;
    }

    return palavraDescodificada;
    
}

void descobreChave(const string &palavraCodificada, size_t tentativas)
{
    cout << "Serão feitas " << tentativas << " tentativas de descobrir a chave." << endl;

    for (size_t i = 1; i < tentativas; i++)
    {
        cout << "Tentativa com a chave " << i << ":" << endl;
        cout << descriptografaPalavra(palavraCodificada, i) << endl;
    }
    
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int tentativas = 4;
    std::string palavraCodificada = "dudud";
    descobreChave(palavraCodificada, tentativas);
    return 0;
}

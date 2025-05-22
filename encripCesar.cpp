// o objetivo desse arquivo é criar um código de encriptação que utilize a cifra de césar para encriptar mensagens de acordo com uma chave, essa chave é um número que indica a qtd de deslocamentos no alfabeto. 
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

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

// Esta função transforma o caractere em sua forma encriptada de acordo com o resto da divisão da soma de seu valor com o valor da chafe por 26.
int encryptLetter(const int chave, const int valor)
{
    int valorCifrado = (chave + valor) % 26;
    return valorCifrado;
}

// Esta função retorna a letra do alfabeto que é representada pelo valor encriptado.
char getEncryptedLetter(const char alfabeto[], int valorCifrado)
{
    return alfabeto[valorCifrado];
}


//Esta função recebe uma string, junto com uma chave e o alfabeto, e permuta por ela por meio de um for, mudando letra por letra.
std::string cifraCesar(const std::string &texto, int chave, const char alfabeto[])
{
    std::string textoEncriptado;
    char letraEncriptada;
    int numeroLetra = 0;
    for (size_t i = 0; i < texto.length(); i++)
    {
        numeroLetra = getLetterNumber(texto[i], alfabeto);
        numeroLetra = encryptLetter(chave, numeroLetra);
        letraEncriptada = getEncryptedLetter(alfabeto, numeroLetra);
        textoEncriptado += letraEncriptada;
    }
    return textoEncriptado;
}

int main()
{
    const char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int chave = 25;
    std::string palavra = "inconstitussionalissimamente";
    std::cout << cifraCesar(palavra, chave, alfabeto);
    return 0;
}


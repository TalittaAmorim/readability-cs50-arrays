#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h> 

int main(void) // Algoritmos para classificar legibilidade de Coleman-Liau
{
   string text = get_string(" Digite o texto: "); 
   int contarLetras = 0;
   int contarPalavras = 1; // essa variavel ja começa com 1 pq depois da ultima palavra não tem espaço
   int contarFrases = 0; 
   
   for(int i = 0, n = strlen(text); i < n; i++) // a variavel i tem o papel de visitar todas as posiçoes do array de caracteres(string)|| strlen é o comprimento da string, com isso se i for menor que o comprimento, ele vai continuar a visitar
   {
       if(isalpha(text[i])) // ai no meio da visitaçao vai ter uma verificação do tipo específico de caractere (que no caso aqui é o alfabeto)
       {
           contarLetras++;
       }
       if(isspace(text[i])) // esse aqui vai contar a quantidade de espaço, essa quantidade de espaço vai corresponder a quantidade de palavras
       {
           contarPalavras++;
       }
       if(text[i]=='!' || text[i] =='.' || text[i] == '?') // e isso aqui vai contar a pontuaçao - que vai ser equivalente a frases
       {
           contarFrases++;
       }
   }
   
   float letras = ((float)contarLetras/(float)contarPalavras) *100;  // antes de colocar as var para dividir, eu tive que converter para float, já que as var originalmente era int .
   float frases = ((float)contarFrases/(float)contarPalavras) *100;
   
    int nivel =round((0.0588 * letras - 0.296 * frases - 15.8)); // Esse round é uma função de arredondamento
    
    if(nivel<1) 
    {
        printf("Nível abaixo de 1");
    }
   
    if(nivel>16)
    {
        printf("Nível acima de 16");
    }
   
   printf(" Nivel de legibilidade: %i", nivel);
  
   
}

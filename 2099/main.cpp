#include <iostream>

using namespace std;

/*
 * p(n,k) = p(n-k,k)+p(n-1,k)
 * n = numero de pedras, k = numero de colunas;
 */

#define SIZE 10000

unsigned long long int matriz[SIZE][SIZE] = {{0}};

unsigned long long int p(unsigned long long int n, unsigned long long int k)
{
    if (n == 0 && k == 0)
        return 1;
    else if (n <= 0 || k <= 0)
        return 0;
    else if (n == k)
        return 1;
    else if (k == 1)
        return 1;
    else if (k == 2)
        return int(n / 2);
    else if (n < k)
        return 0;

    if(matriz[n][k] != 0)
        return matriz[n][k];

    return matriz[n][k] = ( p(n-k,k)+p(n-1,k-1) ) % 1000000007;
}

int main()
{
    unsigned long long int i,numero, aux;
    aux = 0;
    //memset(matriz,0, sizeof(unsigned long long int));
    cin >> numero;

    if( (numero % 2) == 0 )
    {
        for(i=1; i <= numero; i+=2)
        {
            matriz[numero][i] = p(numero,i);
            aux += matriz[numero][i] % 1000000007 ;
        }
    }
    else
    {
        for(i=2; i <= numero; i+=2)
        {
            matriz[numero][i] = p(numero,i);
            aux += matriz[numero][i] % 1000000007;
        }
    }

    cout << aux % 1000000007 << endl;

    return 0;
}


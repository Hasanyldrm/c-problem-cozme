#include <stdio.h>
#include <time.h>

void wait_func();
int permuted_multiples(int n, int m);

int main() {
    int x = 1;
    double time_spent = 0.0;

    clock_t begin = clock();

    while (1)
    {
        if (permuted_multiples(x * 2, x * 3) && permuted_multiples(x * 3, x * 4) &&
            permuted_multiples(x * 4, x * 5) && permuted_multiples(x * 5, x * 6)) {
            break;
        }
        else {
            x++;
        }
    }
    printf("Tum katlarinin rakamlari ayni olan en kucuk pozitif tamsayi: %d\n", x);

    wait_func();
    clock_t end = clock();
    time_spent += (double)(end - begin);

    printf("\nKodun calisma suresi %.2f millisaniye surdu.\n", time_spent);
}
int permuted_multiples(int n, int m) {
    int sayac[10] = { 0 }; // Basamakların sayısını tutmak için sayaç dizisi.
    while (n > 0) {
        sayac[n % 10]++; // Basamak sayısını artır
        n /= 10; // Bir sonraki basamağa geç
    }
    while (m > 0) {
        sayac[m % 10]--; // Basamak sayısını azalt
        m /= 10; // Bir sonraki basamağa geç
    }
    // Eğer her iki sayı da aynı basamakları içeriyorsa, sayac dizisi tüm sıfırlar olacaktır
    for (int i = 0; i < 10; i++) {
        if (sayac[i] != 0)
            return 0;
    }
    return 1;
}
void wait_func()
{
    for (int i = 0; i < 10000000; i++);
}

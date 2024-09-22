//Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000).
// Упорядочить последовательность по неубыванию суммы цифр числа,
// числа с одинаковыми суммами цифр дополнительно упорядочить по неубыванию наибольшей цифры числа,
// числа с одинаковыми суммами цифр и одинаковыми наибольшими цифрами дополнительно упорядочить по неубыванию самого числа.
#include <iostream>
int main() {
    const int N = 1000;
    int n;
    int maximum = INT_MIN;
    int dd[N];//сумма цифр числа
    int kk[N];//наибольшая цифра числа
    std::cin >> n;
    int mas[N];
    for (int i = 0; i < n; i++) {
        std::cin >> mas[i];
    }
    for (int k = 0; k < n; k++){
        int tmp = mas[k];
        dd[k] = 0;
        kk[k] = 0;
        while(tmp > 0){
            dd[k] += tmp % 10;
            if (tmp % 10 >= maximum)
            {
                maximum = tmp%10;

            }
            kk[k] = maximum;
            tmp /= 10;
        }
    }
    for (int l = 0; l < n - 1; l++)
        for (int j = l + 1; j < n; j++) {
            if (dd[l] > dd[j] ||
               (dd[l] == dd[j]) && (kk[l]>kk[j]) ||
               (dd[l] == dd[j]) && (kk[l]==kk[j]) && (mas[j]>mas[l]))  {
                std::swap(mas[j], mas[l]);
                std::swap(dd[j], dd[l]);
                std::swap(kk[j], kk[l]);
            }
        }
    for (int s=0; s<n; s++)
   {
       std::cout<<mas[s]<<std::endl;
   }
}


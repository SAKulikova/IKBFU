//Задача №5 «Умный динамический массив»
//Вам предлагается создать класс, который опишет умный динамический массив из целых чисел.
// Количество чисел заранее неизвестно.
// Ограничением служит размер доступной оперативной памяти компьютера, но использовать память все же надо рационально.
//
//Что он должен уметь:
//Добавлять элемент в конец.+
//Выдавать текущее количество элементов. +
//Выдавать элемент по индексу.+
//Изменять элемент по индексу.+
//Удалять элемент по индексу.+
//Вставлять элемент по индексу.+
#include <iostream>
class DinamicMas
{
private:
    int m_l=1;
    int* m_mas = new int[m_l];
public:
    DinamicMas(int f)
    {
        m_l=1;
        m_mas[0]=f;
    }
    ~DinamicMas()
    {
        delete[] m_mas;
    }
    void ElementInBack(int m)
    {
        int* mas_new = new int [m_l+1];
        for (int i=0; i< m_l; i++)
            mas_new[i]=m_mas[i];
        mas_new[m_l]=m;
        delete[] m_mas;
        m_mas=mas_new;
        m_l++;
    }
    int CurrentNumber()
    {
        return m_l;
    }
    int ElementByIndex(int index)
    {
        return m_mas[index];
    }
    void ChangeElementByIndex(int k, int index)
    {
        m_mas[index]=k;
    };
    void DeletElementByIndex(int index)
    {
        int* mas_new = new int [m_l-1];
        for (int i=0; i< index; i++)
            mas_new[i]=m_mas[i];
        for(int i=index; i<m_l;i++)
            mas_new[i]=m_mas[i+1];
        delete[] m_mas;
        m_mas=mas_new;
        m_l--;
    }

    void InsertElementByIndex(int index, int t)
    {
        int* mas_new = new int [m_l+1];
        for (int i=0; i < index; i++)
            mas_new[i]=m_mas[i];
        mas_new[index]=t;
        for(int i=index+1; i<m_l+1;i++)
            mas_new[i]=m_mas[i];
        delete[] m_mas;
        m_mas=mas_new;
    }
};
int main()
{
    DinamicMas mas(1);
    mas.ElementInBack(15);
    mas.ElementInBack(4);
    mas.ElementInBack(5);
    mas.ElementInBack(10);
    mas.ElementInBack(45);
    for (int i=0; i<mas.CurrentNumber(); i++ )
        std::cout<< mas.ElementByIndex(i)<< " ";
    std::cout<<std::endl;
    std::cout<<mas.ElementByIndex(2)<< std::endl;
    mas.ChangeElementByIndex(900,1);
    mas.DeletElementByIndex(0);
    mas.InsertElementByIndex(4,0);
    for (int i=0; i<mas.CurrentNumber(); i++ ){
        std::cout<< mas.ElementByIndex(i)<< " ";
    }
}
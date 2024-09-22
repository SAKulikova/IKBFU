// диагональ куба = сторона * sqrt(3)
//Найти диагональ куба.
#include <iostream>
#include <cmath>
class Cube
{
private:
    //Абстракция
    double m_side=0;
    double m_diagonal=0;
public:
    //Инкапсуляция
    Cube(double side)
    {
        m_side = side;
    }
    ~Cube() {};
    bool SetSide(double side)
    {
        if (side <= 0)
        {
            std::cout << "Error in side of cube" << std::endl;
            return false;
        }
        else{
            return true;
        }
    }
    double Diagonal1 (double side)
    {
        if (SetSide(side))
            return m_side*sqrt(3);
    }
    void Diagonall(double side){
        std::cout<<Diagonal1(side)<< std::endl;
    }
};
int main() {
    std::cout<< "Введите сторону куба" <<std::endl;
    double side;
    std::cin >> side;
    Cube cube1(side);
    cube1.Diagonall(side);
}
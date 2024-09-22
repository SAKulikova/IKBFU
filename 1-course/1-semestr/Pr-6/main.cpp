#include <iostream>
#include <vector>

int main() {
    std:: vector <int> ivector = {15, 32, 8, 20, 9, 3};
    std::cout<<"Вектор без изменений"<<std::endl;
    for (int i=0; i<ivector.size(); i++)
        std::cout<<ivector[i]<<" ";
    std::cout<<""<<std::endl;
    std::cout << std::endl;
    //операция присваивания
    ivector.at(1) = 5;
    ivector[0] = 17;
    std::cout<<"Операции присваивания"<<std::endl;
    for (int i=0; i<ivector.size(); i++)
        std::cout<<ivector[i]<<" ";
    std::cout<<""<<std::endl;
    std::cout << std::endl;
    //Функция erase () используется для удаления одного или нескольких элементов из вектора
    ivector.erase(ivector.begin());
    //С помощью функции push_back() мы можем добавить ячейку в конец вектора.
    ivector.push_back(456);
    //Функция emplace_back() добавляет элемент в конец контейнера. emplace_back создает объект непосредственно в конце вектора
    ivector.emplace_back(1);
    ivector.insert(ivector.begin(),0);//добавляет элемент в начало
    ivector.insert(ivector.end(), 99);//добавляет элемент в конец
    std::cout<<"Функции erase, push_back, emplace_back, insert"<<std::endl;
    for (int i=0; i<ivector.size(); i++)
        std::cout<<ivector[i]<<" ";
    std::cout<<""<<std::endl;
    std::cout << std::endl;
    std::cout<<"Функция resize"<<std::endl;
    //Функция resize () используется для изменения размера вектора. Размер вектора можно увеличить или уменьшить с помощью этой функции.
    ivector.resize(5);
    for (int i=0; i<ivector.size(); i++)
        std::cout<<ivector[i]<<" ";
    std::cout<<""<<std::endl;
    //вместимость вектора до увеличения его размера
    std::cout << "\nВместимость вектора до увеличения его размера: " << ivector.capacity();
    ivector.reserve(20);
    //вместимость вектора после увеличения его размера
    std::cout << "\nВместимость вектора после увеличения его размера: " << ivector.capacity();

    ivector.shrink_to_fit();
    //очищение памяти
    std::cout << "\nВместимость вектора после shrink_to_fit: " << ivector.capacity();

    ivector.clear();
    //std::cout<<ivector.size()<<std::endl;
    //std::cout<<ivector.capacity();
    return 0;
}
//capacity возвращает количество элементов, для которых в данный момент выделено место в контейнере.
//shrink_to_fit(). Эта функция уменьшает количество используемой памяти нашего вектора (иначе говоря, у нас есть вектор из 10 элементов, но он пустой, эта функция возвращает память системе, которую занимал наш пустой вектор)
//Разница между resize и reserve
//Если resize() вызывается со значением > чем текущий размер (size), то создаются дополнительные элементы конструктором по умолчанию. Если < чем текущий размер, то лишние элементы удаляются из вектора.
//reserve() может только увеличить ёмкость до заданного числа элементов (выделит память, но никаких элементов создано не будет). Т.е. вызов reserve() не влияет на size.
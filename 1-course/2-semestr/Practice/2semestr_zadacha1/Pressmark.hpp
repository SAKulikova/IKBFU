#include <fstream>

class Pressmark
{
private:
    unsigned int m_fibb[30];
    std::string words[30] = {};
int t;

    void Fibonacci_numbers()
    {
        m_fibb[0]=1;
        m_fibb[1]=2;
        for (int i=2; i<30; i++){
            m_fibb[i]=m_fibb[i-2]+m_fibb[i-1];
        }
    }

public:
    Pressmark(int useless){
        Fibonacci_numbers();
    }
    void Encode(){
        std::ifstream in ("/Users/sonya/Desktop/C++/2semestr_zadacha1/letter.txt", std::ios::in);
        t = 0;
        std::string word;
        if (!in)
            std::cout<<"Error";

        while (in >> word) {
            words[t] = word;
            t++;
        }
        in.close();
    }
    void Decode(){
        int key[30];
        for(int i=0; i<t; i++){
            std::cin>>key[i];
        }
        for (int p=0; p<t; p++)
            for(int l=0; l<30; l++) {
                if (key[p] == m_fibb[l])
                    std::cout << words[l] << " ";

            }
        for (int j=0; j<t-1; j++){
            for(int k=j+1; k<t; k++){
                if (key[j]>key[k]){
                    std::swap(key[k], key[j]);
                }
            }
        }
        std::cout<<std::endl;
        for (int p=0; p<t; p++)
            for(int l=0; l<30; l++)
                if (key[p]==m_fibb[l])
                    std::cout << words[l]<< " ";

    }

};
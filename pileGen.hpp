#include <iostream>

template<typename T>
class PileGen
{
private:
    int capacite;
    int taille;
    T * tab;
public:
    PileGen(int = 256);
    const T & top() const;
    bool isEmpty() const;
    void pop();
    void push(const T &);
    int size() const;
    ~PileGen();
};

template<typename T>
PileGen<T>::PileGen(int capa) : capacite(capa), taille(0) {
    if(capa <= 0){
        std::invalid_argument e("Capa should be > 0");
        throw e;
    }
    tab = new T[capacite];
}

template<typename T>
const T & PileGen<T>::top() const{
    return tab[taille -1];
}

template<typename T>
void PileGen<T>::push(const T & el){
    if(taille >= capacite){
        std::out_of_range e("no stack capacity");
        throw e;
    }
    tab[taille] = el;
    ++taille;
}

template<typename T>
bool PileGen<T>::isEmpty() const{
    return (taille <= 0);
}

template<typename T>
void PileGen<T>::pop(){
    if(taille <= 0){
        std::invalid_argument e("can't pop an empty stack");
        throw e;
    }
    --taille;
}

template<typename T>
int PileGen<T>::size() const{
    return taille;
}

template<typename T>
PileGen<T>::~PileGen(){
    delete tab;
}

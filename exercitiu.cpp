#include <iostream>
#include <string>

using namespace std;

class Carte {
private:
    char* titlu;
    string autor;
    int numarPagini;
    double pret;
    bool electronica;
    int* numarCuvinte;

public:
    Carte(const char* _titlu, const string& _autor, int _numarPagini, double _pret, bool _electronica, const int* _numarCuvinte) :
        autor(_autor), numarPagini(_numarPagini), pret(_pret), electronica(_electronica) {
        this->titlu = new char[strlen(_titlu) + 1];
        strcpy_s(this->titlu, strlen(_titlu) +1, _titlu);

        this->numarCuvinte = new int[_numarPagini];
        for (int index = 0; index < _numarPagini; index++) {
            this->numarCuvinte[index] = _numarCuvinte[index];
        }
    }

    Carte(const Carte& carte) {
        this->autor = carte.autor;
        this->numarPagini = carte.numarPagini;
        this->titlu = new char[strlen(carte.titlu) + 1];
        strcpy_s(this->titlu, strlen(carte.titlu) + 1, carte.titlu);

        this->numarCuvinte = new int[numarPagini];
        for (int index = 0; index < numarPagini; index++) {
            this->numarCuvinte[index] = carte.numarCuvinte[index];
        }

        this->pret = carte.pret;
        this->electronica = carte.electronica;
    }

    ~Carte() {
        delete[] titlu;
        delete[] numarCuvinte;
    }

    string getAutor() {
        return autor;
    }

    void setAutor(const string& _autor) {
        autor = _autor;
    }

    int getNumarPagini() {
        return numarPagini;
    }

    void setNumarPagini(int _numarPagini) {
        numarPagini = _numarPagini;
    }

    double getPret() {
        return pret;
    }

    void setPret(double _pret) {
        pret = _pret;
    }
    bool isElectronica() {
        return electronica;
    }
    void setElectronica(bool _electronica) {
        electronica = _electronica;
    }

    const char* getTitlu() {
        return titlu;
    }

    void setTitlu(const char* _titlu) {
        delete[] titlu;
        titlu = new char[strlen(_titlu) + 1];
        strcpy_s(this->titlu, strlen(_titlu) +1, _titlu);
    }
    const int* getNumarCuvinte() {
        return numarCuvinte;
    }

    void setNumarCuvinte(const int* _numarCuvinte) {
        delete[] numarCuvinte;
        numarCuvinte = new int[numarPagini];
        for (int index = 0; index < numarPagini; index++) {
            numarCuvinte[index] = _numarCuvinte[index];
        }
    }
};

int main() {
    char* titlu = (char*)"Titlu Carte"; 
    string autor = "Autor Carte";
    int numarPagini = 200;
    double pret = 25.99;
    bool electronica = false;
    int numarCuvinte[200];

    for (int i = 0; i < numarPagini; i++) {
        numarCuvinte[i] = 300; 
    }

    Carte c1((char*)titlu, autor, numarPagini, pret, electronica, numarCuvinte);

    c1.setAutor("Alt Autor");
    cout << "Noul autor al cărții este: " << c1.getAutor() << endl;

    return 0;
}


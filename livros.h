#pragma once
#include <string>
#include <iostream>
using namespace std;

class Livro{
    private:
    string titulo;
    string autor;
    int preco;
    int estoque;
    float codigo;
    string genero;
    int paginas;
    string sinopse;

public:
Livro(string t, string a, int p, int e, float c, string g, int pag, string s){
    titulo = t;
    autor = a;
    preco = p;
    estoque = e;
    codigo =c;
    genero = g;
    paginas = pag;
    sinopse = s;

}
//MEDOTO GET
string getTitulo(){return titulo;}
string getAutor(){return autor;}
int getPreco(){return preco;}
int  getEstoque(){return estoque;}
float getCodigo(){return codigo;}
string getGenero(){return genero;}
int getPaginas(){return paginas;}
string getSinopse(){return sinopse;}

//METODOS SET
void setTitulo(string t){titulo = t;}
void setAutor(string a){autor = a;}
void setPreco(int p){preco = p;}
void setEstoque(int e){estoque = e;}
void setCodigo(float c){codigo = c;}
void setGenero(string g){genero = g;}
void setPaginas(int pag){paginas = pag;}
void setSinopse(string s){sinopse = s;}

//METODO VENDER
float vender(int q){
    if(estoque >= q){
        estoque -= q;
        return true;
    }
    return false;
}

void reporEstoque(int q){
    estoque += q;
}

void mostrar() {
    cout << "Título: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "Sinopse: " << sinopse << endl;
    cout << "Preço: " << preco << endl;
    cout << "Gênero: " << genero << endl;
    cout << "Páginas: " << paginas << endl;
    cout << "Código: " << codigo << endl;
    cout << "Estoque: " << estoque << endl;
}

};

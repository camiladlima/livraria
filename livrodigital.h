#pragma once
#include "produto.h"

using namespace std;

class LivroDigital : public Produto{
private:
        float tamanho;
        string formato;
public:
   LivroDigital(string t, string a, float p, int e, float tam, string form)
        : Produto(t, a, p, e), tamanho(tam), formato(form) {}

void exibirDetalhes()override {
        int yMax, xMax;
        getmaxyx(stdscr, yMax, xMax);
        WINDOW *win = newwin(14, 50, (yMax-14)/2, (xMax-50)/2);
        box(win, 0, 0);
        mvwprintw(win, 1, 15, "=== LIVRO DIGITAL ===");
        mvwprintw(win, 3, 2, "Titulo: %s", titulo.c_str());
        mvwprintw(win, 4, 2, "Autor: %s", autor.c_str());
        mvwprintw(win, 5, 2, "Preco: R$ %.2f", preco);
        mvwprintw(win, 6, 2, "Estoque: %d unidades", estoque);
        mvwprintw(win, 7, 2, "Tamanho: %.2f MB", tamanho);
        mvwprintw(win, 8, 2, "Formato: %s", formato.c_str());
        mvwprintw(win, 12, 10, "Pressione uma tecla...");
        wrefresh(win);
        getch();
        delwin(win);
    }
};

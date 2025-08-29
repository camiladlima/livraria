#pragma once
#include <string>
#include <iostream>
using namespace std;

class Produto {
protected:
    string titulo;
    string autor;
    float preco;
    int estoque;

public:
    Produto(string t, string a, float p, int e)
        : titulo(t), autor(a), preco(p), estoque(e) {}

    virtual void exibirDetalhes() {
        int yMax, xMax;
        getmaxyx(stdscr, yMax, xMax);

        WINDOW *win = newwin(12, 50, (yMax-12)/2, (xMax-50)/2);
        box(win, 0, 0);

        mvwprintw(win, 1, 18, "=== PRODUTO ===");
        mvwprintw(win, 3, 2, "Titulo: %s", titulo.c_str());
        mvwprintw(win, 4, 2, "Autor: %s", autor.c_str());
        mvwprintw(win, 5, 2, "Preco: R$ %.2f", preco);
        mvwprintw(win, 6, 2, "Estoque: %d unidades", estoque);

        mvwprintw(win, 10, 14, "Pressione uma tecla...");
        wrefresh(win);
        getch();
        delwin(win);
    }
};

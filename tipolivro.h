#pragma once
#include "produto.h"

using namespace std;

class LivroFisico : public Produto {
private:
    float peso;
    int paginas;

public:
    LivroFisico(string t, string a, float p, int e, float ps, int pg)
        : Produto(t, a, p, e), peso(ps), paginas(pg) {}


void exibirDetalhes()override {
        int yMax, xMax;
        getmaxyx(stdscr, yMax, xMax);
        WINDOW *win = newwin(14, 50, (yMax-14)/2, (xMax-50)/2);
        box(win, 0, 0);
        mvwprintw(win, 1, 15, "=== LIVRO FISICO ===");
        mvwprintw(win, 3, 2, "Titulo: %s", titulo.c_str());
        mvwprintw(win, 4, 2, "Autor: %s", autor.c_str());
        mvwprintw(win, 5, 2, "Preco: R$ %.2f", preco);
        mvwprintw(win, 6, 2, "Estoque: %d unidades", estoque);
        mvwprintw(win, 7, 2, "Paginas: %d", paginas);
        mvwprintw(win, 8, 2, "Peso: %.2f kg", peso);
        mvwprintw(win, 12, 10, "Pressione uma tecla...");
        wrefresh(win);
        getch();
        delwin(win);
    }
};


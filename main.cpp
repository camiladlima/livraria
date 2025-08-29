#include <ncurses.h>
#include <vector>
#include <string>
#include "produto.h" // corrigido
#include "tipolivro.h"
#include "livrodigital.h"

using namespace std;

int main() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        init_pair(2, COLOR_BLACK, COLOR_BLUE);
    }

    vector<string> opcoes = {
        "1 - Inserir livro",
        "2 - Listar todos os livros",
        "3 - Exibir um livro",
        "4 - Alterar livro",
        "5 - Remover livro",
        "6 - Gerar relatorio",
        "7 - Sair"
    };

    vector<Produto*> livros;

    int escolha = 0;
    int tecla;

    while (true) {
        clear();
        attron(COLOR_PAIR(1));
        mvprintw(1, 5, "<------- LIVRARIA ------->");
        attroff(COLOR_PAIR(1));

        for (int i = 0; i < (int)opcoes.size(); i++) {
            if (i == escolha) {
                attron(COLOR_PAIR(2));
                mvprintw(3 + i, 5, opcoes[i].c_str());
                attroff(COLOR_PAIR(2));
            } else {
                attron(COLOR_PAIR(1));
                mvprintw(3 + i, 5, opcoes[i].c_str());
                attroff(COLOR_PAIR(1));
            }
        }

        refresh();
        tecla = getch();

        switch (tecla) {
            case KEY_UP:
                escolha = (escolha - 1 + opcoes.size()) % opcoes.size();
                break;
            case KEY_DOWN:
                escolha = (escolha + 1) % opcoes.size();
                break;
            case 10: // Enter
                 switch (escolha) {
                    case 0: // Inserir livro
                        livros.push_back(new LivroFisico("O Senhor dos Aneis", "Tolkien", 120.0, 10, 1.2, 1178));
                        livros.push_back(new LivroDigital("Harry Potter", "J.K.Rowling", 50.0, 5, 5.6, "PDF"));
                        break;
                    case 1: // Listar todos os livros
                        for (auto& livro : livros) {
                            livro->exibirDetalhes();
                        }
                        livros.clear();
                        break;
                    case 2: // Exibir um livro específico
                        if (!livros.empty()) {
                            livros[0]->exibirDetalhes(); // exemplo: primeiro livro
                        }
                        break;
                    case 3: // Alterar livro
                        clear();
                        mvprintw(10, 5, "Funcao de alterar livro ainda nao implementada.");
                        refresh();
                        getch();
                        break;
                    case 4: // Remover livro
                        clear();
                        mvprintw(10, 5, "Funcao de remover livro ainda nao implementada.");
                        refresh();
                        getch();
                        break;
                    case 5: // Gerar relatorio
                        clear();
                        mvprintw(10, 5, "Funcao de gerar relatorio ainda nao implementada.");
                        refresh();
                        getch();
                        break;
                    case 6: // Sair
                        endwin();
                        return 0;
                }
                break;
        }
    }

    endwin();
    return 0;
}

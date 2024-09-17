#include "pch.h"
#include "Biblioteca TF - MQAA.h"


int main()
{
    Console::BackgroundColor = ConsoleColor::White;
    srand(time(nullptr));
    ventana();
    string nombre;
    bool otra_partida = 0;
    int tam_rank = 0;
    ranking* rank_partida = new ranking[tam_rank];
    inicio();
    do
    {
        int tam = 0, vida_pj = 99, puntj = 0;
        carta* mazo_pj = new carta[tam];
        carta* mano = new carta[4];

        for (int i = 0; i < 36; i++)
        {
            mazo_pj = agregar_desde_Bdatos(mazo_pj, i, tam);
        }

        int mapa_i = 30, mapa_j = 11;
        int eleccion_personaje, complejidad = 0, n_clase = 0;
        elegir_personaje(eleccion_personaje);
        ingresar_nombre(nombre);
        _sleep(200);
        do
        {
            if (complejidad % 4 == 0)
            {
                clase(n_clase);
                n_clase++;
                complejidad++;
            }
            else
            {
                partida(eleccion_personaje, complejidad, n_clase, mazo_pj, mano, tam, vida_pj, puntj, nombre);
                complejidad++;
            }
            subir_nivel_mapa(mapa_i, mapa_j, complejidad);
        } while (complejidad < 11);
        clase(3);

        if (vida_pj != 0) {
            ultima_batalla(eleccion_personaje, complejidad, n_clase, mazo_pj, mano, tam, vida_pj, puntj, nombre);
            if (puntj > 1500) { nivel_adicional(eleccion_personaje, complejidad, n_clase, mazo_pj, mano, tam, vida_pj, puntj, nombre); }
        }
        Console::BackgroundColor = ConsoleColor::Black;
        Console::Clear();
        int** you_lowin = crearMatriz(11, 70);
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 70; j++) {
                you_lowin[i][j] = you_lose_you_win[(vida_pj > 0) * 1][i][j];
            }
        }
        color_escenarios(you_lowin, 11, 70, 64, 16);
        system("pause>0");

        rank_partida = agregar_nuevo_usuario(rank_partida, tam_rank, puntj, nombre);
        rank_partida = ordenar_ranking(rank_partida, tam_rank);
        imprimir_ranking(rank_partida, tam_rank);
        system("pause>0");
        delete[] mazo_pj, mano;
        partida_otra(otra_partida);
    } while (otra_partida == true);
    creditos();
    delete[] rank_partida;
    system("pause>0");
    return 0;
}

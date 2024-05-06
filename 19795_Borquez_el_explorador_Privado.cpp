#include <iostream>
using namespace std;

int main() {
    string hora_dormir, hora_levantarse;
    int h_dormir, m_dormir, h_levantarse, m_levantarse;

    // Leer la entrada
    cin >> hora_dormir >> hora_levantarse;

    // Obtener horas y minutos de dormir
    h_dormir = stoi(hora_dormir.substr(0, 2));
    m_dormir = stoi(hora_dormir.substr(3, 2));

    // Obtener horas y minutos de levantarse
    h_levantarse = stoi(hora_levantarse.substr(0, 2));
    m_levantarse = stoi(hora_levantarse.substr(3, 2));

    // Convertir horas a minutos
    int total_dormir;

    if (h_levantarse <= h_dormir && m_levantarse <= m_dormir || h_levantarse < h_dormir  ) {
       
        // Sumar la diferencia entre la hora de dormir y el final del día (24 horas) más la hora de levantarse
        total_dormir = (24 * 60 - (h_dormir * 60 + m_dormir)) + (h_levantarse * 60 + m_levantarse);
    } else {
        //cout<<(h_levantarse * 60 + m_levantarse)<<endl;
        total_dormir = (h_levantarse * 60 + m_levantarse) - (h_dormir * 60 + m_dormir);
    }

    // Imprimir la cantidad de minutos que podrá dormir Diego
    cout << total_dormir << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum class levels {DEBUG = 1, INFO, WARNING, ERROR, CRITICAL};

void log_message(string message, levels level){
    ofstream outFile("logs_file.txt", ios::app);
    if (outFile.is_open()){
        switch(level){
            case levels::DEBUG:
                outFile << "[DEBUG] " << message << endl;
                break;
            case levels::INFO:
                outFile << "[INFO] " << message << endl;
                break;
            case levels::WARNING:
                outFile << "[WARNING] " << message << endl;
                break;
            case levels::ERROR:
                outFile << "[ERROR] " << message << endl;
                break;
            case levels::CRITICAL:
                outFile << "[CRITICAL] " << message << endl;
                break;
            default:
                cout << "Unkown" << endl;
        outFile.close();
        }
    }
    else{
        cerr << "Error al abrir el archivo" << endl;
    }
}

int main(){
    log_message("Se accedio a memoria invalida", levels::CRITICAL);
    log_message("Se freno en la linea 5", levels::DEBUG);
    log_message("No se puede restar un tipo list con un tipo map", levels::ERROR);
    log_message("Casteo a int puede hacer perder precision del float", levels::WARNING);
    log_message("El archivo de salida se creo con exito", levels::INFO);
    return 0;
}


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
    log_message("Exploto un avion", levels::ERROR);
    log_message("El debugger descompilo el programa", levels::DEBUG);
    return 0;
}


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

void log_message(string msg, string file, int line){
    ofstream outFile(file, ios::app);
    outFile << msg << " in line: " << line << endl;
    outFile.close();
}

void log_message(string msg_access, string username){
    ofstream outFile("logs_file.txt", ios::app);
    outFile << "[SECURITY] " << msg_access << "user: " << username << endl;
    outFile.close();
}

int main(){
    log_message("Se accedio a memoria invalida", levels::CRITICAL);
    log_message("Se freno en la linea 5", levels::DEBUG);
    log_message("No se puede restar un tipo list con un tipo map", levels::ERROR);
    log_message("Casteo a int puede hacer perder precision del float", levels::WARNING);
    log_message("El archivo de salida se creo con exito", levels::INFO);
    try{
        float a, b;
        cout << "Choose a: "; cin >> a;
        cout << "Choose b: "; cin >> b; cout << endl;
        cout << "Doing a/b..." << endl;
        if (b == 0){
            throw runtime_error("Division by 0 was attempted");
        }
        float result = a/b;
        cout << "Result: " << result << endl;
    } 
    catch (exception &e){
        log_message(e.what(), levels::ERROR);
        log_message(e.what(), "logs_file.txt", 64);
        cout << "Loggin out with error " << e.what() << endl;
        exit(1);
    }
    return 0;
}


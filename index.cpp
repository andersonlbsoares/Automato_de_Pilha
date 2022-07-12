#include <iostream>
#include <string>
#include <vector>
#include <stack>

bool aceito = false;

//char to string
std::string to_string(char c){
    std::string s;
    s += c;
    return s;
}
//retorna primeiro caracter da string
char first_char(std::string s){
    return s[0];
}
//retorna a string sem o primeiro caracter
std::string without_first_char(std::string s){
    return s.substr(1);
}
//imprimir pilha inteira
std::string print_stack(std::stack<char> s){
    std::string str;
    while(!s.empty()){
        str += s.top();
        s.pop();
    }
    return str;
}
//retorna a string ao contrario
std::string reverse(std::string s){
    std::string str;
    for(int i = s.size()-1; i >= 0; i--){
        str += s[i];
    }
    return str;
}


struct Transicoes {
    int estadoDePartida;
    int estadoDeChegada;
    char simboloDeEntrada;
    char simboloDoTopoDaPilha;
    std::string stringASerEscritaNoTopoDaPilha;
};

void rodar(std::string stringEntrada, std::vector<Transicoes> regras, std::stack<char> pilha, int numeroEstadoInicial, int *estadosFinais, char simboloInicial ){
    // printa todas as regras
    for(int i = 0; i < regras.size(); i++){
        //pega o tamanho dos estaods finais
        int tamanhoEstadosFinais = sizeof(estadosFinais)/sizeof(estadosFinais[0]);
        //percorre os estados finais
        for(int j = 0; j < tamanhoEstadosFinais; j++){
            //verifica se o estado atual é um estado final
            if(regras[i].estadoDeChegada == estadosFinais[j]){
                //verifica se o simbolo do topo da pilha é o simbolo inicial
                if(pilha.top() == simboloInicial){
                    if(stringEntrada == ""){
                        aceito = true;
                    }
                }
            }
        }
        
        if((regras[i].simboloDoTopoDaPilha == pilha.top()&&regras[i].estadoDePartida == numeroEstadoInicial && first_char(stringEntrada) == regras[i].simboloDeEntrada)||(regras[i].simboloDoTopoDaPilha == pilha.top()&&regras[i].estadoDePartida == numeroEstadoInicial && 'e'== regras[i].simboloDeEntrada)){
            std::stack<char> pilhaBackup = pilha;
            // std::cout<<std::endl << "Topo da Pilha" << pilha.top();
            // std::cout<< "Estado de partida: " << regras[i].estadoDePartida << std::endl;
            // std::cout<< "Estado de chegada: " << regras[i].estadoDeChegada << std::endl;
            // std::cout<< "Simbolo de entrada: " << regras[i].simboloDeEntrada << std::endl;
            // std::cout<< "Simbolo do topo da pilha: " << regras[i].simboloDoTopoDaPilha << std::endl;
            // std::cout<< "String a ser escrita no topo da pilha: " << regras[i].stringASerEscritaNoTopoDaPilha << std::endl;
            // std::cout<< "Pilha antes da execucao: " << print_stack(pilha) << std::endl;
            

            //pega o tamanho da string a ser escrita no topo da pilha e divide em 2 char
            if(regras[i].stringASerEscritaNoTopoDaPilha.size() == 2 && regras[i].stringASerEscritaNoTopoDaPilha[0] != 'e'){
                char c1 = regras[i].stringASerEscritaNoTopoDaPilha[0];
                char c2 = regras[i].stringASerEscritaNoTopoDaPilha[1];
                pilha.pop();
                pilha.push(c2);
                pilha.push(c1);
            }else if(regras[i].stringASerEscritaNoTopoDaPilha.size() == 1 && regras[i].stringASerEscritaNoTopoDaPilha[0] != 'e'){
                char c1 = regras[i].stringASerEscritaNoTopoDaPilha[0];
                pilha.pop();
                pilha.push(c1);
            }else{
                pilha.pop();
            }
            // std::cout << "Pilha depois da execucao:" << print_stack(pilha) << std::endl;
                
                if('e'== regras[i].simboloDeEntrada){
                    if(stringEntrada.size() == 0){
                        std::cout<<"("<<regras[i].estadoDeChegada << "," << "e" << "," << print_stack(pilha) << ";";
                    }else{
                        std::cout<<"("<<regras[i].estadoDeChegada << "," << stringEntrada << "," <<print_stack(pilha) << ";";
                    }
                    rodar (stringEntrada, regras, pilha, regras[i].estadoDeChegada, estadosFinais, simboloInicial);
                    std::cout << ")";
                }else{
                    if(without_first_char(stringEntrada).size() == 0){
                        std::cout<<"("<<regras[i].estadoDeChegada << "," << "e" << "," << print_stack(pilha) << ";";
                    }else{
                        std::cout<<"("<<regras[i].estadoDeChegada << "," << without_first_char(stringEntrada) << "," <<print_stack(pilha) << ";";
                    }
                    rodar (without_first_char(stringEntrada), regras, pilha, regras[i].estadoDeChegada, estadosFinais, simboloInicial);
                    std::cout << ")";
                }
                
            pilha = pilhaBackup;
        }
    

    }

}

    int main() {
    int qntdEstados{0};                                    //QUANTIDADE DE ESTADOS
    int qntdSimbolosEntrada{0};                            //QUANTIDADE DE SIMBOLOS DE ENTRADA
    int qntdSimbolosAlfabeto{0};                   	        //QUANTIDADE DE SIMBOLOS DO ALFABETO DE PILHA
    int numeroEstadoInicial{0};
    char SimboloInicial;
    int qntdEstadosFinais{0};
    int qntdTransicoes{0};
    std::string stringEntrada;
    std::stack<char> pilha;
    pilha.push('Z');


    std::cin >> qntdEstados;

    std::cin >> qntdSimbolosEntrada;
    char simbolosEntrada[qntdSimbolosEntrada];       //SIMBOLOS DE ENTRADA
    for (int i = 0; i < qntdSimbolosEntrada; i++) {
        std::cin >> simbolosEntrada[i];
    }

    std::cin >> qntdSimbolosAlfabeto;
    char simbolosAlfabeto[qntdSimbolosAlfabeto];            //SIMBOLOS DO ALFABETO DE PILHA
    for (int i = 0; i < qntdSimbolosAlfabeto; i++) {
        std::cin >> simbolosAlfabeto[i];
    }

    std::cin >> numeroEstadoInicial;
    std::cin >> SimboloInicial;
    std::cin >> qntdEstadosFinais;
    int estadosFinais[qntdEstadosFinais];
    for (int i = 0; i < qntdEstadosFinais; i++) {
        std::cin >> estadosFinais[i];
    }

    std::cin >> qntdTransicoes;
    //transicoes como vector
    std::vector<Transicoes> transicoes;
    for (int i = 0; i < qntdTransicoes; i++){
        //cria objeto de transição
        Transicoes a;
        std::cin >> a.estadoDePartida;
        std::cin >> a.estadoDeChegada;
        std::cin >> a.simboloDeEntrada;
        std::cin >> a.simboloDoTopoDaPilha;
        std::cin >> a.stringASerEscritaNoTopoDaPilha;
        transicoes.push_back(a);
    }

    std::cin >> stringEntrada;
    // MOSTRAR OS DADOS LIDOS

    // std::cout << "Qntd de estados: " << qntdEstados << std::endl;
    // std::cout << "Qntd de simbolos de entrada: " << qntdSimbolosEntrada << std::endl;
    // std::cout << "Simbolos de entrada: ";
    // for (int i = 0; i < qntdSimbolosEntrada; i++) {
    //     std::cout << simbolosEntrada[i] << " ";
    // }
    // std::cout << std::endl;
    // std::cout << "Qntd de simbolos do alfabeto: " << qntdSimbolosAlfabeto << std::endl;
    // std::cout << "Simbolos do alfabeto: ";
    // for (int i = 0; i < qntdSimbolosAlfabeto; i++) {
    //     std::cout << simbolosAlfabeto[i] << " ";
    // }
    // std::cout << std::endl;
    // std::cout << "Numero do estado inicial: " << numeroEstadoInicial << std::endl;
    // std::cout << "Simbolo inicial: " << SimboloInicial << std::endl;
    // std::cout << "Qntd de estados finais: " << qntdEstadosFinais << std::endl;
    // std::cout << "Estados finais: ";
    // for (int i = 0; i < qntdEstadosFinais; i++) {
    //     std::cout << estadosFinais[i] << " ";
    // }
    // std::cout << std::endl;
    // std::cout << "Qntd de transicoes: " << qntdTransicoes << std::endl;
    // for (int i = 0; i < qntdTransicoes; i++) {
    //     std::cout << "Transicao " << i << ": ";
    //     std::cout << "Estado de partida: " << transicoes[i].estadoDePartida << std::endl;
    //     std::cout << "Estado de chegada: " << transicoes[i].estadoDeChegada << std::endl;
    //     std::cout << "Simbolo de entrada: " << transicoes[i].simboloDeEntrada << std::endl;
    //     std::cout << "Simbolo do topo da pilha: " << transicoes[i].simboloDoTopoDaPilha << std::endl;
    //     std::cout << "String a ser escrita no topo da pilha: " << transicoes[i].stringASerEscritaNoTopoDaPilha << std::endl;
    // }


    std::cout << "(" << numeroEstadoInicial << "," << stringEntrada << ",";
    std::cout << print_stack(pilha) << ";";

    rodar(stringEntrada,transicoes,pilha, numeroEstadoInicial, estadosFinais, SimboloInicial);
    std:: cout << ")";
    if(aceito){
        std::cout<<std::endl<< "Aceita";
    }else{
        std::cout<<std::endl<< "Rejeita";
    }

    return 0;
}

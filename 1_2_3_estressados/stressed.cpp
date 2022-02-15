#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>



// Funções auxiliares

bool verificar_existencia(std::vector<int> vetor, int num){
    for( int i = 0; i < (int) vetor.size(); i++){
        if(num == vetor[i]){
            return true;
        }
    }
    
    return false;
}

bool verificar_repeticao(std::vector<int> vetor, int num){
    int rep{0};
    for( int i = 0; i < (int) vetor.size(); i++){
        if(num == vetor[i]){
            rep += 1;
        }
    }
    
    if( rep > 1){
        return true;
    }

    return false;

}

std::vector<int> vetor_abs(std::vector<int> vetor){
    std::vector<int> retorno{};
    for(int i = 0; i < (int) vetor.size(); i++){
        retorno.push_back( abs( vetor[i] ) );
    }

    return retorno;
}

int verificar_ocorrencias(std::vector<int> vetor){
    int retorno{0};
    for(int i = 0; i < (int) vetor.size(); i++){
    int qtd_rep{0};
        for(int a = 0; a < (int) vetor.size(); a++){
            if(vetor[i] == vetor[a]){
                qtd_rep += 1;
            }
            if(qtd_rep > retorno){
                retorno = qtd_rep;
            }
        }
    }
    return retorno;
}

std::vector<int> verificar_dois_mais_recorrentes(std::vector<int> vetor){
    sort(vetor.begin(), vetor.end());
    std::vector<int> retorno{0,0};
    int aux{0};


    for(int i = 0; i < (int) vetor.size(); i+=1 ){
        int conta{0};
        for(int a = 0; a < (int) vetor.size(); a+=1){
            if( vetor[i] == vetor[a]) {
                conta += 1;
            }                
        }
        if( conta >= aux && vetor[i] != retorno[0]){
            aux = conta;
            retorno[1] = retorno[0];
            retorno[0] = vetor[i];
        }
    }
    return retorno;
}

// --- BLOCO 1 ---
//funções de busca
bool existe( std::vector<int> vet ,int x ){

    for( int i = 0; i < (int) vet.size(); i++ )
        if(vet[i] == x)
            return(true);
    return false;
}

int contar( std::vector<int> vet, int x ){

    int cont = 0;
    for( int i = 0; i < (int) vet.size(); i++ )
        if( x == vet[i] )
            cont++;
    return cont;
} 

int procurar_valor( std::vector<int> vet, int x){

    for( int i = 0; i < (int) vet.size(); i++ )
        if( x == vet[i])
            return 1;
        else   
            return -1;
    return 0;
}

int procurar_valor_apos( std::vector<int> vet, int x, int pos_incial){

    for( int i = pos_incial; i < (int) vet.size(); i++ )
        if( x == vet[i])
            return i;
        else 
            return -1;

    return 0;
}

//funções de melhor caso
int procurar_menor( std::vector<int> vet ){

    int min = vet[0];

    for( int i = 0; i < (int) vet.size(); i++ )
        if(vet[i] < min)
            min = vet[i];
    return min;
}

int procurar_maior( std::vector<int> vet ){

    int max = vet[0];

    for( int i = 0; i < (int) vet.size(); i++ )
        if(vet[i] > max)
            max = vet[i];
    return max;
    
}

int procurar_menor_poss( std::vector<int> vet ){

    int poss = 0;

    for( int i = 0; i < (int) vet.size(); i++ )
        if(vet[i] < vet[poss]){
            poss = i;
        }
    return poss;
}

int procurar_menor_poss_apos( std::vector<int> vet, int apos_inicial){

    int poss = 0;

    for( int i = apos_inicial; i < (int) vet.size(); i++ )
        if(vet[i] < vet[poss]){
            poss = i;
        }
    return poss;
}

int procurar_melhor_se( std::vector<int> vet ){

    int min = vet[0];
    int cont = 0;

    for( int i = 0; i < (int) vet.size(); i++ ){
        if(cont == 0 && vet[i] > 0){
            cont = 1;
            min = vet[i];
        }
        else{
            if(vet[i] < min && vet[i] > 0){
                min = vet[i];
            }
        }
    }

            
    return min;
}

float calcular_stress_medio(std::vector<int> vet ){
    int soma = 0;
    
    for( int i =0; i < (int) vet.size(); i++ ){
        if( vet[i] < 0 ){
            vet[i] *= -1;
        }
        soma += vet[i];
    }

    return (soma/(int) vet.size());
}

std::string mais_homens_ou_mulheres(std::vector<int> vet){

    int mulheres = 0;

    for( int i = 0; i < vet.size(); i++){
        if( vet[i] < 0 ){
            mulheres++;
        }
    }

    if( mulheres == vet.size()/2){
        return "empate";
    }
    else{
        if ( mulheres > vet.size()/2){
            return "mulheres";
        }
        else {
            return "homens";
        }
    }
}

std::string qual_metade_eh_mais_estressad(std::vector<int> vet){

    int all = 0;
    int primeiro = 0;
    int segundo = 0;

    for( int i =0; i < (int) vet.size(); i++ ){
        if( vet[i] < 0 ){
            vet[i] *= -1;
        }
        
        all += vet[i];
        if( i < vet.size()/2 ){
            primeiro += vet[i];
        }
        else{
            segundo += vet[i];
        }
    }

    if( primeiro == segundo ){
        return "empate";
    }
    else{
        if( primeiro < segundo ){
            return "segunda";
        }
        else {
            return "primeira";
        }
    }

}

std::string homens_sao_mais_estressados_que_mulheres(std::vector<int> vet){
    int mulher = 0;
    int homem = 0;
    int cont_homem = 0;

    for( int i =0; i < (int) vet.size(); i++ ){
        if(vet[i] < 0){
            homem += vet[i];
            cont_homem++;
        }
        else{
            mulher += vet[i] * -1;
        }
    }

    if( (homem / cont_homem) == (mulher / ( (int) vet.size() - cont_homem ))){
        return "empate";
    }

    if( homem / cont_homem < mulher / ( (int) vet.size() - cont_homem )){
        return "não";
    }
    else{
        return "sim";
    }
    
}

// --- BLOCO 2 ---
std::vector<int> clone(const std::vector<int>& v){
    std::vector<int> aux;

    for( int i = 0; i < (int) v.size(); i++){
        aux.push_back(v[i]);
    }
    return aux;
}

std::vector<int> pegar_homens(const std::vector<int>& v){
    std::vector<int> aux;
    for( int i = 0; i < (int) v.size(); i++){
        if(v[i] > 0){
            aux.push_back(v[i]);
        }
    }
    return aux;


}

std::vector<int> pegar_calmos(const std::vector<int>& v){
    std::vector<int> aux;
    for( int i = 0; i < (int) v.size(); i++){
        if(abs(v[i]) <= 10){
            aux.push_back(v[i]);
        }
    }
    return aux;
}

std::vector<int> pegar_mulheres_calmas(const std::vector<int>& v){
    std::vector<int> aux;
    for( int i = 0; i < (int) v.size(); i++){
        if(v[i] < 0 && abs(v[i]) <= 10 ){
            aux.push_back(v[i]);
        }
    }
    return aux;
}

std::vector<int> inverter_com_copia(const std::vector<int>& v){
    std::vector<int> aux;

    for( int i = (int) v.size() -1; i >= 0; i--){
        aux.push_back(v[i]);
    }
    return aux;
}

void inverter_inplace(std::vector<int>& v){
    int aux{ v.size()-1 };
    int *p{};
    for( int i = aux; i >= 0; i--){
        p = &v[i];
        v.push_back(*p);
    }

    for( int i = 0; i < (int) v.size(); i++){
        v.erase(v.begin()+0);
    }

}

int sortear(const std::vector<int>& v){
    srand(time(NULL));
    int i { rand() % ( (int) v.size()-1) };

    return v[i];    
}

void embaralhar(std::vector<int>& v){
    for (int i = 0; i < (int) v.size(); i++){
       std::swap(v[i], v[rand() % (int) v.size()]);    
    }
}

void ordenar(std::vector<int>& v){
    sort(v.begin(), v.end());
}

std::vector<int> exclusivos(const std::vector<int>& v){
    std::vector<int> aux{};

    for( int i = 0; i < (int) v.size(); i++){
        if( !verificar_existencia(aux, v[i])){
            aux.push_back(v[i]);
        }
    }
    return aux;
}

std::vector<int> diferentes(const std::vector<int>& v){
    std::vector<int> aux{};

    for( int i = 0; i < (int) v.size(); i++){
        if( !verificar_existencia(aux, abs(v[i]))){
            aux.push_back(abs(v[i]));
          }
    }
    return aux;
}

std::vector<int> abandonados(const std::vector<int>& v){
    std::vector<int> aux{};

    for( int i = 0; i < (int) v.size(); i++){
        if( verificar_repeticao(v, v[i]) && !verificar_existencia(aux,v[i])){
            aux.push_back(v[i]);       
        }
    }
    return aux;
}
// --- BLOCO 3 ---
std::vector<int> sozinhos(const std::vector<int>& v){
    std::vector<int> v_abs{};    
    std::vector<int> aux{};

    for( int i : vetor_abs(v)){
        v_abs.push_back(i);        
    }

    for( int i = 0; i < (int) v_abs.size(); i++){
        if(!verificar_repeticao(v_abs, v_abs[i])){
            aux.push_back(v_abs[i]);
        }
    }


    return aux;
}

int mais_ocorrencias(std::vector<int> v){
    std::vector<int> vet{vetor_abs(v)};    
    return verificar_ocorrencias(vet);
}

std::vector<int> mais_recorrentes(std::vector<int> v){
    std::vector<int> vet{vetor_abs(v)};    
    return verificar_dois_mais_recorrentes(vet);
}

int briga(std::vector<int> v){
    std::vector<int> vetor_aux{vetor_abs(v)};
    int cont{0};

    for(int i = 1; i < (int) vetor_aux.size()-1; i+= 1){
            if(vetor_aux[i] > 50 && vetor_aux[i-1] > 30 && vetor_aux[i+1] > 30){
                cont += 1;
            }            
    }
    return cont;

}

std::vector<int> apaziguado( std::vector<int> v){
    std::vector<int> vetor_aux{vetor_abs(v)};
    std::vector<int> retorno{};
    
    if( vetor_aux[0] > 80 && vetor_aux[1] < 10){
        retorno.push_back(0);
    }
    if( vetor_aux[vetor_aux.size()-1] > 80 && vetor_aux[vetor_aux.size()-2] < 10){
        retorno.push_back(vetor_aux.size()-1);
    }

    for(int i = 1; i < (int) vetor_aux.size()-1; i+= 1){
        if(vetor_aux[i] > 80 && (vetor_aux[-1] < 10 || vetor_aux[+1] < 10)){
            retorno.push_back(i);
        }
    }

    return retorno;
}

int quantos_times(std::vector<int> v){
    int cont{0};
    for(int i = 0; i < (int) v.size()-1; ){
        if(v[i] < 0 && v[i+1] < 0){
            cont+=1;
            while(v[i] < 0){
                i+=1;
            }
        }
        else{
            if(v[i] > 0 && v[i+1] > 0){
                cont+=1;
                while(v[i] > 0){
                    i+=1;
                }
            }
            else{
                i++;
            }

        }

    }
    return cont;
}
        
int maior_time(std::vector<int> v){
 int cont{0};
 int aux{0};
    for(int i = 0; i < (int) v.size()-1; ){
        if(v[i] < 0 && v[i+1] < 0){
            while(v[i] < 0){
                i+=1;
                aux += 1;
            }
        }
        else{
            if(v[i] > 0 && v[i+1] > 0){
                while(v[i] > 0){
                    i+=1;
                    aux+=1;
                }
            }
            else{
                i++;
            }

        }
        if(aux > cont){
            cont = aux;
        }
        aux = 0;

    }
    return cont;
}

int sozinho(std::vector<int> v ){
 int cont{0};
 int aux{0};
    for(int i = 0; i < (int) v.size()-1; ){
        if(v[i] < 0 && v[i+1] < 0){
            while(v[i] < 0){
                i+=1;
                aux += 1;
            }
        }
        else{
            if(v[i] > 0 && v[i+1] > 0){
                while(v[i] > 0){
                    i+=1;
                    aux+=1;
                }
            }
            else{
                i++;
            }

        
        }
    cont += aux;
    aux = 0;

    }
    return (int) v.size() - cont;
}

std::vector<int> remove(std::vector<int> v, int pos){
    std::vector<int> retorno{};

    for(int i = 0; i < (int) v.size(); i++){
        if( i == pos){
            continue;
        }
        retorno.push_back(v[i]);
    }

    return retorno;
}

std::vector<int> insert(std::vector<int> v, int x, int y ){
    std::vector<int> retorno{};

    for(int i = 0; i < (int) v.size(); i++){
        if( i == x){
            continue;
        }
        if( i == y){
            retorno.push_back(v[x]);
        }
        retorno.push_back(v[i]);
    }

    return retorno;
}

std::vector<int> dance(std::vector<int> v ){
    for(int i = 0; i < (int) v.size()-1; i++){
        if(v[i] == v[i+1]){
            v.erase( v.begin()+i, v.begin()+i+2);
            v = dance(v);
        }
    }

    return v;
}


int main(){

    int x = -50;
    int pos_inicial = 3;
    int p = 3;
    

    std::vector<int> vetor{50, 98, 2, -50, -1, -99};
    // BLOCO 1
    //std::cin >> x ;
    std::cout << "existe: " << existe({-1, -50, -99, 80, 70, 90, -4}, x ) << "\n" ;
    std::cout << "contar: " << contar({-1, -50, -99, 80, 70, 90, -4}, x ) << "\n" ;
    std::cout << "procurar_valor: " << procurar_valor({-1, -50, -99, 80, 70, 90, -4}, x ) << "\n" ;
    std::cout << "procurar_valor_apos: " << procurar_valor_apos({-1, -50, -99, 80, 70, 90, -4}, x, pos_inicial ) << "\n" ;

    // Módulo de melhor caso
    std::cout << "procurar_menor: " << procurar_menor( {-1, -50, -99, 80, 70, 90, -4} ) << "\n" ;
    std::cout << "procurar_maior: " << procurar_maior( {-1, -50, -99, 80, 70, 90, -4} ) << "\n" ;
    std::cout << "procurar_menor_poss: " << procurar_menor_poss( {-1, -50, -99, 80, 70, 90, -4} ) << "\n" ;
    std::cout << "procurar_menor_poss_apos: " << procurar_menor_poss_apos( {-1, -50, -99, 80, 70, 90, -4},p ) << "\n" ;
    std::cout << "procurar_melhor_se: " << procurar_melhor_se( {-1, -50, -99, 80, 70, 90, -4} ) << "\n" ;

    // Módulo de contagem
    std::cout << "calcular_stress_medio: " << calcular_stress_medio( {-1, -50, -99, 80, 70, 90, -4} ) << "\n" ;
    std::cout << "mais_homens_ou_mulheres: " << mais_homens_ou_mulheres( {-1, -50, -99, 80, 70, 90, -4} ) << "\n" ;
    std::cout << "qual_metade_eh_mais_estressad: " << qual_metade_eh_mais_estressad( {5, 3, -1, -50, -1, -99} ) << "\n" ;
    std::cout << "homens_sao_mais_estressados_que_mulheres :" << homens_sao_mais_estressados_que_mulheres( {50, 98, 2, -50, -1, -99} ) << "\n" ;

    //BLOCO 2
    //Módulo de filtragem
    std::cout << "clone: ";
    for (int i : clone({50, 98, 2, -50, -1, -99})){
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "pegar_homens: ";
    for ( int i : pegar_homens({50, 98, 2, -50, -1, -99})){
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "pegar_mulheres_calmas: ";
    for ( int i : pegar_mulheres_calmas({50, 98, 2, -50, -1, -99})){
        std::cout << i << " ";
    }
    std::cout << "\n";
    //Módulo de acesso
    std::cout << "inverter_com_copia: ";
    for ( int i : inverter_com_copia({50, 98, 2, -50, -1, -99})){
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "inverter_inplace: ";
    inverter_inplace( vetor );
    for( int i = 0; i < (int) vetor.size(); i++){
        std::cout << vetor[i] << " ";
    }
    std::cout << "\n";

    std::cout << "sortear: ";
    std::cout << sortear( {50, 98, 2, -50, -1, -99}) << "\n";

    embaralhar( vetor );
    std::cout << "embaralhar: ";
    for( int i = 0; i < (int) vetor.size(); i++){
        std::cout << vetor[i] << " ";
    }
    std::cout << "\n";

    std::cout << "ordenar: ";
    ordenar( vetor );
    for( int i = 0; i < (int) vetor.size(); i++){
        std::cout << vetor[i] << " ";
    }
    std::cout << "\n";
    //Modulo de conjuntos
    std::cout << "exclusivos: ";
    for( int i :exclusivos( {1, 3, 4, 3, -1, -2, -2} )){
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "diferentes: ";
    for( int i :diferentes( {1, 3, 4, 3, -1, -2, -2} )){
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "abandonados: ";
    for( int i :abandonados( {1, 3, 4, 3, -1, -2, -2} )){
        std::cout << i << " ";
    }
    std::cout << "\n";

    //BLOCO 3

    std::cout << "sozinho: ";
    for( int i : sozinhos( {1, 3, 4, 3, -1, -2, -2} )){
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "mais_ocorrencias: " << mais_ocorrencias({1, 3, 4, 5, -1, -5, -5}) << "\n";

    std::cout << "mais_recorrentes: ";
    for( int i : mais_recorrentes({1, 3, 4, 5, -1, -5, -5, 3, -3})){
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "briga: " << briga( {50, -98, 31, -51, 31, -99} ) << "\n";

    std::cout << "apaziguado: ";
    for (int i : apaziguado( {83, -4, 65, 8, -99, 12 } ) ){
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "quantos_times: " << quantos_times({ 28, 26, 1, 6, 39} ) << "\n";

    std::cout << "maior_time: " << maior_time({-5, 3, 1, -15, -1, 99, -11, -1, -7 }) << "\n";

    std::cout << "sozinhos: " << sozinho({-5, 3, 1, 15, -1, -99, -11, -1, -7 }) << "\n";

    std::cout << "remove: ";
    for( int i : remove( {-5, 3, 1, 15, -1, -99, -11, -1, -7 }, 4)){
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "insert: ";
    for( int i : insert( {-5, 3, 1, 15, -1, -99, -11, -1, -7 }, 5, 4)){
        std::cout << i << " ";
    }
    std::cout << "\n";


    std::cout << "dance: ";
    for( int i : dance( {-5, 3, 1, 15, -99, -99, 15, -1, -7 })){
        std::cout << i << " ";
    }
    std::cout << "\n";    
}
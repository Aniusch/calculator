#include <stdio.h>
#include <stdlib.h>

//Gabriel Jose do Amaral Schuina
//RGA : 202121901017


//**** prototipos das funcoes ******

//determina a operacao e a chama  
void Operacao(); 

//operacoes
double Adicao(double x, double y);
double Subtracao(double x, double y);
double Multiplicacao(double x, double y);
double Divisao(double x, double y);
double Modulo(double x);
double Seno(double x);
double Cosseno(double x);
double Tangente(double x);
double Exponencial(double x, double y);
double ExponencialNatural(double x);
double RaizY(double x, double y);
double Log(double x, double y);
double Ln(double x);
double Fatorial(double x);

// *********************************

//driver code
int main()
{
    Operacao();
    return 0;
}

void Operacao(){    
    double x, y, resultado; // variaveis;
    char operacao; // armazena a operacao do usuario
    scanf("%c", &operacao);//recebe a operacao do usuario
    switch (operacao) //chama a operacao com base no input do usuario
    {
    case '+':
        scanf("%lf", &x);
        scanf("%lf", &y);
        resultado = Adicao(x, y);
        printf("%.2f", resultado);
        break;
    
    case '-':
        scanf("%lf", &x);
        scanf("%lf", &y);
        resultado = Subtracao(x, y);
        printf("%.2f", resultado);
        break;
    
    case '*':
        scanf("%lf", &x);
        scanf("%lf", &y);
        resultado = Multiplicacao(x, y);
        printf("%.2f", resultado);
        break;

    case '/':
        scanf("%lf", &x);
        scanf("%lf", &y);
        resultado = Divisao(x, y);
        printf("%.2f", resultado);
        break;
    
    case 'm':
        scanf("%lf", &x);
        resultado = Modulo(x);
        printf("%.2f", resultado);
        break;
    
    case 's':
        scanf("%lf", &x);
        resultado = Seno(x);
        printf("%.2f", resultado);
        break;
    
    case 'c':
        scanf("%lf", &x);
        resultado = Cosseno(x);
        printf("%.2f", resultado);
        break;
    
    case 't':
        scanf("%lf", &x);
        resultado = Tangente(x);
        printf("%.2f", resultado);
        break;
    
    case 'e':
        scanf("%lf", &x);
        scanf("%lf", &y);
        if(y < 0 && x == 0){ //nao aceita
            break; 
        }
        else{
            resultado = Exponencial(x, y);
        	printf("%.2f", resultado);
            break;
        }
        

    case 'n':
        scanf("%lf", &x);
        resultado = ExponencialNatural(x);
        printf("%.2f", resultado);
        break;

    case 'r':
        scanf("%lf", &x);
        scanf("%lf", &y);
        if(x <= 0 || y <= 0){ //nao aceita
            break;
        }
        resultado = RaizY(x, y);
        printf("%.2f", resultado);
        break;

    case 'l':
        scanf("%lf", &x);
        scanf("%lf", &y);
        if (x < 0 || y < 0){ //nao aceita
            break;
        }
        
        resultado = Log(x, y);
        printf("%.2f", resultado);
        break;

    case 'g':
        scanf("%lf", &x);
        if(x <= 0){ //nao aceita
            break;
        }
        resultado = Ln(x);
        printf("%.2f", resultado);
        break;

    case 'f':
        scanf("%lf", &x);
        if(x < 1){ //nao aceita negativo
            break;
        }
        else{
            resultado = Fatorial(x);
            printf("%.2f", resultado);
            break;
        }
    default:
        break;
    }
}

/*Vale destacar, antes de continuar, que era possivel reduzir os FOR LOOPS
usando uma recorrencia na funcao, onde retornaria um valor e chamaria a funcao com aquele novo valor.
Contudo, optei por nao usar, para deixar todos os passos mais claros.*/


/*Do mesmo modo, operaçoes tem suas variaveis, quando necessario, iniciadas em 0.
 Isso se da pois, nas operacoes de tangente por exemplo, 
 a funcao Cosseno(x) eh chamada depois da funcao Seno(x) e caso a variavel que realizara o somatorio
 nao seja iniada em zero, o valor da funcao passada de x, Seno(x), vaza para a funcao Cosseno(x) e eh somada no final. */

double Adicao(double x, double y){
    return x + y; //operacao
}
double Subtracao(double x, double y){
    return x - y; //operacao
}
double Multiplicacao(double x, double y){
    return x * y; //operacao
}
double Divisao(double x, double y){
    return x / y; //operacao
}
double Modulo(double x){
    double modulo;
    
    if(x >= 0){  //operacao
       modulo = x; // caso for positivo, ou igual a zeor, o resultado é x
    }
    else{
        modulo = x * (-1); // caso for negativo
    }
    return modulo;
}
double Seno(double x){
    double i = 0;
    double seno = 0;
    double k = 20;

    for(i = 0; i <= k; ++i){
        seno += Exponencial((-1), i) / Fatorial(2 * i + 1) * Exponencial(x, 2 * i + 1);
    }
    return seno;
}
double Cosseno(double x){
    double i = 0;
    double cosseno = 0;
    double k = 20;

    for(i = 0; i <= k; ++i){
        cosseno += Exponencial(-1, i) / Fatorial(2 * i) * Exponencial(x, 2 * i);
    }
    return cosseno;
}
double Tangente(double x){
    double cosseno, seno;
    seno = Seno(x);
    cosseno = Cosseno(x);

    return seno / cosseno; // operacao
}

// vale ressaltar que essa funcao eh limitada a y inteiro. 
// mas como nao foi requisitado nas guidelines do projeto
// o caso de y ser um float
double Exponencial(double x, double y){ 
    double i = 1; 
    double exponencial = 1;

    if(y < 0){
        y = -1 * y;  // Modulo(y)
        x = 1.0 / x; 
        for(i = 1; i <= y; ++i){ //operacao
        exponencial *= x;}

        return  exponencial;
    }
    else if(y == 0){
        return 1;
    }
    else if(y == 1){
        return x;
    }
    else{
        for(i = 1; i <= y; ++i){ //operacao
        exponencial *= x;}
        
        return exponencial;
    }
}
double ExponencialNatural(double x){
    double k = 20;
    double i = 0;
    double expNatural = 0;

    for(i = 0; i <= k; ++i){ // operacao
        expNatural += Exponencial(x, i) / Fatorial(i);
    }

    return expNatural;
}
double RaizY(double x, double y){
    double lnX = Ln(x);
    
    return ExponencialNatural(lnX / y); //operacao
}
double Log(double x, double y){
    //realiza as operacoes de logaritmo natural de x e de y

    return Ln(x) / Ln(y); // operacao
}
double Ln(double x){
    double i = 0;
    double ln = 0;
    double k = 20;

    for(i = 0; i <= k; ++i){ //operacao
        ln += 1 / (2 * i + 1) * Exponencial((x - 1)/(x + 1), 2 * i + 1);
    }

    return 2 * ln;
}
double Fatorial(double x){

    double i = 1; // para iteracao
    double fatorial = 1; // fatorial = 1 para tornar possivel a multiplicacao

    for(i = 1; i <= x; ++i){ //operacao
        fatorial *= i;
    }
    
    return fatorial;
}
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

//alguem me ajuda aaaaaaaaaaaaaaaaaaaaaaa
void imprimir_tabuleiro(std::vector<std::vector<char>> tabuleiro){
    system("cls");
    for(int i = -1; i<3;i++){
        for(int j = -1; j<3;j++){
                if(i<0&&j<0) std::cout<<"# ";
                 else if(i<0) std::cout<<" "<<j+1;
                 else if(j<0) std::cout<<i+1<<"  ";
                 else std::cout<<tabuleiro.at(i).at(j)<<"";
                 if(j>-1&&j<2&&i>-1) std::cout<<"|";
        }if(i<2&&i>-1)std::cout<<"\n  -------  \n"; else std::cout<<"\n";
        }

}
int verificar_win(std::vector<std::vector<char>> tabuleiro){

    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] == 'X')
            return 1;
    }


    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j] && tabuleiro[0][j] == 'X')
            return 1;
    }

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] == 'X')
        return 1;
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] == 'X')
        return 1;

         for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] == 'O')
            return 2;
    }


    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j] && tabuleiro[0][j] == 'O')
            return 2;
    }

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] == 'O')
        return 2;
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] == 'O')
        return 2;

    return 0;
}
int jogo(int modo){
    std::srand(time(0));
    std::vector<std::vector<char>> tabuleiro {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int pos_X, pos_Y,jogador_cont=0;

        int joga_p = 1;


    while(true){
             if (modo==0){
        imprimir_tabuleiro(tabuleiro);
            if(joga_p==0){
                    if(jogador_cont%2==0){
                std::cout<<"jogador\nx:";
                std::cin>>pos_X;
                std::cout<<"y:";
                std::cin>>pos_Y;
                if(pos_X<1||pos_X>3||pos_Y<1||pos_Y>3) continue;
            if(jogador_cont>=9){
                std::cout<<"empate!!\n";
                break;}
            if(tabuleiro[pos_Y-1][pos_X-1]!=' ') continue;
            tabuleiro[pos_Y-1][pos_X-1] = 'X';
            if(verificar_win(tabuleiro)==1){
                std::cout<<"jogador ganhou!!!\n";
                imprimir_tabuleiro(tabuleiro);
                break;}
            if(verificar_win(tabuleiro)==2){
                std::cout<<"computador ganhou!!!\n";
                imprimir_tabuleiro(tabuleiro);
                break;}
            jogador_cont++;
                    }
                if(jogador_cont%2==1){
            pos_X = std::rand()%3;
            pos_Y = std::rand()%3;


            if(pos_X<0||pos_X>2||pos_Y<0||pos_Y>2) continue;
            if(tabuleiro[pos_Y][pos_X]!=' ') continue;
            tabuleiro[pos_Y][pos_X] = 'O';
            if(verificar_win(tabuleiro)==1){
                std::cout<<"jogador ganhou!!!\n";
                imprimir_tabuleiro(tabuleiro);
                break;}
            if(verificar_win(tabuleiro)==2){
                std::cout<<"computador ganhou!!!\n";
                imprimir_tabuleiro(tabuleiro);
                break;}
            jogador_cont++;


            }
            }
                else{
                        if(jogador_cont%2==0){
            pos_X = std::rand()%3;
            pos_Y = std::rand()%3;


            if(pos_X<0||pos_X>2||pos_Y<0||pos_Y>2) continue;
            if(tabuleiro[pos_Y][pos_X]!=' ') continue;
            tabuleiro[pos_Y][pos_X] = 'X';
            imprimir_tabuleiro(tabuleiro);
            if(verificar_win(tabuleiro)==1){
                std::cout<<"jogador ganhou!!!\n";
                imprimir_tabuleiro(tabuleiro);
                break;}
            if(verificar_win(tabuleiro)==2){
                std::cout<<"computador ganhou!!!\n";
                imprimir_tabuleiro(tabuleiro);
                break;}
            jogador_cont++;

                }
                if(jogador_cont%2==1){
                std::cout<<"jogador\nx:";
                std::cin>>pos_X;
                std::cout<<"y:";
                std::cin>>pos_Y;
                if(pos_X<1||pos_X>3||pos_Y<1||pos_Y>3) continue;
            if(jogador_cont>=9){
                std::cout<<"empate!!\n";
                break;}
            if(tabuleiro[pos_Y-1][pos_X-1]!=' ') continue;
            tabuleiro[pos_Y-1][pos_X-1] = 'O';
            if(verificar_win(tabuleiro)==1){
                std::cout<<"jogador ganhou!!!\n";
                imprimir_tabuleiro(tabuleiro);
                break;}
            if(verificar_win(tabuleiro)==2){
                std::cout<<"computador ganhou!!!\n";
                imprimir_tabuleiro(tabuleiro);
                break;}
            jogador_cont++;
                    }


             }}



            if (modo==1){
        imprimir_tabuleiro(tabuleiro);



        std::cout<<"jogador "<<1+(jogador_cont%2!=0)<<"\n";
        std::cout<<"x:";
        std::cin>>pos_X;
        std::cout<<"y:";
        std::cin>>pos_Y;

            if(pos_X<1||pos_X>3||pos_Y<1||pos_Y>3) continue;
            if(jogador_cont>=9){
                std::cout<<"empate!!\n";
                break;}
            if(tabuleiro[pos_Y-1][pos_X-1]!=' ') continue;
            if(jogador_cont%2==0)tabuleiro[pos_Y-1][pos_X-1] = 'X';
            if(jogador_cont%2!=0)tabuleiro[pos_Y-1][pos_X-1] = 'O';
        jogador_cont++;
        imprimir_tabuleiro(tabuleiro);
            if(verificar_win(tabuleiro)==1){
                std::cout<<"jogador 1 ganhou!!!\n";
                break;}
            if(verificar_win(tabuleiro)==2){
                std::cout<<"jogador 2 ganhou!!!\n";
                break;}
    }
    }

return 0;
}

int main(){
    std::cout<<"deseja jogar?s/n\n";
    while(std::cin.get()=='s'||std::cin.get()=='S'){
            std::cout<<"computador(0)\n2 jogadores(1)\n->";
    int modo = 0;
    std::cin>>modo;
        jogo(modo);
            std::cout<<"deseja jogar novamente?s/n\n";
    }
}

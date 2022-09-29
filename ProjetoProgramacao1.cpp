#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

//Classe Mapa
class Maps{

    public:	
        char maps[75][75];
        int portali, portalj;//portal
        int portali2, portalj2;//2portal ou portal de destino
        int i,j;
        bool final=false;
		bool porta=false;
        bool chave=false;
        bool bot=false;//botao
        int tam=20;
        
		//Mapa
        void imprimir1(int& peri, int& perj);
       
};

//Classe Player
class Player{
    private:

    public:
        char ordem;
        int vida=3;
        int i=10,j=10;

        void Movimento(Maps& maps1);
        
};


int main()
{
	Maps maps;
	Player Tobias;

	Tobias.i=10;
    Tobias.j=10;
	
    while(Tobias.vida!=0 and maps.final==0)
	{
        int opcao;
    	inicio:
    	
    	cout <<"1 - JOGAR \n2 - TUTORIAL \n3 - CREDITOS \n4 - SAIR\n";
    	cin >> opcao;
    
        switch(opcao) 
		{
    	case 1:
        	cout << "GAME\n";
        	//fase 1
        	//fase 2
        	//fase 3
        	//vitoria 
        	//derrota
        	maps.imprimir1(Tobias.i, Tobias.j);
        	Tobias.Movimento(maps);
        	break;
    	case 2:
        	cout << "TUTORIAL\n";
        	cout << "O jogador sera representado por esse simbolo: &\n";
        	//system("cls");
        	
        	cout << "Movimentacao/n W para andar pra cima\n";
        	cout << "A para andar pra direita\n";
        	cout << "D para andar pra esquerda\n";
        	cout << "S para andar pra baixo\n";
        	//system("cls");
        	cout << "I: O jogador interage com o objeto que ele estar em cima\n";
        	cout << "A chave sera representada por: @";
        	cout << "\nA porta fechada sera representada por: D";
        	cout << "\nA porta aberta sera representada por: =";
        	cout << "\nO:Simbolo que representa um botão que o usuário pode interagir, o botão fica no chão e o jogador deve ficar em cima dele para poder interagir";
        	cout << "\n#: Simbolo que representa um espinho";
        	cout << "\n>: Simbolo que representa um teletransporte. O teletransporte sempre deve vir em par, quando o jogador toca em um ele é transportado para o outro e vice-versa.";
        	//system("cls");
			cout << "Precione qualquer tecla para voltar ao menu\n";
        	system("pause");
        	goto inicio;
        	
    	case 3:
        	cout << "Creditos\n";
  			cout << "Criadores : Pedro Gabriel\nThomas Coutinho\n";
        	goto inicio;
        	
    	case 4:
        	cout << "voce pediu para sair, prencione qualquer tecla para continuar\n";
        	break;
    	default:
        	cout << "voce deve escolher uma opcao valida\n";
        	cout << "Precione qualquer tecla para voltar ao menu\n";
        	system("pause");
        	goto inicio;
    	}
        
    }
}

//MOVIMENTAÇÃO
void Player::Movimento(Maps& maps){
	
    cout<<"\t\t\t\t\t\t\tVIDAS: "<<vida<<" BOTAO: "<<maps.bot<<" CHAVE: "<<maps.chave<<" porta: "<<maps.porta<<endl;
    cout<<"\t\t\t\t\t\t\t>";
    //cout << "\t\t>";
    cin>>ordem;

    switch(ordem){
        //andanto pra cima
        case 'W':
        case 'w':
        	switch(maps.maps[i-1][j]){
        		//verificação de porta e parede
        		case '*':
				case 'D':
				case '@':
				case '|':
				case '!':
        			i=i;
        			break;
        		
        		//espinho
        		case '#':
        			i=i;
                    vida=vida-1;
                    maps.porta=false;
                    maps.bot=false;
                    maps.chave=false;
                    i=maps.tam/2;
                    j=maps.tam/2;
					sleep(2);
        			break;
        		
        		//Botão
        		case 'O':
        			i=i-1;
                    maps.bot=true;
        			break;
        		
        		//Portal 1
        		case '>':
        			i=maps.portali2-1;
                	j=maps.portalj2;
                	break;
                
                //Portal 2
                case '<':
                	i=maps.portali-1;
                	j=maps.portalj;
                	break;
                
                default:
                	i=i-1;
        		}
			break;
		
		
        //andar pra baixo
        case 'S':
        case 's':
        	switch(maps.maps[i+1][j]){
        		//verificação de porta e parede
        		case '*':
				case 'D':
				case '@':
				case '|':
				case '!':
        			i=i;
        			break;
        			
        		//espinho 
        		case '#':
        			i=i;
                    vida=vida-1;
                    maps.porta=false;
                    maps.bot=false;
                    maps.chave=false;
                    i=maps.tam/2;
                    j=maps.tam/2;
					sleep(2);
                    break;
                    
                //Botão
                case 'O':
                	i=i+1;
                    maps.bot=true;
                    break;
                    
                //Portal 1
                case '>':
                	i=maps.portali2+1;
                	j=maps.portalj2;
                	break;
                	
                //Portal 2
                case '<':
                	i=maps.portali+1;
                	j=maps.portalj;
                	break;
                
                default:
                	i=i+1;
			}
			break;
		
		
        //andanto pra esquerdo
        case 'A':
        case 'a':
        	switch(maps.maps[i][j-1]){
        		//verificação de porta e parede
        		case '*':
				case 'D':
				case '@':
				case '|':
				case '!':
        			j=j;
        			break;
        		
        		//espinho
        		case '#':
        			j=j;
                    vida=vida-1;
                    maps.porta=false;
                    maps.bot=false;
                    maps.chave=false;
                    i=maps.tam/2;
                    j=maps.tam/2;
					sleep(2);
        			break;
        			
        		//Botao
        		case 'O':
        			j=j-1;
                    maps.bot=true;
        			break;
        	
        		//Portal 1
        		case '>':
        			i=maps.portali2;
                	j=maps.portalj2-1;
        			break;
        			
        		//Portal 2
        		case '<':
        			i=maps.portali;
                	j=maps.portalj-1;
        			break;
        			
        		default:
        			j=j-1;
			}
			break;


        //andanto pra direita
        case 'D':
        case 'd':
        	switch(maps.maps[i][j+1]){
        		//Porta ou parede
        		case '*':
				case 'D':
				case '@':
				case '|':
				case '!':
        			j=j;
        			break;
        		
				//espinho
        		case '#':
        			j=j;
                    vida=vida-1;
                    maps.porta=false;
                    maps.bot=false;
                    maps.chave=false;
                    i=maps.tam/2;
                    j=maps.tam/2;
					sleep(2);
        			break;
        		
        		//Botão
        		case 'O':
        			j=j+1;
                    maps.bot=true;
        			break;
        		
        		//Portal 1
        		case '>':
        			i=maps.portali2;
              		j=maps.portalj2+1;
        			break;
        		
        		//Portal 2
        		case '<':
        			i=maps.portali;
              		j=maps.portalj+1;
        			break;
				
				default:
					j=j+1;	
			}
			//player interção    
        	case 'I':
        	case 'i':
        	//interação chave
			if(maps.maps[i-1][j]=='@' or maps.maps[i+1][j]=='@' or maps.maps[i][j-1]=='@' or maps.maps[i][j+1]=='@')
			{
				maps.chave=true;
        	}
            break;
}
}

void Maps::imprimir1(int& peri, int& perj)
{
    for(i=0;i<tam;i++){
				cout<<"\t\t\t\t\t\t\t";
            for(j=0;j<tam;j++){
            	
                //Jogador plotado no mapa
                if(peri==i and perj==j){
                    maps[i][j]='&';
                    cout<<maps[i][j]<<" ";
                    
                    if(peri==15 and perj==11){
                    	final=true;
					}
                    
                }
                
                

                //Delimitação do mapa
                else if(i==0 or i==tam-1 or j==0 or j==tam-1){
                    maps[i][j]='*';
                    cout<<maps[i][j]<<" ";
                }

                //Parede da sala esquerdo-superior
                else if( (i==(tam-4)/2 and j<(tam-2)/2) or (i<(tam-2)/2 and i==(tam-4)/2) ){
                    
                    //PORTA FECHADA
                    if(i==(tam-4)/4 and j==(tam-4)/2 and bot==false){
                        maps[i][j]='D';
                        cout<<maps[i][j]<<" ";
                    }

                    //PORTA ABERTA
                    else if(i==(tam-4)/4 and j==(tam-4)/2 and bot==true){
                        maps[i][j]='=';
                        cout<<maps[i][j]<<" ";
                    }

                    else{
                    maps[i][j]='*';
                    cout<<maps[i][j]<<" ";
                    }

                }

                //Parede da sala direita-superior
                else if( (i<=(tam-4)/2 and j==(tam+2)/2) or (i==(tam-4)/2 and j>(tam+2)/2) ){
                    
                    //PORTA ABERTA
                    if(i==(tam-4)/2 and j==(tam+4)/2){
                        maps[i][j]='=';
                        cout<<maps[i][j]<<" ";
                    }
                    else{
                    maps[i][j]='*';
                    cout<<maps[i][j]<<" ";
                    }
                }

                //Parede da sala esquerdo-inferior
                else if( (i==(tam+2)/2 and j<=(tam-4)/2) or (i>(tam+2)/2 and j==(tam-4)/2) ){
                    
					maps[i][j]='*';
                    cout<<maps[i][j]<<" ";
                }

                //Parede da sala direita-inferior
                else if( (i==(tam+2)/2 and j>=(tam+2)/2 ) or (i>=(tam+2)/2 and j==(tam+2)/2)){
                    
					if(i==15 and j==11 and porta==false){
						maps[i][j]='D';
                    	cout<<maps[i][j]<<" ";
					}
					
					else if(i==15 and j==11 and porta==true){
						maps[i][j]='=';
                    	cout<<maps[i][j]<<" ";
					}
					
					else{
						
						maps[i][j]='*';
                    	cout<<maps[i][j]<<" ";
                	}
                }

                //Interior da sala direita-superior
                else if(i>0 and i<(tam-4)/2 and j>(tam+2)/2 and j<tam){
                    //Labirinto de Cacto
                    if((j==tam-7 and i>1) or (j==tam-3 and i>1) or (j==tam-5 and i<(tam+1)/3)){
                        maps[i][j]='#';
                        cout<<maps[i][j]<<" ";
                    }
                    //Botão
                    else if(i==tam-13 and j==tam-2){
                        maps[i][j]='O';
                        cout<<maps[i][j]<<" ";
                    }
                    //Vazio do mapa
                    else{
                        maps[i][j]=' ';
                        cout<<maps[i][j]<<" ";
                    }
                }

                //Interior da sala esquerda-superior
                else if(i>0 and i<(tam-4)/2 and j>0 and j<(tam-4)/2){
                    
                    //PORTAL 1
                    if(i==tam/5 and j==tam/5){
                    	portali=tam/5;
                    	portalj=tam/5;
                        maps[i][j]='>';
                        cout<<maps[i][j]<<" ";
                    }
					
                    //Vazio do mapa
                    else{
                        maps[i][j]=' ';
                        cout<<maps[i][j]<<" ";
                    }

                }

                //Interior da sala esquerda-inferior
                else if(i>tam-9 and i<tam and j>0 and j<(tam-4)/2){
                    
                    //PORTAL 2
                    if(i==tam-5 and j==tam-16){
                    	portali2=tam-5;
                    	portalj2=tam-16;
                        maps[i][j]='<';
                        cout<<maps[i][j]<<" ";
                    }
					
					//CHAVE
					else if(i==tam-3 and j==tam-16 and chave==false){
						maps[i][j]='@';
                        cout<<maps[i][j]<<" ";
					}
                    //Vazio do mapa
                    else{
                        maps[i][j]=' ';
                        cout<<maps[i][j]<<" ";
                    }

                }
                //Restante do mapa
                else{
                    maps[i][j]=' ';
                    cout<<maps[i][j]<<" ";
                }

            }

            cout<<"\n";
        }


}

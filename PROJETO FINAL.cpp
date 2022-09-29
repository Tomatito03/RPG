#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>

using namespace std;




class Maps{

    public:	
        char maps[75][75];
        int portali, portalj;
        int portali2, portalj2;
        int i,j;
        bool final=false;
		bool porta=false;
        bool chave=false;
        bool bot=false;
        int tam=20;
        
		
        void imprimir1(int& peri, int& perj);
       
};


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
	//menu principal
    int opcao;
    inicio:
    
    system("cls");
    system("color 0F");
    cout << "Bem vindo a Redem Blaze!";
    cout << "\n\nSelecione uma das opcoes abaixo: ";
    cout << "\n1- Jogar \n2- Tutorial \n3- Creditos \n4- Sair\n";
    cout << "\nEscolha: ";
    cin >> opcao;
    switch(opcao) 
	{
    	case 1: {
    		system("cls");
			Maps maps;
			Player Tobias;
	

			Tobias.i=10;
    		Tobias.j=10;
	
	
   			while(Tobias.vida!=0 and maps.final==0)
			{
				system("color 0F");
				system("cls");
        		maps.imprimir1(Tobias.i, Tobias.j);
        		Tobias.Movimento(maps);
  			}
  			
  			
  			if (Tobias.vida == 0) // tela de game over
  			{	
  				telagameover:
  					
  				int choice;
  				system("color 0F");
  				cout << "\nGAME OVER!";
				cout << "\n\nPressione 1 se voce deseja voltar ao menu principal e 2 se voce deseja sair do jogo.\n";  
				cin >> choice;
				
				
				switch (choice)
				{
					case 1:
					{
						goto inicio;
					}	
					
					
					
					case 2: 
					{
						cout << "Adeus, foi bom ter voce por aqui! Pressione qualquer tecla para continuar.\n";
						break;
					}
					
					
					default:
						{
							cout << "\nPor favor, selecione uma opcao valida.\n";
							goto telagameover;
						}
					
					
				}	
			}
			
			
			
			while(Tobias.vida!=0){
				
				
				
			}
			
		}
			
			
        	
    	case 2: {
        	cout << "\n\nTUTORIAL DE CONTROLES E REPRESENTACOES\n";
        	cout << "\n&: Simbolo que representa a posicao do jogador.";
        	
        	cout << "\n\nMovimentacao:\n\nPressione W para andar para cima;\n";
        	cout << "Pressione A para andar para a direita;\n";
        	cout << "Pressione D para andar para a esquerda;\n";
        	cout << "Pressione S para andar para baixo.\n\n";
        	cout << "Pressione I para interagir com os objetos do jogo."; 
        	cout << "\n\nAs chaves sao representadas por @.";
        	cout << "\nAs portas fechadas sao representada por D.";
        	cout << "\nAs portas, quando abertas, sao representadas por =.";
        	cout << "\n\nO: Simbolo que representa um botao de interacao ao usuario (o botao se encontra no chao e o jogador deve estar sobre ele para poder interagir)";
        	cout << "\n#: Simbolo que representa os espinhos (caso o jogador encoste em um deles, perdera uma vida)."; 
        	cout << "\n>: Simbolo que representa um terminal de teletransporte. Ele sempre estara acompanhado por um outro mesmo simbolo, sendo este o local de destino do teletransporte.";
			cout << "\n\nPressione qualquer tecla para voltar ao menu.\n";
        	system("pause");
        	system("cls");
        	goto inicio;
        }
        	
        	
        	
    	case 3: {		
        	cout << "\n\nCREDITOS: \n";
  			cout << "\nCriadores do jogo: \nPedro Gabriel\nThomas Coutinho\nJoao Victor Portela\nAugusto Dutra\nEnzo Souza\n\n";
  			cout << "Pressione qualquer tecla para voltar ao menu principal.\n";
  			system("pause");
  			system("cls");
  			goto inicio;
  		}
  			
  			
        	
    	case 4:{
    		system("cls");
        	cout << "Adeus, foi bom ter voce por aqui! Pressione qualquer tecla para continuar.\n";
        	break;
        }
        	
        	
        	
    	default: {
        	cout << "\nPor favor, selecione uma opcao valida.\n";
        	cout << "Pressione qualquer tecla para voltar ao menu principal do jogo.\n\n";
        	system("pause");
        	system("cls");
        	goto inicio;
    	}
    }
	
	
	
}


//MOVIMENTACAO
void Player::Movimento(Maps& maps){
	
    cout<<"\t\t\t\t\t\t\t\t\t\tVIDAS: "<<vida<<" BOTAO: "<<maps.bot<<" CHAVE: "<<maps.chave<<" porta: "<<maps.porta<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t>";
    cin>>ordem;

    switch(ordem){
        
        case 'W':
        case 'w':
        	switch(maps.maps[i-1][j]){
        		
        		case '*':
				case 'D':
				case '@':
				case '|':
				case '!':
        			i=i;
        			break;
        		
        		//espinho
        		case '#':
        			system("color 4C");
        			system("pause");
        			i=i;
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
        			i=i-1;
                    maps.bot=true;
        			break;
        		
        		
        		case '>':
        			i=maps.portali2-1;
                	j=maps.portalj2;
                	break;
                
               
                case '<':
                	i=maps.portali-1;
                	j=maps.portalj;
                	break;
                
                default:
                	i=i-1;
        		}
			break;
		
		
        
        case 'S':
        case 's':
        	switch(maps.maps[i+1][j]){
        		
        		case '*':
				case 'D':
				case '@':
				case '|':
				case '!':
        			i=i;
        			break;
        			
        		//espinho 
        		case '#':
        			system("color 4C");
        			system("pause");
        			i=i;
                    vida=vida-1;
                    maps.porta=false;
                    maps.bot=false;
                    maps.chave=false;
                    i=maps.tam/2;
                    j=maps.tam/2;
					sleep(2);
                    break;
                    
                
                case 'O':
                	i=i+1;
                    maps.bot=true;
                    break;
                    
                
                case '>':
                	i=maps.portali2+1;
                	j=maps.portalj2;
                	break;
                	
                
                case '<':
                	i=maps.portali+1;
                	j=maps.portalj;
                	break;
                
                default:
                	i=i+1;
			}
			break;
		
		
       
        case 'A':
        case 'a':
        	switch(maps.maps[i][j-1]){
        		
        		case '*':
				case 'D':
				case '@':
				case '|':
				case '!':
        			j=j;
        			break;
        		
        		//espinho
        		case '#':
        			system("pause");
        			j=j;
                    vida=vida-1;
                    maps.porta=false;
                    maps.bot=false;
                    maps.chave=false;
                    i=maps.tam/2;
                    j=maps.tam/2;
					sleep(2);
        			break;
        			
        		
        		case 'O':
        			j=j-1;
                    maps.bot=true;
        			break;
        	
        		
        		case '>':
        			i=maps.portali2;
                	j=maps.portalj2-1;
        			break;
        			
        		
        		case '<':
        			i=maps.portali;
                	j=maps.portalj-1;
        			break;
        			
        		default:
        			j=j-1;
			}
			break;


        
        case 'D':
        case 'd':
        	switch(maps.maps[i][j+1]){
        		
        		case '*':
				case 'D':
				case '@':
				case '|':
				case '!':
        			j=j;
        			break;
        		
				// espinho
        		case '#':
        			system("color 4C");
        			system("pause");
        			j=j;
                    vida=vida-1;
                    maps.porta=false;
                    maps.bot=false;
                    maps.chave=false;
                    i=maps.tam/2;
                    j=maps.tam/2;
					sleep(2);
        			break;
        		
        		
        		case 'O':
        			j=j+1;
                    maps.bot=true;
        			break;
        		
        		
        		case '>':
        			i=maps.portali2;
              		j=maps.portalj2+1;
        			break;
        		
        		
        		case '<':
        			i=maps.portali;
              		j=maps.portalj+1;
        			break;
				
				default:
					j=j+1;	
			}
			   
        	case 'I':
        	case 'i':
        	
			if(maps.maps[i-1][j]=='@' or maps.maps[i+1][j]=='@' or maps.maps[i][j-1]=='@' or maps.maps[i][j+1]=='@')
			{
				maps.chave=true;
				maps.porta=true;
        	}
            break;
}
}

void Maps::imprimir1(int& peri, int& perj)
{
    for(i=0;i<tam;i++){
				cout<<"\t\t\t\t\t\t\t\t\t\t"; // 10  barra t
            for(j=0;j<tam;j++){
            	
                
                if(peri==i and perj==j){
                    maps[i][j]='&';
                    cout<<maps[i][j]<<" ";
                    
                    if(peri==15 and perj==11){
                    	final=true;
					}
                    
                }
                
                

                
                else if(i==0 or i==tam-1 or j==0 or j==tam-1){
                    maps[i][j]='*';
                    cout<<maps[i][j]<<" ";
                }
				
				
                
                else if( (i==(tam-4)/2 and j<(tam-2)/2) or (i<(tam-2)/2 and i==(tam-4)/2) ){
                    
                    
                    if(i==8 and j==5 and bot==false){
                        maps[i][j]='D';
                        cout<<maps[i][j]<<" ";
                    }

                    
                    else if(i==8 and j==5 and bot==true){
                        maps[i][j]='=';
                        cout<<maps[i][j]<<" ";
                    }
					
					else if(i==8 and j==12){
						maps[i][j]='=';
                    	cout<<maps[i][j]<<" ";
					}
					
                    else{
                    maps[i][j]='*';
                    cout<<maps[i][j]<<" ";
                    }

                }
                

                
                else if( (i<=(tam-4)/2 and j==(tam+2)/2) or (i==(tam-4)/2 and j>(tam+2)/2) ){
                    
                    
                    if(i==(tam-4)/2 and j==(tam+4)/2){
                        maps[i][j]='=';
                        cout<<maps[i][j]<<" ";
                    }
                    else{
                    maps[i][j]='*';
                    cout<<maps[i][j]<<" ";
                    }
                }

                
                else if( (i==(tam+2)/2 and j<=(tam-4)/2) or (i>(tam+2)/2 and j==(tam-4)/2) ){
                    
					maps[i][j]='*';
                    cout<<maps[i][j]<<" ";
                }

                
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

                
                else if(i>0 and i<(tam-4)/2 and j>(tam+2)/2 and j<tam){
                    // espinho
                    if((j==tam-7 and i>1) or (j==tam-3 and i>1) or (j==tam-5 and i<(tam+1)/3)){
                        maps[i][j]='#';
                        cout<<maps[i][j]<<" ";
                    }
                    //botao
                    else if(i==tam-13 and j==tam-2){
                        maps[i][j]='O';
                        cout<<maps[i][j]<<" ";
                    }
                    
                    else{
                        maps[i][j]=' ';
                        cout<<maps[i][j]<<" ";
                    }
                }

                
                else if(i>0 and i<(tam-4)/2 and j>0 and j<(tam-4)/2){
                    
                    
                    if(i==tam/5 and j==tam/5){
                    	portali=tam/5;
                    	portalj=tam/5;
                        maps[i][j]='>';
                        cout<<maps[i][j]<<" ";
                    }
					
                    
                    else{
                        maps[i][j]=' ';
                        cout<<maps[i][j]<<" ";
                    }

                }

                
                else if(i>tam-9 and i<tam and j>0 and j<(tam-4)/2){
                    
                    
                    if(i==tam-5 and j==tam-16){
                    	portali2=tam-5;
                    	portalj2=tam-16;
                        maps[i][j]='<';
                        cout<<maps[i][j]<<" ";
                    }
					
					//chave
					else if(i==tam-3 and j==tam-16 and chave==false){
						maps[i][j]='@';
                        cout<<maps[i][j]<<" ";
					}
                    
                    else{
                        maps[i][j]=' ';
                        cout<<maps[i][j]<<" ";
                    }

                }
                
                else{
                    maps[i][j]=' ';
                    cout<<maps[i][j]<<" ";
                }

            }

            cout<<"\n";
        }


}



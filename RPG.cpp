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



//MOVIMENTAÇÃO
void Player::Movimento(Maps& maps){
	
    cout<<"\t\t\t\t\t\t\tVIDAS: "<<vida<<" BOTAO: "<<maps.bot<<" CHAVE: "<<maps.chave<<" FECHADURA: "<<maps.porta<<endl;
    cout<<"\t\t\t\t\t\t\t>";
    cin>>ordem;

    switch(ordem){
        //andanto pra cima
        case 'W':
        case 'w':
        	switch(mapa.mapa[i-1][j]){
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
                	j=mapa.portal2-1;
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
        	switch(mapa.mapa[i][j+1]){
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
            break;
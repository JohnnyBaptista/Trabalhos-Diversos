#include "editor.c"

//====================================================================

Linha linha = NULL;
Texto fluxo = NULL;
Cursor pfluxo = NULL;

//====================================================================

void sair(char* nome_arquivo){ //Fecha a ncurses, salva o texto no arquivo.  
  endwin();
  texto_salvar(fluxo,nome_arquivo);
  texto_apagar(fluxo);
  printf("\nTexto salvo! :D\n");
}

//====================================================================

int main(int argc, char *argv[]){ //Pergunta se quer abrir ou criar arquivo.
  if(argc == 2) como_usar(); //Se a função for chamada com mais de um argumento, é mostrado informações sobre o programa.

  char nome_arquivo[200]; char palavra[16];
  
  menu(nome_arquivo);

  fluxo = texto_abrir(nome_arquivo, linha);
  pfluxo = fluxo->pro;

  initscr();
  keypad(stdscr,TRUE);
  erase();
  printw("%s",texto_parastring(fluxo,pfluxo));
  refresh();
 
  int ch;
 
  while(1){
    switch(ch = getch()){
   
      case KEY_BACKSPACE:
        texto_movercursor(fluxo,&pfluxo,-1);
        texto_deletarchar(&fluxo,&pfluxo);	
        break;

      case KEY_LEFT:
        texto_movercursor(fluxo,&pfluxo,-1);
        break;
   
      case KEY_RIGHT:
        texto_movercursor(fluxo,&pfluxo,1);
        break;
   
      case KEY_UP:
        texto_movercursor(fluxo,&pfluxo,-100);
        break;
   
      case KEY_DOWN:
        texto_movercursor(fluxo,&pfluxo,64);
        break;
   
      case KEY_HOME:
        texto_movercursor(fluxo,&pfluxo,-1000);
        break;
   
      case KEY_END:
        texto_movercursor(fluxo,&pfluxo,32);
        break;
   
      case KEY_DC:
        texto_deletarchar(&fluxo,&pfluxo);
        break;

      case KEY_F(2):
        erase();
        printw( "=================================================\n"
		            "Ins: Procura palavra \n"
	              "Enter: Salva e fecha \n"
		            "Esc: Salva e fecha \n"
		            "F2: Ajuda \n"
		            "\n"
	   	          "Nome autores: João Pedro da Silva Baptista\n"
		            "              Vinícius Vedovotto\n"            
		            "Trabalho de ED I - Professor Ronaldo\n"
		            "Versão v1.0\n"
		            "=================================================\n\n");
        getch();
        break;
   
      case KEY_IC:
        erase();
   	    printw ("Digite a palavra a ser procurada:\n");
   	    scanw("%19s", palavra);
   	    procurar(palavra,texto_parastring(fluxo,pfluxo));
   	    break;

      case KEY_BREAK:
        exit(EXIT_SUCCESS);
        break;
   	
      case '\n':
        //mostre o menu
        // while(pfluxo != NULL)
        //   texto_movercursor(fluxo,&pfluxo,1);
        sair(nome_arquivo);
        exit(EXIT_SUCCESS);
      break;

      case 27:
        sair(nome_arquivo);
        exit(EXIT_SUCCESS);
        break;
   
      default:
        if(ch < 256){
          texto_inserirchar(fluxo,pfluxo,ch,linha);
          beep();
        }
    
        else{
          printw("\a");
        }
    }
  
    erase();
    printw("%s",texto_parastring(fluxo,pfluxo));
    refresh();
    texto_limpar();
  }
  sair(nome_arquivo);
  exit(EXIT_SUCCESS);
} //main

//====================================================================

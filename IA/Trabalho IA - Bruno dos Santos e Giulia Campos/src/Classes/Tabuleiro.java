
package Classes;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.Timer;
import Interface.principal;

/**
 *
 * @author Giulia
 */
public class Tabuleiro {
    private int tabuleiro[][];    
    private int dim; //Dimensão   
    private principal interface_tabuleiro;  
    private Timer cronometro; 
    private ArrayList historico_movimentacoes = new ArrayList(); //Array que armazena o histórico dos 6 ultimos movimentos
    private Random rand = new Random();
    private final int ACIMA = 0, DIREITA = 1, ABAIXO = 2, ESQUERDA = 3;
    //Funções de avaliação: 0 - distância euclidiana, 1 - quantidade de quadrados nas posições erradas
    private final int EUCLIDIANA = 0, ERROPOSICAO = 1;
    private int qtdMovimentos = 0;
    private int qtdMovFeitos = 0; //Quantidade de movimentos realmente feitos para organizar o tabuleiro
            
    
    public Tabuleiro(int dim, principal manipula_interface) {
        this.dim = dim;
        this.interface_tabuleiro = manipula_interface;
        iniciaTabuleiro(); //Inicia o tabuleiro de forma correta
    }

    public int[][] getTabuleiro() {
        return tabuleiro;
    }

    public void setTabuleiro(int[][] tabuleiro) {
        this.tabuleiro = tabuleiro;
    }

    public int getDim() {
        return dim;
    }

    public void setDim(int dim) {
        this.dim = dim;
    }

    public void iniciaTabuleiro() { //Inicia o tabuleiro de forma correta
        tabuleiro = new int[getDim()][getDim()];
        for (int i = 0, cont = 0; i < getDim(); i++) {
            for (int j = 0; j < getDim(); j++) {
                tabuleiro[i][j] = ++cont;
            }
        }
    }

    private Coordenada posicaoN(int n, int[][] t) { //Retorna as coordenadas do número n no tabuleiro t
        Coordenada espaco = null;
        boolean continua = true;
        for (int i = 0; i < getDim(); i++) {
            if (!continua) {
                break;
            }
            for (int j = 0; j < getDim(); j++) {
                if (t[i][j] == n) {
                    espaco = new Coordenada(i, j);
                    continua = false;
                    break;
                }
            }
        }
        return espaco;
    }

    private int tentaMovimento(int ind, int t[][]) {    //Tenta movimentar o espaço de acordo com o índice passado no tabuleiro t
        Coordenada espaco = posicaoN(getDim() * getDim(), t);
        int nova_pos = ind;

        switch (ind) {
            case ACIMA:
                if (espaco.getLinha() - 1 < 0) {
                    nova_pos = tentaMovimento(ind + 1, t);
                }
                break;
            case DIREITA:
                if (espaco.getColuna() + 1 >= getDim()) {
                    nova_pos = tentaMovimento(ind + 1, t);
                }
                break;
            case ABAIXO:
                if (espaco.getLinha() + 1 >= getDim()) {
                    nova_pos = tentaMovimento(ind + 1, t);
                }
                break;
            case ESQUERDA:
                if (espaco.getColuna() - 1 < 0) {
                    nova_pos = tentaMovimento(0, t);
                }
                break;
        }

        return nova_pos;

    }

    private void moverPeca(int indice) {
        Coordenada espaco = posicaoN(9, tabuleiro);
        Coordenada nova_pos = new Coordenada(espaco.getLinha(), espaco.getColuna());
        int copia[][] = new int[getDim()][getDim()];
        int ind = tentaMovimento(indice, tabuleiro);

        switch (ind) {
            case ACIMA:
                nova_pos.setLinha(nova_pos.getLinha() - 1);
                break;
            case DIREITA:
                nova_pos.setColuna(nova_pos.getColuna() + 1);
                break;
            case ABAIXO:
                nova_pos.setLinha(nova_pos.getLinha() + 1);
                break;
            case ESQUERDA:
                nova_pos.setColuna(nova_pos.getColuna() - 1);
                break;
        }

        copia = copiaTabuleiro(tabuleiro);
        copia = trocaEspaco(espaco, nova_pos, copia);

        //Verifica se o movimento esta no histórico
        if (verificaHistorico(copia, historico_movimentacoes)) {
            moverPeca(geraNumeroAleatorio());
        } else {
            tabuleiro = copia;
            adicionaHistorico(tabuleiro);
            interface_tabuleiro.moverEspaco(espaco, nova_pos);
        }

    }

    public void embaralhar(int n) {
        ActionListener acao = new ACEmbaralhar(n);
        cronometro = new Timer(250, acao); //Realiza a tarefa de embaralhar a cada 250ms.
        cronometro.setRepeats(true);
        cronometro.start();
    }

    private boolean Solucao(int t[][]) {
        for (int i = 0, cont = 1; i < getDim(); i++) {
            for (int j = 0; j < getDim(); j++) {
                if (t[i][j] != cont) {
                    return false;
                }
                cont++;
            }
        }
        return true;
    }

    private void mostraCaminho(Map<No, No> caminho, No no_solucao, No no_raiz) { //mostra o caminho certo
        ActionListener acao = new ACMostraCaminho(caminho, no_solucao, no_raiz);
        cronometro = new Timer(350, acao); //Mostra uma posição do tabuleiro a cada 250 ms.
        interface_tabuleiro.exibeQtdMovimentosFeitos(qtdMovFeitos);
        
        cronometro.setRepeats(true);
        cronometro.start();
    }

    private int[][] trocaEspaco(Coordenada antiga, Coordenada nova, int t[][]) { //move o "espaço" de lugar
        int valor = t[nova.getLinha()][nova.getColuna()];
        t[nova.getLinha()][nova.getColuna()] = t[antiga.getLinha()][antiga.getColuna()];
        t[antiga.getLinha()][antiga.getColuna()] = valor;
        return t;
    }

    private int[][] copiaTabuleiro(int t[][]) {
        int copia[][] = new int[getDim()][getDim()];

        for (int i = 0; i < getDim(); i++) {
            for (int j = 0; j < getDim(); j++) {
                copia[i][j] = t[i][j];
            }
        }

        return copia;
    }

    private boolean verificaHistorico(int t[][], ArrayList h) {   //Verifica se o movimento esta no histórico
        if (h == null) {
            return false;
        }
        for (Iterator iterator = h.iterator(); iterator.hasNext();) {
            int th[][] = (int[][]) iterator.next();
            if (verificaIgual(th, t)) {
                return true;
            }
        }
        return false;
    }

    private void adicionaHistorico(int t[][]) { //Armazenando os ultimos 6 movimentos para não cair em looping
        if (historico_movimentacoes.size() == 6) {
            historico_movimentacoes = new ArrayList();
        }
        historico_movimentacoes.add(t);
    }

    private boolean verificaIgual(int t1[][], int t2[][]) {
        for (int i = 0; i < getDim(); i++) {
            for (int j = 0; j < getDim(); j++) {
                if (t1[i][j] != t2[i][j]) {
                    return false;
                }
            }
        }
        return true;

    }


    private int geraNumeroAleatorio() {
        int indice = rand.nextInt(200);
        indice = indice % 4;
        return indice;
    }


    private void encontraSucessores(No no, int op) { //encontra os movimentos que uma peça pode fazer
        Coordenada espaco = posicaoN(getDim() * getDim(), no.getEstado());

        for (int i = 0; i < 4; i++) {
            int ind = tentaMovimento(i, no.getEstado());
            if (ind >= i) {
                Coordenada nova_pos = new Coordenada(espaco.getLinha(), espaco.getColuna());
                i = ind;
                switch (ind) {
                    case ACIMA:
                        nova_pos.setLinha(nova_pos.getLinha() - 1);
                        break;
                    case DIREITA:
                        nova_pos.setColuna(nova_pos.getColuna() + 1);
                        break;
                    case ABAIXO:
                        nova_pos.setLinha(nova_pos.getLinha() + 1);
                        break;
                    case ESQUERDA:
                        nova_pos.setColuna(nova_pos.getColuna() - 1);
                        break;
                }

                int copia[][] = copiaTabuleiro(no.getEstado());
                copia = trocaEspaco(espaco, nova_pos, copia);
                No filho;
                if (op == EUCLIDIANA) {//Cria um nó com função avaliação baseada na distância euclidiana.
                    filho = new No(copia, calculaDistanciaEuclidiana(copia));
                } else {//Cria um nó com função avaliação baseada na quantidade de quadrados nas posições erradas.
                    filho = new No(copia, numeroPosErradas(copia));
                }
                no.adicionaFilho(filho);

            }
        }
    }

    private int possui(ArrayList<No> lista, No no) {
        int i = 0;
        for (Iterator iterator = lista.iterator(); iterator.hasNext();) {
            No no_atual = (No) iterator.next();
            if (verificaIgual(no_atual.getEstado(), no.getEstado())) {
                return i;
            }
            i++;
        }
        return -1;
    }

    private int calculaDistanciaEuclidiana(int t[][]) {
        int soma = 0;

        for (int i = 0, cont = 1; i < getDim(); i++) {
            for (int j = 0; j < getDim(); j++) {
                Coordenada pos = posicaoN(cont, t);
                soma += Math.pow((pos.getLinha() - i), 2) + Math.pow((pos.getColuna() - j), 2); //soma += (x1-x2)^2 + (y1-y2)^2.
                cont++;
            }
        }
        return soma;
    }

    private int numeroPosErradas(int t[][]) {
        int qtde = 0;
        for (int i = 0, cont = 1; i < getDim(); i++) {
            for (int j = 0; j < getDim(); j++) {
                if (t[i][j] != cont) {
                    qtde++;
                }
                cont++;
            }
        }
        return qtde;
    }

//******************************************************************************TÉCNICAS DE BUSCA**************************************************************************************
  
    public void buscaAleatoria() {
        ActionListener acao = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if (Solucao(tabuleiro)) {
                    cronometro.stop();
                    historico_movimentacoes = new ArrayList();
                    interface_tabuleiro.liberaBotoes();
                    interface_tabuleiro.exibeQtdMovimentos(qtdMovimentos);
                    qtdMovimentos = 0;
                    
                    return;
                }
                qtdMovimentos++;
                //System.out.println("Movimentos" + qtdMovimentos);
                moverPeca(geraNumeroAleatorio()); 
            }
        };
        //manipula_interface.exibeQtdMovimentos(qtdMovimentos);
        cronometro = new Timer(250, acao);
        cronometro.setRepeats(true);
        cronometro.start();
    }
    
    public void buscaHeuristica1() {
        ArrayList<No> fechados = new ArrayList<No>();
        ArrayList<No> abertos = new ArrayList<No>();

        boolean solucaoEncontrada = false;
        No no_atual;
        No no_raiz = new No(tabuleiro, calculaDistanciaEuclidiana(tabuleiro));
        Map<No, No> caminho = new HashMap<No, No>();

        abertos.add(no_raiz);

        while (!solucaoEncontrada && !abertos.isEmpty()) {
            Collections.sort(abertos);
            no_atual = abertos.get(0);
            qtdMovimentos++;
            if (!Solucao(no_atual.getEstado())) {
                //qtdMovimentos++;
                abertos.remove(0);                
                fechados.add(no_atual);
                encontraSucessores(no_atual, EUCLIDIANA);
                ArrayList<No> filhos = no_atual.getFilhos();
                for (Iterator iterator = filhos.iterator(); iterator.hasNext();) {
                    No filho = (No) iterator.next();
                    if (possui(fechados, filho) == -1) { //Se já não tiver sido visitado
                        filho.setCustocaminho(no_atual.getCustocaminho() + 1);
                        filho.setCustototal(filho.getCustocaminho() + filho.getFuncaoavaliacao());
                        int ind;
                        if ((ind = possui(abertos, filho)) == -1) {
                            abertos.add(filho);
                            caminho.put(filho, no_atual);
                        } else if (filho.getCustocaminho() < abertos.get(ind).getCustocaminho()) {
                            abertos.remove(ind);
                            abertos.add(filho);
                            caminho.remove(filho);
                            caminho.put(filho, no_atual);
                        }
                    }
                }
            } else {
                solucaoEncontrada = true;
                mostraCaminho(caminho, no_atual, no_raiz);
                interface_tabuleiro.exibeQtdMovimentos(--qtdMovimentos);
                qtdMovFeitos = 0;
                qtdMovimentos = 0;
            }
        }
    }

    public void buscaHeuristica2() {
        ArrayList<No> fechados = new ArrayList<No>();
        ArrayList<No> abertos = new ArrayList<No>();
        boolean solucaoEncontrada = false;
        No no_atual;

        No no_raiz = new No(tabuleiro, calculaDistanciaEuclidiana(tabuleiro));
        Map<No, No> caminho = new HashMap<No, No>();

        abertos.add(no_raiz);

        while (!solucaoEncontrada && !abertos.isEmpty()) {
            Collections.sort(abertos);
            no_atual = abertos.get(0);
            qtdMovimentos++;
             if (!Solucao(no_atual.getEstado())) {
                abertos.remove(0);                
                fechados.add(no_atual);
                encontraSucessores(no_atual, EUCLIDIANA);
                ArrayList<No> filhos = no_atual.getFilhos();

                for (Iterator iterator = filhos.iterator(); iterator.hasNext();) {
                    No filho = (No) iterator.next();
                    if (possui(fechados, filho) == -1) { 
                        filho.setCustocaminho(no_atual.getCustocaminho() + 1);
                        
                        encontraSucessores(filho, EUCLIDIANA);
                        ArrayList<No> netos = filho.getFilhos();
                        if (netos.isEmpty())
                            filho.setCustototal(filho.getCustocaminho() + filho.getFuncaoavaliacao());
                        
                        for (Iterator iterator_1 = netos.iterator(); iterator_1.hasNext();) {
                            No neto = (No) iterator_1.next();
                            neto.setCustocaminho(filho.getCustocaminho() + 1);
                            neto.setCustototal(neto.getCustocaminho() + neto.getFuncaoavaliacao());
                            if ((neto.getCustototal() < filho.getCustototal()) || (filho.getCustototal() == 0) )
                                filho.setCustototal(neto.getCustototal());
                        }
                        int ind;
                        if ((ind = possui(abertos, filho)) == -1) { 
                            abertos.add(filho);
                            caminho.put(filho, no_atual);
                        } else if (filho.getCustocaminho() < abertos.get(ind).getCustocaminho()) {
                            abertos.remove(ind);
                            abertos.add(filho);
                            caminho.remove(filho);
                            caminho.put(filho, no_atual);
                        }
                    }
                }
            } else {
                solucaoEncontrada = true;
                mostraCaminho(caminho, no_atual, no_raiz);
                interface_tabuleiro.exibeQtdMovimentos(--qtdMovimentos);
                qtdMovFeitos = 0;
                qtdMovimentos = 0;
            }
        }
    }

    public void buscaHeuristicaPessoal() {
        ArrayList<No> fechados = new ArrayList<No>();
        ArrayList<No> abertos = new ArrayList<No>();
        boolean solucaoEncontrada = false;
        No no_atual;
        No no_raiz = new No(tabuleiro, numeroPosErradas(tabuleiro));
        Map<No, No> caminho = new HashMap<No, No>();

        abertos.add(no_raiz);

        while (!solucaoEncontrada && !abertos.isEmpty()) {
            Collections.sort(abertos);
            no_atual = abertos.get(0);
            qtdMovimentos++;
            if (!Solucao(no_atual.getEstado())) {
                abertos.remove(0);                
                fechados.add(no_atual);
                //Encontra o nós filhos do nó atual.
                encontraSucessores(no_atual, ERROPOSICAO);
                ArrayList<No> filhos = no_atual.getFilhos();

                for (Iterator iterator = filhos.iterator(); iterator.hasNext();) {
                    No filho = (No) iterator.next();
                    if (possui(fechados, filho) == -1) {
                        filho.setCustocaminho(no_atual.getCustocaminho() + 1);
                        filho.setCustototal(filho.getCustocaminho() + filho.getFuncaoavaliacao());
                        int ind;
                        if ((ind = possui(abertos, filho)) == -1) {
                            abertos.add(filho);
                            caminho.put(filho, no_atual);
                        } else if (filho.getCustocaminho() < abertos.get(ind).getCustocaminho()) {
                            abertos.remove(ind);
                            abertos.add(filho);
                            caminho.remove(filho);
                            caminho.put(filho, no_atual);

                        }
                    }
                }
            } else {
                solucaoEncontrada = true;
                mostraCaminho(caminho, no_atual, no_raiz);
                interface_tabuleiro.exibeQtdMovimentos(--qtdMovimentos);
                qtdMovFeitos = 0;
                qtdMovimentos = 0;
            }
        }
    }

   //Embaralha o tabuleiro
    private class ACEmbaralhar implements ActionListener {
        private int n;
        private Random rand;

        public ACEmbaralhar(int n) {
            this.n = n;
            rand = new Random();
        }

        public void actionPerformed(ActionEvent e) {
            if (n == 0) {
                cronometro.stop();
                historico_movimentacoes = new ArrayList();
                interface_tabuleiro.liberaBotoes();

                return;
            }

            moverPeca(geraNumeroAleatorio()); //Move espaço aleatoriamente

            n--;
        }
    }
    
    //Mostra o caminho no tabuleiro
    private class ACMostraCaminho implements ActionListener {
        private LinkedList<No> caminho = new LinkedList<No>();
        private No no_atual;
        private No no_anterior;

        public ACMostraCaminho(Map<No, No> caminho, No solucao, No raiz) {
            populaCaminho(caminho, solucao);
            //manipula_interface.exibeQtdMovimentos(qtdMovFeitos);
            System.out.println(qtdMovFeitos);
            this.no_anterior = raiz;
        }

        public void populaCaminho(Map<No, No> c, No no) {
            while (c.containsKey(no)) {
                qtdMovFeitos++;
                caminho.push(no);
                no = c.get(no);
            }
            caminho.push(no);
            
        }

        public void actionPerformed(ActionEvent e) {
            if (caminho.isEmpty()) {
                cronometro.stop();
                interface_tabuleiro.liberaBotoes();
                return;
            }

            no_atual = caminho.pop();
            setTabuleiro(no_atual.getEstado());
            Coordenada antiga = posicaoN(getDim() * getDim(), no_anterior.getEstado());
            Coordenada nova = posicaoN(getDim() * getDim(), no_atual.getEstado());
            no_anterior = new No(no_atual.getEstado(), no_atual.getFuncaoavaliacao());
            interface_tabuleiro.moverEspaco(antiga, nova);
        }
    }
    
}

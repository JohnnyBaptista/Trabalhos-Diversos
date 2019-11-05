/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Classes;

/**
 *
 * @author Giulia
 */
public class Coordenada {
    private int linha;
    private int coluna;

    public Coordenada(int linha, int coluna) {
        this.linha = linha;
        this.coluna = coluna;
    }

    public Coordenada() {
    }
    
    
    public int getLinha() {
        return linha;
    }

    public void setLinha(int linha) {
        this.linha = linha;
    }

    public int getColuna() {
        return coluna;
    }

    public void setColuna(int coluna) {
        this.coluna = coluna;
    }
    
}

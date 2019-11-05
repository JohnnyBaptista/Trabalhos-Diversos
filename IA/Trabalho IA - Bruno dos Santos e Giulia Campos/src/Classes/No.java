/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Classes;

import java.util.ArrayList;
import java.util.Collections;

/**
 *
 * @author Giulia
 */
public class No implements Comparable<No>{
    private int[][] estado;
    private int funcaoavaliacao;    
    private int custototal = 0;
    private int custocaminho = 0;
    private int id;
    ArrayList<No> filhos = new ArrayList<No>();

    public No(int[][] estado, int funcaoavaliacao) {
        this.estado = estado;
        this.funcaoavaliacao = funcaoavaliacao;        
    }

    public int[][] getEstado() {
        return estado;
    }

    public void setEstado(int[][] estado) {
        this.estado = estado;
    }

    public int getFuncaoavaliacao() {
        return funcaoavaliacao;
    }

    public void setFuncaoavaliacao(int funcaoavaliacao) {
        this.funcaoavaliacao = funcaoavaliacao;
    }


    public ArrayList<No> getFilhos() {
        return filhos;
    }

    public void setFilhos(ArrayList<No> filhos) {
        this.filhos = filhos;
    }

    public void adicionaFilho(No filho) {
        filhos.add(filho);     
        Collections.sort(filhos);
    }
    
    public No removeFilho(){
        return filhos.remove(0);
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getCustototal() {
        return custototal;
    }

    public void setCustototal(int custototal) {
        this.custototal = custototal;
    }

    
    public int getCustocaminho() {
        return custocaminho;
    }

    public void setCustocaminho(int custocaminho) {
        this.custocaminho = custocaminho;
    }
           
    //Função de comparação pelo custo total
    @Override
    public int compareTo(No no) {
        if (no == null) {
            throw new NullPointerException();
        }
        if (no.getCustototal()< this.custototal) {  
            return 1;  
        } else if (no.getCustototal() > this.custototal){  
            return -1;  
        } else {  
            return 0;  
        } 
    }
    
}

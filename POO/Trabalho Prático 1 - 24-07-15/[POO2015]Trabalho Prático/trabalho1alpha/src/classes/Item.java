/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package classes;

import java.io.Serializable;

/**
 *
 * @author Mortzion
 */
public class Item implements Serializable{
    private static final long serialVersionUID = 1L;
    private int num;
    private Produto produto;
    private float quantidade;

    Item(int num, Produto produto, int quantidade) {
        this.num = num;
        if(produto instanceof ProdutoNacional)this.produto = new ProdutoNacional((ProdutoNacional) produto);
        if(produto instanceof ProdutoImportado)this.produto = new ProdutoImportado((ProdutoImportado) produto);
        this.quantidade = quantidade;
    }
   
    public float precoTotal(){
        return this.quantidade*this.produto.calcularPreco();
    }
            
    public void setNum(int num){
        this.num = num;
    }
    public void setPrdto(Produto prdto){
        this.produto.clone(prdto);
    }
    public void setQuantidade(float quantidade){
        this.quantidade = quantidade;
    }
    public int getNum(){
        return num;
    }
    public Produto getPrdto(){
        return produto;
    }
    public float getQuantidade(){
        return quantidade;
    }
}

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
public class Cartao extends TipoPagamento  implements Serializable{
    private String nome;
    private String numero;
    private static final long serialVersionUID = 5124350687600521680L;
    
    public Cartao(String nome, String numero, String tipoPagamento){
        super(tipoPagamento);
        this.nome = nome;
        this.numero = numero;
    }

    public String getNome() {
        return nome;
    }

    public String getNumero() {
        return numero;
    }

    @Override
    public void exibirDados() {
        
    }
    

    
    
}

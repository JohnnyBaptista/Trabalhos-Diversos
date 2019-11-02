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
public class Cheque extends TipoPagamento  implements Serializable{
    private String nomeEmissor;
    private String numeroCheque;
    private static final long serialVersionUID = -3889527857452576856L;
    
    public Cheque(String nomeEmissor, String numeroCheque, String tipoPagamento){
        super(tipoPagamento);
        this.nomeEmissor = nomeEmissor;
        this.numeroCheque = numeroCheque;
    }
    
    public void setNomeEmissor(String nomeEmissor){
        this.nomeEmissor = nomeEmissor;
    }
    
    public String getNomeEmissor(){
        return nomeEmissor;
    }
    
    public void setNumeroCheque(String numeroCheque){
        this.numeroCheque = numeroCheque;
    }
    
    public String getNumeroCheque(){
        return numeroCheque;
    }
    
    public void exibirDados(){
    
    }
    
}

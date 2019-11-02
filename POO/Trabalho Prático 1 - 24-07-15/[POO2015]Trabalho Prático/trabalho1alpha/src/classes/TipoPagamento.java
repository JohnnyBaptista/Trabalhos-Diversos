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
public abstract class TipoPagamento implements Serializable{
        private String tipoPagamento;
        private static final long serialVersionUID = 6346994977456047537L;
        
        public TipoPagamento(String tipoPagamento){
            this.tipoPagamento = tipoPagamento;
        }
        
        public abstract void exibirDados();
        
        
}

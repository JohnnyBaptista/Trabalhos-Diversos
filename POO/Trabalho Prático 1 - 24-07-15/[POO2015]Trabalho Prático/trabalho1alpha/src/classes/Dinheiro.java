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
public class Dinheiro extends TipoPagamento  implements Serializable{
    private static final long serialVersionUID = -9028649030545996949L;
    
    public Dinheiro(String tipoPagamento){
        super(tipoPagamento);
    }
    public void exibirDados(){
        //Usar o devido metodo para exibir os dados
        //saida no console ou na interface?
    }
 
    
}

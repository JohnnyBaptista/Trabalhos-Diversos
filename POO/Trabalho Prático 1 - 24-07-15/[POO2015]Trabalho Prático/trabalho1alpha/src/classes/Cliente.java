package classes;

import java.io.Serializable;
import javax.swing.JOptionPane;

public class Cliente implements Serializable{
    private static final long serialVersionUID = 1L;
    private String cpf;
    private String nome;
    

    public Cliente(String cpf, String nome){
        this.cpf = cpf;
        this.nome = nome;
    }

    public Cliente(){}
    
    public String getCpf(){
        return cpf;
    }
    
    public void setCpf(String cpf){
        this.cpf = cpf;
    }
    
    public String getNome(){
        return nome;
    }
    
    public void setNome(String nome){
        this.nome = nome;
    }
    
    public void exibir(){
        JOptionPane.showMessageDialog(null, this.nome+"  "+this.cpf);
    }
    
    public void clone(Cliente cliente){
        this.cpf = cliente.getCpf();
        this.nome = cliente.getNome();
    }
}

package classes;

import java.io.Serializable;
import java.util.Objects;

public abstract class Produto implements Serializable{
    private static final long serialVersionUID = 1L;
    private String codigo;
    private String descricao;
    private float valor;
   
    public Produto(){}
    
    public Produto(String codigo, String descricao, float valor){
        this.codigo = codigo;
        this.descricao = descricao;
        this.valor = valor;
    }
    
    public Produto(Produto produto){
        this.codigo = produto.getCodigo();
        this.descricao = produto.getDescricao();
        this.valor = produto.getValor();
    }
    
    public void setCodigo(String codigo){
        this.codigo = codigo;
    }
    
    public String getCodigo(){
        return codigo;
    }
    
    public void setDescricao(String descricao){
        this.descricao = descricao;
    }
    
    public String getDescricao(){
        return descricao;
    }
    
    public void setValor(float valor){
        this.valor = valor;
    }
    
    public float getValor(){
        return valor;
    }
    
    public abstract float calcularPreco();

   public void clone(Produto produto){
       this.codigo = produto.getCodigo();
       this.descricao = produto.getDescricao();
       this.valor = produto.getValor();
   }
    
    
}

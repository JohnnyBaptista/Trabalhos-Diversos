package classes;

import java.io.Serializable;

public class ProdutoNacional extends Produto implements Serializable{
    private static final long serialVersionUID = 1L;
    private float taxaImposto;

    public ProdutoNacional(String codigo, String descricao, float valor,float taxaImposto) {
        super(codigo, descricao, valor);
        this.taxaImposto = taxaImposto;
    }

    public ProdutoNacional(ProdutoNacional produto){
        super(produto);
        this.taxaImposto = produto.getTaxaImposto();
    }
    
    public ProdutoNacional(){}
    
    @Override
    public float calcularPreco(){
    return super.getValor()*(1 + taxaImposto);
    }
    
    public float getTaxaImposto(){
        return taxaImposto;
    }
    
    public void setTaxaImposto(float taxaImposto){
        this.taxaImposto = taxaImposto;
    }
    
    public void clone(ProdutoNacional produto){
        super.clone(produto);
        this.taxaImposto = produto.getTaxaImposto();
    }
}

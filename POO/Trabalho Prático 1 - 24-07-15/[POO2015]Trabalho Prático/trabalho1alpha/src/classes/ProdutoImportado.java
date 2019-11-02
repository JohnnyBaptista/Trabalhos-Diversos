package classes;

import java.io.Serializable;

public class ProdutoImportado extends Produto implements Serializable{
    private static final long serialVersionUID = 1L;
    private float taxaImposto;
    private float taxaImportacao;
    
    public ProdutoImportado(String codigo, String descricao, float valor, float taxaImposto, float taxaImportacao){
        super(codigo,descricao,valor);
        this.taxaImposto = taxaImposto;
        this.taxaImportacao = taxaImportacao;
    }

    public ProdutoImportado(ProdutoImportado produto){
        super(produto);
        this.taxaImposto = produto.getTaxaImposto();
        this.taxaImportacao = produto.getTaxaImportacao();
    }
    
    public ProdutoImportado(){}
    
    @Override
    public float calcularPreco(){
        return super.getValor()*(1 + taxaImposto + taxaImportacao);
    }
    
    public void setTaxaImposto(float taxaImposto){
        this.taxaImposto = taxaImposto;
    }
    
    public float getTaxaImposto(){
        return taxaImposto;
    }
    
    public void setTaxaImportacao(float taxaImportacao){
        this.taxaImportacao = taxaImportacao;
    }
    
    public float getTaxaImportacao(){
        return taxaImportacao;
    }
    
    public void clone(ProdutoImportado produto){
        super.clone(produto);
        this.taxaImportacao = produto.getTaxaImportacao();
        this.taxaImposto = produto.getTaxaImposto();
    }
}

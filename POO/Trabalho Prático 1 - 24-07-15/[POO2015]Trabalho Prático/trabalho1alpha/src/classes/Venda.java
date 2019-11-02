package classes;

import java.io.Serializable;
import java.util.Calendar;

public class Venda implements Serializable{
    private static final long serialVersionUID = 1L;
    private String numero;
    private Item[] itens;
    private TipoPagamento tipoPgto;
    private Cliente cliente = new Cliente();
    private Calendar data;
    private int contItens;

    public float totalGasto(){
        float gasto=0;
            for(int i=0;i<contItens;i++){
                gasto += itens[i].precoTotal();
            }
        return gasto;
    }
    
    public Venda(int maxItem){
        itens = new Item[maxItem];
        contItens = 0;
    }
    
    public void setNumero(String numero) {
        this.numero = numero;
    }

    public int getContItens(){
        return contItens;
    }

    public void setTipoPgto(TipoPagamento tipoPgto) {
        this.tipoPgto = tipoPgto;
    }

    public void setCliente(Cliente cliente) {
        this.cliente.clone(cliente);
    }

    public void setData(Calendar data) {
        this.data = data;
    }

    public String getNumero() {
        return numero;
    }

    public TipoPagamento getTipoPgto() {
        return tipoPgto;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public Calendar getData() {
        return data;
    }

    public void addItem(Produto produto,int quantidade){
        if(contItens< itens.length){
            
            itens[contItens] = new Item(contItens,produto,quantidade);
            
            contItens++;
        }
    }
    
    public Item getItem(int i){
        return itens[i];
    }
    
   
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controladores;

import arquivos.ArquivoVendas;
import classes.Cliente;
import classes.Venda;
import java.io.IOException;

/**
 *
 * @author Mortzion
 */
public class ControladorVendas {
    
    //Recebe como parâmetro uma instancia de uma venda e salva no arquivo de vendas
    public void cadastrarVenda(Venda novaVenda) throws IOException, ClassNotFoundException{
        Venda vendas[];
        ArquivoVendas arqVr = new ArquivoVendas();
        
        vendas = arqVr.leitura();
        arqVr.gravacao(vendas, novaVenda);
    }

    //Retorna o numero de vendas cadastradas no arquivo
    public int getNumVendas() throws IOException {
        ArquivoVendas arqVr = new ArquivoVendas();
        return arqVr.getNumElem();
    }
    
    //Retorna um array com todas as vendas cadastradas no cpf de um cliente
    public Venda [] vendasDeUmCliente(String cpf) throws IOException, ClassNotFoundException{
        ArquivoVendas v = new ArquivoVendas();
        Venda vendas[] = v.leitura();
        Cliente aux;
        int cont=0;
        Venda vendasEspecificas[] = new Venda[vendas.length];
        for(int i = 0;i<vendas.length;i++){
            aux =  vendas[i].getCliente();
            if(aux.getCpf().equals(cpf)) vendasEspecificas[cont++] = vendas[i];
        }
        
        return vendasEspecificas;
    }
    
    //Realiza uma busca no arquivo de vendas de acordo com o numero da venda
    public Venda buscaVendaNum(String NumVenda) throws IOException, ClassNotFoundException{
        ArquivoVendas arqVr = new ArquivoVendas();
        Venda[] vendas = arqVr.leitura();
        
        if(vendas == null)return null;
        else{
            for(int i=0;i<vendas.length;i++){
                if(NumVenda.equals(vendas[i].getNumero())){
                    return vendas[i];
                }
            }
            return null;
        }
    }
    
    //Retorna o array de vendas salvas no arquivo.
    //Retorna null caso não haja vendas cadastradas
    public Venda[] getVendas() throws IOException, ClassNotFoundException{
        ArquivoVendas arqVr = new ArquivoVendas();
        return arqVr.leitura();
    }
    
}

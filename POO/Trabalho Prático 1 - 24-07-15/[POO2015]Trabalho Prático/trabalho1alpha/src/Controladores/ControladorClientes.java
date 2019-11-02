
package Controladores;

import arquivos.ArquivoClientes;
import classes.Cliente;
import java.io.IOException;

public class ControladorClientes {
    
    public ControladorClientes(){}
    
    //Busca um cliente no arquivo de acordo com o cpf
    public Cliente buscarCliente(String cpf) throws IOException, ClassNotFoundException{
        Cliente [] c;
        c = this.lerClientes();
        
        for(int i=0;i<c.length;i++){
            if(c[i].getCpf().equals(cpf)){
                return c[i];
            }
        }
        
        return null;
    }
    
    //Recebe como parâmetro dados de um cliente para instanciar o objeto e salvar no arquivo
    public void cadastrarCliente(String nome, String cpf) throws IOException, ClassNotFoundException{       
        Cliente cliente = new Cliente(cpf, nome);
        Cliente clientes [];
        ArquivoClientes c1 = new ArquivoClientes();
        clientes = c1.leitura();
        c1.gravacao(clientes, cliente);
    }
    
    //Retorna o array de clientes salvo no arquivo, ou null caso não haja arquivo ou clientes
    public Cliente [] lerClientes() throws IOException, ClassNotFoundException{
        Cliente clientes [];
        ArquivoClientes c1 = new ArquivoClientes();
        clientes = c1.leitura();  
        return clientes;
    }

}

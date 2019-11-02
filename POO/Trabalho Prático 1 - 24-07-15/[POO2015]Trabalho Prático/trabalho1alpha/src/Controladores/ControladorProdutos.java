package Controladores;

import arquivos.ArquivoProdutos;
import classes.Produto;
import java.io.IOException;

public class ControladorProdutos {
    
    //Recebe como parâmetro uma instancia de um produto para salvar no arquivo de produtos
    public void cadastrarProduto(Produto novoProduto) throws IOException, ClassNotFoundException{
        Produto produtos[];
        ArquivoProdutos arqPr = new ArquivoProdutos();
        
        produtos = arqPr.leitura();
        arqPr.gravacao(produtos, novoProduto);
    }
    
    //Retorna o array de produtos salvo no arquivo, ou null caso não haja arquivo ou produtos cadastrados
    public Produto[] lerProdutos() throws IOException, ClassNotFoundException{
        Produto produtos[];
        ArquivoProdutos arqPr = new ArquivoProdutos();
        
        produtos = arqPr.leitura();
        return produtos;
    }
    
    //Busca um produto no arquivo de acordo com código vindo por parâmetro
    public Produto buscarProduto(String codigo) throws IOException, ClassNotFoundException{
        Produto p;
        ControladorProdutos control = new ControladorProdutos();
        Produto [] produtos = control.lerProdutos();
        if(produtos == null) return null;
        for(int i=0;i<produtos.length;i++){
            if(produtos[i].getCodigo().equals(codigo)) return produtos[i];
        }
        return null;
    }
    
    //Verifica se um produto com um dado código já esta cadastrado
    public boolean produtoJaCadastrado(String codigo) throws IOException, ClassNotFoundException{
        ControladorProdutos control = new ControladorProdutos();
        Produto [] produtos = control.lerProdutos();
        if(produtos == null) return false;
        for(int i=0;i<produtos.length;i++){
            if(produtos[i].getCodigo().equals(codigo)) return true;
        }       
        return false;
    }
}

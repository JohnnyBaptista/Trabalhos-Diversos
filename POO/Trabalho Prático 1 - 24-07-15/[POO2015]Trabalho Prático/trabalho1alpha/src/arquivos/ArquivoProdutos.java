/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package arquivos;

import classes.Cliente;
import classes.Produto;
import java.awt.HeadlessException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import javax.swing.JOptionPane;

/**
 *
 * @author Mortzion
 */
public class ArquivoProdutos {
        
    public void gravacao(Produto produtos[], Produto novoProduto){
        try{//gravação;
            
            File fileProdutos = new File("produtos.arq");
            
            if(fileProdutos.exists() == false){
                fileProdutos.createNewFile();
                FileOutputStream arq = new FileOutputStream("produtos.arq");
                ObjectOutputStream obj = new ObjectOutputStream(arq);
                
                obj.writeInt(1);
                obj.writeObject(novoProduto);
                
                JOptionPane.showMessageDialog(null, "Produto salvo com sucesso!");
            }else{
            
                FileOutputStream arq = new FileOutputStream("produtos.arq");
                ObjectOutputStream obj = new ObjectOutputStream(arq);

                obj.writeInt(produtos.length+1);
                for(int i=0;i<produtos.length;i++){
                    obj.writeObject(produtos[i]);
                }
                obj.writeObject(novoProduto);
                JOptionPane.showMessageDialog(null, "Produto salvo com sucesso!");
            }
        }//end try;
        catch(IOException | HeadlessException erro){
            JOptionPane.showMessageDialog(null, "Ocorreu um Erro Durante a Gravação do Arquivo");
        }//end catch;
    }
    
    public Produto[] leitura() throws IOException, ClassNotFoundException{
        int numProdutos;
        Produto produtos [] = null;
        
        try{//leitura do array;
            File fileProduto = new File("produtos.arq");
            
            if(fileProduto.exists() == false)return null;
            
            FileInputStream arq = new FileInputStream("produtos.arq");
            ObjectInputStream obj = new ObjectInputStream(arq);
          
            numProdutos = obj.readInt();
            produtos = new Produto[numProdutos];
            
            for(int i=0; i<numProdutos;i++){
                produtos[i] = (Produto) obj.readObject();
            }
        }
        catch(HeadlessException erro){
            JOptionPane.showMessageDialog(null, erro.getMessage());
        }
           
        return produtos;
    }

    
}

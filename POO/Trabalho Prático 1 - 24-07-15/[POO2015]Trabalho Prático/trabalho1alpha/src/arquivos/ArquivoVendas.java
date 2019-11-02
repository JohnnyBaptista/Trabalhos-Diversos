/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package arquivos;

import classes.Venda;
import java.awt.HeadlessException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import javax.swing.JOptionPane;

/**
 *
 * @author Mortzion
 */
public class ArquivoVendas {
    public void gravacao(Venda vendas[], Venda novaVenda){
        try{//gravação;
        
            File fileVendas = new File("vendas.arq");
            
            if(fileVendas.exists() == false){
                fileVendas.createNewFile();
                FileOutputStream arq = new FileOutputStream("vendas.arq");
                ObjectOutputStream obj = new ObjectOutputStream(arq); 
                
                obj.writeInt(1);
                obj.writeObject(novaVenda);
                JOptionPane.showMessageDialog(null, "Venda salvo com sucesso!");
            }else{
            
                FileOutputStream arq = new FileOutputStream("vendas.arq");
                ObjectOutputStream obj = new ObjectOutputStream(arq);

                obj.writeInt(vendas.length+1);
                for(int i=0;i<vendas.length;i++){
                    obj.writeObject(vendas[i]);
                }
                obj.writeObject(novaVenda);
                JOptionPane.showMessageDialog(null, "Venda salvo com sucesso!");
            }
        }//end try;
        catch(IOException | HeadlessException erro){
            JOptionPane.showMessageDialog(null, "Ocorreu um Erro Durante a Gravação do Arquivo");
        }//end catch;
    }
    
    public Venda[] leitura() throws IOException, ClassNotFoundException{
        int numVendas;
        Venda vendas [] = null;
        try{//leitura do array;
            File fileVendas = new File("vendas.arq");
            
            if(fileVendas.exists() == false)return null;
            
            FileInputStream arq = new FileInputStream("vendas.arq");
            ObjectInputStream obj = new ObjectInputStream(arq);
            numVendas = obj.readInt();
            vendas = new Venda[numVendas];
            for(int i=0; i<numVendas;i++){
                vendas[i] = (Venda) obj.readObject();
            }
            
        }
        catch(HeadlessException erro){
            JOptionPane.showMessageDialog(null, "Ocorreu um Erro Durante a Abertura do Arquivo");
        }
           
        return vendas;
    }
    
    public int getNumElem() throws FileNotFoundException, IOException{
        File fileVendas = new File("vendas.arq");
        
        if(fileVendas.exists() == false)return 0;
        else{
            FileInputStream arq = new FileInputStream("vendas.arq");
            ObjectInputStream obj = new ObjectInputStream(arq);
            
            return obj.readInt();
        }
       
    }
    
}

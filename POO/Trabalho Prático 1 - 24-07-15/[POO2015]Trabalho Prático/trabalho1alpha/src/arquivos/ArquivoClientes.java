package arquivos;

import classes.Cliente;
import java.awt.HeadlessException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import javax.swing.JOptionPane;

public class ArquivoClientes {
    
    public void gravacao(Cliente clientes[], Cliente cliente){
        try{//gravação;
            File fileClientes = new File("clientes.arq");
            
            if(fileClientes.exists() == false){
                
                fileClientes.createNewFile();
                FileOutputStream arq = new FileOutputStream("clientes.arq");
                ObjectOutputStream obj = new ObjectOutputStream(arq);
                
                obj.writeInt(1);
                obj.writeObject(cliente);
                
                JOptionPane.showMessageDialog(null, "Cliente salvo com sucesso!");
                
            }else{
            
            int numcontas = clientes.length;
            FileOutputStream arq = new FileOutputStream("clientes.arq");
            ObjectOutputStream obj = new ObjectOutputStream(arq);
            numcontas++;
            
            obj.writeInt(numcontas);
            for(int i=0;i<numcontas-1;i++){
                obj.writeObject(clientes[i]);
            }
            obj.writeObject(cliente);
            JOptionPane.showMessageDialog(null, "Cliente salvo com sucesso!");
            }
        }//end try;
        catch(IOException | HeadlessException erro){
            JOptionPane.showMessageDialog(null, "Ocorreu um Erro Durante a Gravação do Arquivo");
        }//end catch;
    }
    
    public Cliente[] leitura() throws IOException, ClassNotFoundException{
        int numcontas=0;
        Cliente clientes [] = null;
        try{//leitura do array;
            File fileClientes = new File("clientes.arq");
            
            if(fileClientes.exists() == false){
                return null;
            }else{
            
                FileInputStream arq = new FileInputStream("clientes.arq");
                ObjectInputStream obj = new ObjectInputStream(arq);
                numcontas = obj.readInt();
                clientes = new Cliente[numcontas];
                for(int i=0; i<numcontas;i++){
                    clientes[i] = (Cliente) obj.readObject();
                }
            }
        }
        catch(HeadlessException erro){
            JOptionPane.showMessageDialog(null, "Ocorreu um Erro Durante a Abertura do Arquivo");
        }
           
        return clientes;
    }

    
}

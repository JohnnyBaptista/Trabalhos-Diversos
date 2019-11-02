package Arquivos;

import Classes.Configuracao;
import Classes.Controlador;
import Classes.Emprestimo;
import Classes.Livro;
import Classes.usuarios.Usuario;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

/**
 * Métodos de leitura e escrita de arquivos.
 * @author Matheus Prachedes, Eymar Lima, Carlos Henrique.
 */
public class IOArquivos {
    /**
     * Função responsável pela abertura e leitura do arquivo de configuração.
     * Busca um arquivo com um nome pré-definido, caso não encontre, cria um novo arquivo com as configurações padrões.
     * @return Retorna um objeto Configuracao salvo no arquivo.
     */
    public Configuracao lerConfig(){
        try {
            File arquivoConfig = new File("config.arq");

            Configuracao configAtual;
            FileInputStream ios;
            
            if(arquivoConfig.exists() == false){
                configAtual = new Configuracao();
                this.escreverConfig(configAtual);
                return configAtual;
            }
            
            ios = new FileInputStream(arquivoConfig);
            ObjectInputStream ois = new ObjectInputStream(ios);
            
            configAtual = (Configuracao) ois.readObject();
            return configAtual;
            
        } catch (FileNotFoundException ex) {
            return null;
        } catch (IOException | ClassNotFoundException ex) {
            return null;
        }
            
            
    }
    /**
     * Função responsável por salvar no arquivo as novas configurações.
     * @param novaConfig Nova configuração que será salva no arquivo.
     */
    public void escreverConfig(Configuracao novaConfig){
        try {
            File configFile = new File("config.arq");
            
            if(configFile.exists() == false)configFile.createNewFile();
            
            FileOutputStream fos = new FileOutputStream("config.arq");
            ObjectOutputStream ous = new ObjectOutputStream(fos);
            
            ous.writeObject(novaConfig);
        } catch (FileNotFoundException ex) {
            JOptionPane.showMessageDialog(null,"Erro ao salvar o arquivo de configurações");
        } catch (IOException ex) {
            JOptionPane.showMessageDialog(null,"Erro ao salvar o arquivo de configurações");
        }
        
    }
    /**
     * Função responsável pela leitura de um arquivo que contém objetos do tipo Usuário.
     * @return Retorna um ArrayList com todos os usuários salvos no arquivo. Caso o arquivo não possua nenhum usuário, retorna null.
     */
    public ArrayList<Usuario> lerUsuarios(){
        try {
            Controlador control = new Controlador();
            FileInputStream fis = new FileInputStream(control.getConfigUsuarios());
            ObjectInputStream ois = new ObjectInputStream(fis);
            
            int contUsuarios = ois.readInt();
            ArrayList<Usuario> usuarios = new ArrayList<>();
            
            for(int i = 0;i<contUsuarios;i++){
                usuarios.add((Usuario) ois.readObject());
            }
            return usuarios;
            
        } catch (IOException ex) {
            return null;
        } catch (ClassNotFoundException ex) {
            return null;
        }
    }
    
    /**
     * Função responsável por adcionar um novo usuário no arquivo.
     * Caso o arquivo não exista, ele é criado com o nome pré-estabelecido nas configurações.
     * @param usuario Usuário que será adicionado no arquivo.
     */
    public void escreverUsuario(Usuario usuario){
        
        try {
            Controlador control = new Controlador();
            File arquivoUsuario = new File(control.getConfigUsuarios());
            ArrayList<Usuario> usuarios;
            usuarios = lerUsuarios();
            
            int contUsuarios;
            
            if(arquivoUsuario.exists() == false) arquivoUsuario.createNewFile();
             
            FileOutputStream fos = new FileOutputStream(arquivoUsuario);
            ObjectOutputStream ous = new ObjectOutputStream(fos);
            
            
            
            if(usuarios != null){
                usuarios.add(usuario);
                contUsuarios = usuarios.size();
                ous.writeInt(contUsuarios);
                for(int i = 0;i<contUsuarios;i++){
                    ous.writeObject(usuarios.get(i));
                }
            }else{
                ous.writeInt(1);
                ous.writeObject(usuario);
            }
            ous.close();
            fos.close();
            JOptionPane.showMessageDialog(null, "Usuário Cadastrado Com Sucesso!!");
            
        } catch (FileNotFoundException ex) {
            JOptionPane.showMessageDialog(null, "Erro ao abrir o arquivo de usuarios");
        } catch (IOException ex) {
            Logger.getLogger(IOArquivos.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }
    
    /**
     * Função responsável pela leitura de um arquivo que contém objetos do tipo Empréstimo.
     * @return Retorna um ArrayList com todos os empréstimos salvos no arquivo. Caso o arquivo não possua nenhum empréstimo, retorna null.
     */
    public ArrayList<Emprestimo> lerEmprestimos(){
        
        try {
            Controlador control = new Controlador();
            File arquivoEmprestimos = new File(control.getConfigEmprestimos());
        
            if(arquivoEmprestimos.exists() == false)return null;
        
            ArrayList<Emprestimo> emprestimos = new ArrayList<>();
            int contEmprestimos;
        
            FileInputStream fis = new FileInputStream(arquivoEmprestimos);
            ObjectInputStream ois = new ObjectInputStream(fis);
            
            contEmprestimos = ois.readInt();
            
            for(int i = 0; i<contEmprestimos; i++){
                emprestimos.add( (Emprestimo) ois.readObject());
            }
            
            ois.close();
            fis.close();
            return emprestimos;
            
        } catch (FileNotFoundException ex) {
            return null;
        } catch (IOException | ClassNotFoundException ex) {
            return null;
        }
        
        
    }
    
    /**
     * Função responsável por adcionar um novo empréstimo no arquivo.
     * Caso o arquivo não exista, ele é criado com o nome pré-estabelecido nas configurações.
     * @param novoEmprestimo Empréstimo que será adicionado arquivo.
     */
    public void escreverEmprestimo(Emprestimo novoEmprestimo){
        
        try {
            ArrayList<Emprestimo> emprestimos;
            Controlador control = new Controlador();
            File arquivoEmprestimos = new File(control.getConfigEmprestimos());
            int contEmprestimos;
            
            emprestimos = lerEmprestimos();
            
            if(arquivoEmprestimos.exists() == false) arquivoEmprestimos.createNewFile();
               
            FileOutputStream fos = new FileOutputStream(arquivoEmprestimos);
            ObjectOutputStream ous = new ObjectOutputStream(fos);
            
            if(emprestimos == null){
                ous.writeInt(1);
                ous.writeObject(novoEmprestimo);
            }else{
                emprestimos.add(novoEmprestimo);
                contEmprestimos = emprestimos.size();
                
                ous.writeInt(contEmprestimos);
                for(int i = 0; i<contEmprestimos;i++){
                    ous.writeObject( emprestimos.get(i) );
                }
            }
                ous.close();
                fos.close();
                JOptionPane.showMessageDialog(null, "Empréstimo Salvo Com Sucesso!!");
      
        } catch (FileNotFoundException ex) {
            Logger.getLogger(IOArquivos.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(IOArquivos.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    /**
     * Função responsável por substituir todos os empréstimos do arquivo, pelos novos empréstimos recebidos através de um ArrayList.
     * @param a ArrayList com os novos empréstimos.
     */
    public void escreverEmprestimoCheio(ArrayList<Emprestimo> a){
        try {
            Controlador control = new Controlador();
            File arquivoEmprestimos = new File(control.getConfigEmprestimos());
            FileOutputStream fos;
            fos = new FileOutputStream(arquivoEmprestimos);
            ObjectOutputStream ous = new ObjectOutputStream(fos);
        
            ous.writeInt(a.size());
            for(int i=0;i<a.size();i++){
                ous.writeObject(a.get(i));
            }
            ous.close();
            fos.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(IOArquivos.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(IOArquivos.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }
    
     /**
     * Função responsável por substituir todos os livros do arquivo, pelos novos livros recebidos através de um ArrayList.
     * @param a ArrayList com os novos livros.
     */
    public void escreverLivroCheio(ArrayList<Livro> a){
        Controlador control = new Controlador();
        
        
        try {
            File arquivoLivros = new File(control.getConfigLivros());
            FileOutputStream fos;
            fos = new FileOutputStream(arquivoLivros);
            ObjectOutputStream ous = new ObjectOutputStream(fos);
        
            ous.writeInt(a.size());
            for(int i=0;i<a.size();i++){
                ous.writeObject(a.get(i));
            }
            ous.close();
            fos.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(IOArquivos.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(IOArquivos.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }
    
    /**
     * Função responsável pela leitura de um arquivo que contém objetos do tipo Livro.
     * @return Retorna um ArrayList com todos os livros salvos no arquivo. Caso o arquivo não possua nenhum livro, retorna null.
     */
    public ArrayList<Livro> lerLivros(){
        try {
            Controlador control = new Controlador();
            ArrayList<Livro> livros = new ArrayList<>();
            File arquivoLivros = new File(control.getConfigLivros());
            int contLivros;
            
            if(arquivoLivros.exists() == false)return null;
        
            FileInputStream fis;
            fis = new FileInputStream(arquivoLivros);
            ObjectInputStream ois = new ObjectInputStream(fis);
            
            contLivros = ois.readInt();
            for(int i = 0;i<contLivros;i++){
                livros.add((Livro) ois.readObject());
            }
            
            return livros;
        } catch (FileNotFoundException ex) {
            Logger.getLogger(IOArquivos.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(IOArquivos.class.getName()).log(Level.SEVERE, null, ex);
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(IOArquivos.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }
    
    /**
     * Função responsável por adcionar um novo livro no arquivo.
     * Caso o arquivo não exista, ele é criado com o nome pré-estabelecido nas configurações.
     * @param novoLivro Livro que será adicionado arquivo.
     */
    public void escreverLivro(Livro novoLivro){
          
        try {
            ArrayList<Livro> livros;
            Controlador control = new Controlador();
            File arquivoLivros = new File(control.getConfigLivros());
            int contLivros;
            
            livros = lerLivros();
            
            if(arquivoLivros.exists() == false) arquivoLivros.createNewFile();
               
            FileOutputStream fos = new FileOutputStream(arquivoLivros);
            ObjectOutputStream ous = new ObjectOutputStream(fos);
            
            if(livros == null){
                ous.writeInt(1);
                ous.writeObject(novoLivro);
            }else{
                livros.add(novoLivro);
                contLivros = livros.size();
                
                ous.writeInt(contLivros);
                for(int i = 0; i<contLivros;i++){
                    ous.writeObject( livros.get(i) );
                }
            }
                ous.close();
                fos.close();
                JOptionPane.showMessageDialog(null, "Livro Salvo Com Sucesso!!");
      
        } catch (FileNotFoundException ex) {
            Logger.getLogger(IOArquivos.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(IOArquivos.class.getName()).log(Level.SEVERE, null, ex);
        }   
    }
    
    /**
     * Função responsável por retornar a quantidade de usuários salvos no arquivo.
     * @return Quantidade de usuários salvos no arquivo.
     */
    public int getNumUsuarios(){
        
        try {
            Controlador control = new Controlador();
            File arquivoUsuarios = new File(control.getConfigUsuarios());
        
            if(arquivoUsuarios.exists() == false)return 0;
        
            FileInputStream fis = new FileInputStream(arquivoUsuarios);
            ObjectInputStream ous = new ObjectInputStream(fis);
            
            return ous.readInt();
            
        } catch (FileNotFoundException ex) {
            Logger.getLogger(IOArquivos.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(IOArquivos.class.getName()).log(Level.SEVERE, null, ex);
        }
       
        return 0;
    }
    
    /**
     * Função responsável por retornar a quantidade de livros salvos no arquivo.
     * @return Quantidade de livros salvos no arquivo.
     */
    public int getNumLivros(){
        
        try {
            Controlador control = new Controlador();
            File arquivoLivros = new File(control.getConfigLivros());
        
            if(arquivoLivros.exists() == false)return 0;
        
            FileInputStream fis = new FileInputStream(arquivoLivros);
            ObjectInputStream ous = new ObjectInputStream(fis);
            
            return ous.readInt();
            
        } catch (FileNotFoundException ex) {
            Logger.getLogger(IOArquivos.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(IOArquivos.class.getName()).log(Level.SEVERE, null, ex);
        }
       
        return 0;
    }
    
    /**
     * Função responsável por retornar a quantidade de empréstimos salvos no arquivo.
     * @return Quantidade de empréstimos salvos no arquivo.
     */
    public int getNumEmprestimos(){
        
        try {
            Controlador control = new Controlador();
            File arquivoEmprestimos = new File(control.getConfigEmprestimos());
        
            if(arquivoEmprestimos.exists() == false)return 0;
        
            FileInputStream fis = new FileInputStream(arquivoEmprestimos);
            ObjectInputStream ous = new ObjectInputStream(fis);
            
            return ous.readInt();
            
        } catch (FileNotFoundException ex) {
            Logger.getLogger(IOArquivos.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(IOArquivos.class.getName()).log(Level.SEVERE, null, ex);
        }
       
        return 0;
    }
}

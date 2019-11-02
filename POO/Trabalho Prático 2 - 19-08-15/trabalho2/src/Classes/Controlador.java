
package Classes;

import Arquivos.IOArquivos;
import Classes.usuarios.Aluno;
import Classes.usuarios.Professor;
import Classes.usuarios.Usuario;
import Interface.Devolucao;
import java.util.ArrayList;
import javax.swing.JOptionPane;


/**
 * Classe usada para fazer intermédio entre o núcleo do sistema e as interfaces
 * do programa
 * 
 * @author Matheus Prachedes, Eymar Lima, Carlos Henrique.
 */
public class Controlador {
    public static Biblioteca biblio = new Biblioteca();
    
    /**
     * 
     * @return Retorna a quantidade de dias que um aluno pode ficar com um livro.
     */
    public int quantDiasAlunos(){
        return biblio.getConfig().getDiasAlunos();
    }
    
    /**
     * 
     * @return Retorna a quantidade de dias que um professor pode ficar com
     *         um livro.
     */
    public int quantDiasProfessores(){
        return biblio.getConfig().getDiasProfessor();
    }
    
    /**
     * 
     * @return Retorna a variável do tipo Configuração utilizada atualmente 
     *          pelo sistema
     */
    public Configuracao getConfig(){
        return biblio.getConfig();
    }
    
    /**
     * Atualiza a configuração atual do sistema tanto no arquivo quanto na
     * memória.
     * 
     * @param config Nova configuração que será utilizada pelo sistema.
     */
    public void setConfig(Configuracao config){
        biblio.setConfig(config);
        IOArquivos arq = new IOArquivos();
        arq.escreverConfig(config);
        JOptionPane.showMessageDialog(null, "Configurações Salvas Com Sucesso!!");
    }
    
    /**
     * 
     * @return Retorna o nome do arquivo usado para armazenar os alunos 
     *         cadastrados.
     */
    public String getConfigUsuarios(){
        return biblio.getConfig().getArquivoUsuarios();
    }
    
    /**
     * 
     * @return Retorna o nome do arquivo usado para salvar os empréstimos 
     *          cadastrados
     */
    public String getConfigEmprestimos(){
        return biblio.getConfig().getArquivoEmprestimos();
    }

    /**
     * 
     * @return Retorna o nome do arquivo usado para salvar os livros cadastrados 
     */
    public String getConfigLivros() {
        return biblio.getConfig().getArquivoLivros();
    }
    
    /**
     * 
     * @return Retorna a quantiade de dias que um aluno pode ficar com um livro.
     */
    public int getNumUsuarios(){
        IOArquivos arq = new IOArquivos();
        return arq.getNumUsuarios();
    }
    
    /**
     * 
     * @return Retorna um ArrayList contendo os usuarios cadastrados no arquivo.
     *          Caso não exista usuários cadastrados retorna null.
     */
    public ArrayList<Usuario> getUsuarios(){
        IOArquivos arq = new IOArquivos();
        return arq.lerUsuarios();
    }
    
    /**
     *  Adiciona um novo usuário no arquivo de usuários  
     * 
     * @param novoUsuario Novo usuário que será salvo no arquivo. 
     */
    public void addUsuario(Usuario novoUsuario){
        IOArquivos arq = new IOArquivos();
        arq.escreverUsuario(novoUsuario);
    }
    
    /**
     * 
     * @return Retorna o número de livros cadastrados no sistema.
     */
    public int getNumLivros(){
        IOArquivos arq = new IOArquivos();
        return arq.getNumLivros();
    }
    
    /**
     * 
     * @return Retorna o número de empréstimos cadastrados no sistema.
     */
    public int getNumEmprestimos(){
        IOArquivos arq = new IOArquivos();
        return arq.getNumEmprestimos();
    }

    /**
     * 
     * @param novoLivro Novo livro que será salvo no arquivo.
     */
    public void addLivro(Livro novoLivro) {
        IOArquivos arq = new IOArquivos();
        arq.escreverLivro(novoLivro);
    }
    
    /**
     * 
     * @param novoEmprestimo Novo empréstimo que será salvo no arquivo.
     */
    public void addEmprestimo(Emprestimo novoEmprestimo) {
        IOArquivos arq = new IOArquivos();
        arq.escreverEmprestimo(novoEmprestimo);
    }
    
    /**
     * 
     * @return Retorna um ArrayList contendo os livros salvo no arquivo, caso não haja
     *          livros cadastrados retorna null.
     */
    public ArrayList<Livro> getLivros(){
        IOArquivos arq = new IOArquivos();
        return arq.lerLivros();
    }
    
    /**
     * Realiza uma busca nos usuarios cadastrados utilizando o codigo de usuario
     * e retorna o Usuario encontrado, retorna null caso não encontre nenhum
     * usuario.
     * 
     * @param codigo Codigo de usuario usado para fazer a busca
     * @return Retorna o usuario encontrado, caso não encontre retorna null.
     */
    public Usuario procurarUsuario(String codigo){
        Usuario user;
        IOArquivos arq = new IOArquivos();
        ArrayList a =  arq.lerUsuarios();
        if(a==null) return null;
        for(int i=0;i<a.size();i++){
            user = (Usuario) a.get(i);
            if(user.getCodUsuario().equals(codigo)) return user;
        }    
        return null;
    }
    
    /**
     * Realiza uma busca nos livros cadastrados utilizando o codigo de livro
     * e retorna o Livro encontrado, retorna null caso não encontre nenhum
     * livro.
     * 
     * @param cod Codigo utilizado para fazer a busca.
     * @return Retorna o livro encontrado, caso não encontre retorna null.
     */
    public Livro procurarLivro(String cod){
        IOArquivos arq = new IOArquivos();
        ArrayList a = arq.lerLivros();
        Livro livro;
        if(a == null) return null;
        for(int i=0;i<a.size();i++){
            livro = (Livro) a.get(i);
            if(livro.getCodLivro().equals(cod)) return livro;
        }
        return null;
    }
    
    /**
     * Realiza uma busca no ArrayList de itens do parâmetro, e retorna um
     * boleano de acordo com o sucesso ou não da busca.
     * 
     * @param item ArrayList onde será feito a busca.
     * @param livro Livro que será buscado no ArrayList.
     * @return Retorna true se encontrar, false caso contrario.
     */
    public boolean verificaItemValido(ArrayList<Item> item, Livro livro){
        Item ii;
        Livro ll;
        for(int i=0;i<item.size();i++){
            ii = item.get(i);
            ll = ii.getLivro();
            if(livro.getCodLivro().equals(ll.getCodLivro())) return true;
        }
        return false;
    }
    
    
    /**
     * Realiza uma busca no ArrayList de livros cadastrados salvo arquivo
     * de acordo com o codigo do livro vindo como parâmetro. Marca todos os
     * livros encontrados como emprestado e salva o ArrayList alterado no 
     * arquivo de livros.
     * 
     * @param cod Codigo de livro usado para fazer a busca.
     */
    public void setTrueLivro(String cod){
        IOArquivos arq = new IOArquivos();
        ArrayList<Livro> livros = arq.lerLivros();
        Livro l;
        for(int i=0;i<livros.size();i++){
            l = livros.get(i);
            if(l.getCodLivro().equals(cod)) l.setEmprestado(true);
        }
        arq.escreverLivroCheio(livros);
    }
    
    /**
     * Realiza uma busca no ArrayList de livros cadastrados salvo arquivo
     * de acordo com o codigo do livro vindo como parâmetro. Marca todos os
     * livros encontrados como não emprestado e salva o ArrayList alterado no 
     * arquivo de livros.
     * 
     * @param cod Codigo de livro usado para fazer a busca.
     */
    public void setFalseLivro(String cod){
        IOArquivos arq = new IOArquivos();
        ArrayList<Livro> livros = arq.lerLivros();
        Livro l;
        for(int i=0;i<livros.size();i++){
            l = livros.get(i);
            if(l.getCodLivro().equals(cod)) l.setEmprestado(false);
        }
        
        arq.escreverLivroCheio(livros);
    }
    
    /**
     * Faz uma busca no ArrayList de emprestimos salvo no arquivo e retorna
     * todos os itens não devolvidos de um usuario ou null caso não exista
     * livros não devolvidos do usuario..
     * 
     * @param codUs Codigo de usuario usado para fazer a busca.
     * @return Retorna um ArrayList com todos os itens não devolvidos de um 
     *          usuario, retorna null se o ArrayList estiver vazio.
     */
    public ArrayList<Item> getItensDeUmUsuario(String codUs){
        ArrayList<Item> itens = new ArrayList<Item>();
        IOArquivos arq = new IOArquivos();
        ArrayList<Emprestimo> emps = arq.lerEmprestimos();
        if(emps == null) return null;
        
        Emprestimo emp;
        ArrayList<Item> itemTemp;
        Item it;
        for(int i=0;i<emps.size();i++){
            emp = emps.get(i);
            if(emp.getCodUsuario().equals(codUs)){
                itemTemp = emp.getItens();
                for(int j=0;j<itemTemp.size();j++){
                    it = itemTemp.get(j);
                    if(it.isDevolvido() == false){
                        itens.add(it);
                    }
                }
            }
        }
        
        if(itens.isEmpty() == true) return null;
        return itens;
    }
    
    /**
     * Faz uma busca no ArrayList de emprestimos salvo no arquivo de acordo com 
     * o codigo de emprestimo. Marca o livro que possui o codigo vindo pelo 
     * parâmetro como devolvido e salva o ArrayList de emprestimo alterado no
     * arquivo.
     * 
     * @param codEmprestimo Codigo de empresitmo usado para fazer a busca
     * @param codLivro Codigo do livro que será devolvido.
     */
    public void devolve1Item(String codEmprestimo, String codLivro){
        IOArquivos arq = new IOArquivos();
        ArrayList<Emprestimo> emps = arq.lerEmprestimos();
        
        ArrayList<Item> itensTemp;
        Emprestimo empTemp;
        Item itemTemp;
        
        for(int i=0;i<emps.size();i++){
            empTemp = emps.get(i);
            if(empTemp.getCodEmprestimo().equals(codEmprestimo)){
                empTemp.devolverItem(codLivro);
                this.setFalseLivro(codLivro);
                arq.escreverEmprestimoCheio(emps);
            }
        }
    }
    
    /**
     * Recebe um ArrayList contendo codigos de emprestimos e livros, e utiliza
     * essa informação para devolver os mesmos.
     * 
     * @param codigos ArrayList onde cada elemento possui duas Strings,
     *                a primeira String é referente ao codigo de emprestimo,
     *                e a segunda String é referente ao codigo de livro.
     * 
     * @see #devolve1Item(java.lang.String, java.lang.String) 
     */
    public void devolverItens(ArrayList<String[]> codigos){
        String[] s;
        for(int i=0;i<codigos.size();i++){
            s = codigos.get(i);
            this.devolve1Item(s[0],s[1]);
        }
        JOptionPane.showMessageDialog(null, "Livros Devolvidos Com Sucesso");
    }
    
    /**
     * Faz uma busca no ArrayList de livros salvos no arquivo e retorna um 
     * ArrayList contendo todos os livros disponiveis para emprestimos.
     * 
     * @return Retorna um ArrayList contendo todos os livros Disponiveis. 
     */
    public ArrayList<Livro> getLivrosDisponiveis(){
        ArrayList<Livro> livrosDisponiveis = new ArrayList<>();
        ArrayList<Livro> todosLivros;
        IOArquivos arq = new IOArquivos();
        Livro livroAtual;
        todosLivros = arq.lerLivros();
        
        if(todosLivros == null)return null;
        
        for(int i = 0;i<todosLivros.size();i++){
            livroAtual = todosLivros.get(i);
            if(livroAtual.isEmprestado() == false)livrosDisponiveis.add(livroAtual);
        }
        
        return livrosDisponiveis;
    }
    
    /**
     * 
     * @return Retorna um ArrayList contendo os emprestimos salvo no arquivo,
     *          retorna null caso não exista emprestimos cadastrados.
     */
    public ArrayList<Emprestimo> getEmprestimos(){
        IOArquivos arq = new IOArquivos();
        return arq.lerEmprestimos();
    }
    
    /**
     * Faz uma busca no ArrrayList de emprestimos salvo no arquivo e retorna
     * um ArrayList contendo todos os livros atrasados.
     * 
     * @return Retorna um ArrayList com livros atrasados.
     */
    public ArrayList<Livro> getLivrosAtrasados(){
        ArrayList<Livro> livrosAtrasados = new ArrayList<>();
        ArrayList<Emprestimo> emprestimos = getEmprestimos();
        Emprestimo emprestimoAtual;
        
        if(emprestimos == null)return null;
                
        for(int i = 0; i < emprestimos.size();i++){
            emprestimoAtual = emprestimos.get(i);
            livrosAtrasados.addAll( emprestimoAtual.getLivrosAtrasados());
        }
        return livrosAtrasados;
    }
    
    /**
     * Faz uma busca no ArrayList de emprestimos salvo no arquivo e retorna
     * um ArrayList contendo todos os livros emprestados.
     * 
     * @return Retorna um ArrayList com livros emprestados.
     */
    public ArrayList<Livro> getLivrosEmprestados(){
        IOArquivos arq = new IOArquivos();
        ArrayList<Livro> livros =  arq.lerLivros();
        ArrayList<Livro> livrosEmprestados = new ArrayList<Livro>();
        if(livros == null) return null;
        
        Livro livro;
        for(int i=0; i<livros.size();i++){
            livro = livros.get(i);
            if(livro.isEmprestado() == true){
                    livrosEmprestados.add(livro);
            }
        }
        return livrosEmprestados;
    }
    
    /**
     * Faz uma busca no ArrayList de emprestimos salvo no arquivo e retorna um
     * ArrayList contendos todos os itens ja emprestados por um usuario.
     * 
     * @param codUsuario Codigo do usuario que será usado na busca.
     * 
     * @return Retorna um ArrayList contendos os livros ja emprestados pelo usuario. 
     */
    public ArrayList<Item> getTodosOsLivrosJaEmprestados(String codUsuario){
        ArrayList<Item> devolver = new ArrayList<Item>();
        IOArquivos arq = new IOArquivos();
        ArrayList<Emprestimo> emps = arq.lerEmprestimos();
        if(emps == null) return null;
        Emprestimo emp;
        
        for(int i=0;i<emps.size();i++){
            emp = emps.get(i);
            if(emp.getCodUsuario().equals(codUsuario)){
                devolver.addAll(emp.getItens());
            }
        }
        
        if(devolver.isEmpty()==true) return null;
        return devolver;
    }
    
    /**
     * Faz uma busca no ArrayList de emprestimos salvo no arquivo, e retorna 
     * um Array de int com duas posições, a primeira com o numero de livros
     * emprestados pelo usuario, e a segunda com o numero de livros atrasados
     * do usuario.
     * 
     * @param codUsuario Codigo de usuario utilizado para fazer a busca.
     * 
     * @return Retora um Array de int com o numero de livros emprestados e 
     *          o numero de livros atrasados.
     */
    public int[] getNumLivrosAtrEmpr(String codUsuario){
        ArrayList<Emprestimo> emprestimos = this.getEmprestimos();
        int[] LivrosEmprAtr = new int[2];;
        Emprestimo emprestimoAtual;
        
        LivrosEmprAtr[0] = 0;
        LivrosEmprAtr[1] = 0;
        
        if(emprestimos == null)return LivrosEmprAtr;
        
        for(int i = 0; i<emprestimos.size();i++){
            emprestimoAtual = emprestimos.get(i);
            if(codUsuario.equals(emprestimoAtual.getCodUsuario())){
                LivrosEmprAtr[0] += emprestimoAtual.getNumLivrosEmprestados();
                LivrosEmprAtr[1] += emprestimoAtual.getNumLivrosAtrasados();
            }
        }
        return LivrosEmprAtr;
    }
    
    /**
     * Faz uma busca no ArrayList de emprestimos salvo no arquivo de acordo
     * com o codigo de livro vindo como parâmetro, retorna true caso o livro
     * esteja atrasado, e false caso contrario.
     * 
     * @param codLivro Codigo de livro utilizado pra fazer a busca.
     * 
     * @return Retorna true caso o livro esteja atrasado, false caso contrario. 
     */
    public boolean isLivroAtrasado(String codLivro){
        ArrayList<Emprestimo> emprestimos = getEmprestimos();
        if(emprestimos == null)return false;
        Emprestimo emprestimoAtual;
        
        for(int i = emprestimos.size()-1; i>=0;i--){
            emprestimoAtual = emprestimos.get(i);
            
            if(emprestimoAtual.isLivroAtrasado(codLivro) == true)return true;
            
        }
        return false;
    }
    
    /**
     * Faz uma busca no ArrayList de usuarios cadastrados e retorna um ArrayList
     * de usuarios atrasados onde cada elemento do ArrayList possui 4 Strings,
     * a primeira com o codigo de usuario, a segunda com o nome do usuario,
     * a terceira com o tipo de usuario e a quarta com o numero de livros
     * atrasados do usuario.
     * 
     * @return Retorna um ArrayList com informações dos usuarios com atrasos.
     */
    public ArrayList<String[]> getUsuariosAtrasos(){
        String[] linha = new String[4];
        ArrayList<Usuario> usuarios = getUsuarios();
        ArrayList<String[]> usuariosAtrasos = new ArrayList<>();
        int[] LivrosEmprAtr; 
        Usuario usuarioAtual;
        
        if(usuarios == null)return null;
        
        for(int i = 0;i<usuarios.size();i++){
            usuarioAtual = usuarios.get(i);
            
            LivrosEmprAtr = this.getNumLivrosAtrEmpr( usuarioAtual.getCodUsuario());
            
            if(LivrosEmprAtr[1] != 0){
                linha[0] = usuarioAtual.getCodUsuario();
                linha[1] = usuarioAtual.getNome();
                
                if(usuarioAtual instanceof Aluno)linha[2] = "Aluno";
                if(usuarioAtual instanceof Professor)linha[2] = "Professor";
                
                linha[3] = String.valueOf(LivrosEmprAtr[1]);
                
                usuariosAtrasos.add(linha);
            }
        }
        return usuariosAtrasos;
    }
}

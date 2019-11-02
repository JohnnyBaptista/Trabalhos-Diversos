package Classes;
import Classes.usuarios.Usuario;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Calendar;
/**
 * Classe de empréstimo da biblioteca.
 * @author Eymar Lima, Matheus Prachedes, Carlos Henrique.
 */
public class Emprestimo implements Serializable{
    /**
     * Código de referência do empréstimo.
     */
    private String codEmprestimo;
    /**
     * Código de referência do usuário que está fazendo o empréstimo.
     */
    private String codUsuario;
    /**
     * ArrayList com todos os itens que pertencem ao empréstimo.
     */
    private ArrayList<Item> itens;
    /**
     * Váriavel utilizada pela interface Serializable.
     */
    private static final long serialVersionUID = 1L;
    /**
     * @return Código de referência do usuário que está fazendo o empréstimo.
     */
    public String getCodUsuario() {
        return codUsuario;
    }
    /**
     * Realiza uma busca no array de itens, de acordo com o código do livro recebido como parâmetro, e realiza a devolução do item.
     * @param codLivro Código do livro a ser devolvido.
     */
    public void devolverItem(String codLivro){
        Item temp;
        for(int i=0;i<itens.size();i++){
            temp = itens.get(i);
            if(temp.getLivro().getCodLivro().equals(codLivro)){
                temp.setDevolvido(true);
                return;
            }
        }
    }
    /**
     * Construtor do empréstimo.
     * @param codEmprestimo Código de referência do empréstimo.
     * @param codUsuario Código de referência do usuário que está fazendo o empréstimo. 
     */
    public Emprestimo(String codEmprestimo, String codUsuario){
        this.codEmprestimo = codEmprestimo;
        this.codUsuario = codUsuario;
        this.itens = new ArrayList<>();
    }
    /**
     * @return Código de referência do empréstimo.
     */
    public String getCodEmprestimo() {
        return codEmprestimo;
    }
    /**
     * @return ArrayList com os itens do empréstimo.
     */
    public ArrayList<Item> getItens() {
        return itens;
    }
    /**
     * @param itens Novo ArrayList de itens. 
     */
    public void setItens(ArrayList<Item> itens) {
        this.itens = itens;
    }
    /**
     * Recebe como parâmetro um novo item, e o adiciona no ArrayList de itens.
     * @param item Novo item que será adicionado no ArrayList.
     */
    public void addItem(Item item){
        itens.add(item);
    }
    /**
     * Realiza uma busca pelo ArrayList de itens local, e retorna em um ArrayList auxiliar, contento apenas os livros que possuírem atraso.
     * @return ArrayList contendo todos os livros atrasados.
     */
    public ArrayList<Livro> getLivrosAtrasados(){
        ArrayList<Livro> livrosAtrasados = new ArrayList<>();
        int contItens = itens.size();
        Item itemAtual;
        
        for(int i = 0;i<contItens;i++){
            itemAtual = itens.get(i);
            
            if(itemAtual.isAtrasado() == true)livrosAtrasados.add( itemAtual.getLivro() );
        }
        return livrosAtrasados;
    }
    /**
     * Faz uma busca pelo ArrayList de itens local, e retorna a quantidade de livros que ainda estão esmprestados pelo usuário.
     * @return Quantidade de livros que ainda estão esmprestados pelo usuário, no empréstimo atual.
     */
    public int getNumLivrosEmprestados(){
        int contLivrosEmprestados = 0;
        for(int i = 0; i<itens.size();i++){
            if(itens.get(i).isDevolvido() == false)contLivrosEmprestados++;
        }
        return contLivrosEmprestados;
    }
    /**
     * Faz uma busca pelo ArrayList de itens local, e retorna a quantidade de livros que ainda estão atrasados.
     * @return Quantidade de livros atrasados.
     */
    public int getNumLivrosAtrasados(){
        int contLivrosAtrasados = 0;
        for(int i = 0; i<itens.size();i++){
            if(itens.get(i).isAtrasado())contLivrosAtrasados++;
        }
        return contLivrosAtrasados;
    }
    /**
     * Faz uma busca pelo ArrayList de itens local, utilizando o código do livro recebido como parâmetro, e verifica se o livro está atrasado.
     * @param codLivro Código do livro a ser procurado e verificado.
     * @return Retorna true caso o livro esteja atrasado, e false caso ele esteja em dia.
     */
    public boolean isLivroAtrasado(String codLivro){
        Item itemAtual;
        
        for(int i = 0;i<itens.size();i++){
            itemAtual = itens.get(i);
            
            if(itemAtual.getLivro().getCodLivro().equals(codLivro)){
                if(itemAtual.isAtrasado() == true)return true;
                return false;
            }
        }
        return false;
    }
}

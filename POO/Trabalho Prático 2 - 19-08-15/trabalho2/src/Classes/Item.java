package Classes;
import java.io.Serializable;
import java.util.Calendar;
/**
 * Classe de itens, utilizada pela classe emprestimo.
 * @author Eymar Lima, Matheus Prachedes, Carlos Henrique
 */
public class Item implements Serializable{
    /**
     * Livro associado ao Item.
     */
    private Livro livro;
    /**
     * Boolean responsável por indicar se o livro foi ou não devolvido.
     */
    private boolean devolvido;
    /**
     * Código de referência do empréstimo ao qual o item pertence.    
    */
    private String codEmprestimo;
    /**
     * Data em que o empréstimo foi realizado.
     */
    private Calendar dataEmprestimo;
    /**
     * Data em que o item deverá ser devolvido.
     */
    private Calendar dataDevolucao;
    /**
     * Váriavel utilizada pela interface Serializable.
     */
    private static final long serialVersionUID = 1L;
    /**
     * Construtor da Classe Item.
     * @param livro Livro associado ao Item.
     * @param emprestimo Data em que o empréstimo foi realizado.
     * @param devolucao Data em que o item deverá ser devolvido.
     * @param codEmprestimo Código de referência do empréstimo ao qual o item pertence.
     */
    public Item(Livro livro, Calendar emprestimo, Calendar devolucao, String codEmprestimo){
        this.livro = livro;
        this.dataDevolucao = devolucao;
        this.dataEmprestimo = emprestimo;
        this.codEmprestimo = codEmprestimo;
        this.devolvido = false;
    }
    /**
     * @return Data em que o item deverá ser devolvido.
     */
    public Calendar getDataDevolucao(){
        return dataDevolucao;
    }
    /**
     * @param dataDevolucao Nova data de devolução do item.
     */
    public void setDataDevolucao(Calendar dataDevolucao){
        this.dataDevolucao = dataDevolucao;
    } 
    /**
     * @return Livro associado ao Item.
     */
    public Livro getLivro() {
        return livro;
    }
    /**
     * @return Data em que o item deverá ser devolvido.
     */
    public Calendar getDataEmprestimo() {
        return dataEmprestimo;
    }
    /**
     * @return Boolean responsável por indicar se o livro foi ou não devolvido.
     */
    public boolean isDevolvido() {
        return devolvido;
    }
    /**
     * @param devolvido Novo estado de devolução do item.
     */
    public void setDevolvido(boolean devolvido) {
        this.devolvido = devolvido;
    }
    /**
     * @return Código de referência do empréstimo ao qual o item pertence.
     */
    public String getCodEmprestimo() {
        return codEmprestimo;
    }
    /**
     * @param codEmprestimo Novo código de referência do empréstimo ao qual o item pertence.
     */
    public void setCodEmprestimo(String codEmprestimo) {
        this.codEmprestimo = codEmprestimo;
    }
    /**
     * @return Boolena que indica se o livro está atrasado ou não. 
     */
    public boolean isAtrasado(){
        Calendar dataAtual = Calendar.getInstance();
        if(devolvido == false && dataAtual.after(dataDevolucao))return true;
        return false;
    }
}
